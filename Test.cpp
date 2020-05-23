#include <cstring>
#include <memory>
#include<utility>

class Test {
public:
    //Default constructor
    Test() = default;

    //Copy constructor
    Test(const Test& obj) {
        //Using existing assignment operator
        *this = obj;
    }

    //Parametarized constructor
    Test(size_t len, char* data) {
        size = len;
        cptr = std::make_shared<char[]>(new char[size]);
        strncpy(cptr.get(), data, size);
    }

    //Move constructor
    Test(Test&& old) noexcept {
        //Using existing move assignment operator code
        *this = std::move(old);
    }

    //Assignment operator
    Test& operator=(const Test& obj) {
        if(this != &obj) {
            Test temp;
            temp.size = obj.size;
            temp.cptr = std::make_shared<char[]>(*obj.cptr);
            *this = std::move(temp);
        }
        return *this;
    }

    //Move assignment operator
    Test& operator=(Test&& old) noexcept {
        if(this != &old) {
            size = std::exchange(old.size, 0);
            cptr = std::exchange(old.cptr, nullptr);
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
};
