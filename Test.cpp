#include <cstring>
#include <memory>

using namespace std;

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
    Test(size_t len, char* info) {
        size = len;
        cptr = make_shared<char>(new char[size]);
        strncpy(cptr.get(), info, size);
    }

    //Move constructor
    Test(Test&& old) noexcept {
        //Using existing move assignment operator code
        size = std::exchange(old.size, 0);
        cptr = std::exchange(old.cptr, nullptr);
    }

    //Assignment operator
    Test& operator=(const Test& obj) {
        if(this != &obj) {
            Test temp;
            temp.size = obj.size;
            temp.cptr = make_shared<char>(*obj.cptr);
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
    shared_ptr<char> cptr = nullptr;
    int size = 0;    
};
