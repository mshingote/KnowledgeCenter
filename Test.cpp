#include <cstring>
#include <memory>
#include <utility>

class Test {
public:
    //Default constructor
    Test() = default;

    //Copy constructor
    Test(const Test& other) : size(other.size), cptr(std::make_shared<char[]>(other.cptr)) {}

    //Parametarized constructor
    Test(size_t len, char* data) {
        size = len;
        cptr = std::make_shared<char[]>(new char[size]);
        strncpy(cptr.get(), data, size);
    }

    //Move constructor
    Test(Test&& old) noexcept {
        //Using existing move assignment operator code
        Test temp(old);
        swap(*this, temp);
    }

    //Assignment operator
    Test& operator=(const Test other) {
        if(this != &other) {
            //Use existing move assignment
            *this = std::move(other);
        }
        return *this;
    }

    //Move assignment operator
    Test& operator=(Test&& old) noexcept {
        if(this != &old) {
            Test temp(old);
            swap(*this, temp);
        }
        return *this;
    }

    //Destructor
    ~Test() {
        size = 0;
        cptr = nullptr;
    }
private:
    std::shared_ptr<char[]> cptr = nullptr;
    size_t size = 0;    

    static void swap(Test& first, Test& second) noexcept{
        using std::swap;
        swap(first.size, second.size);
        swap(first.cptr, second.cptr);
    }
};
