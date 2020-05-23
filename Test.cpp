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

    //Assignment operator
    Test& operator=(const Test& obj) {
        if(this != &obj) {
            Test temp;
            temp.size = obj.size;
            temp.cptr = obj.cptr;
            *this = std::move(temp);
        }
        return *this;
    }

    //Move constructor
    Test(Test&& old) noexcept {
        //Using existing move assignment operator code
        *this = std::move(old);
    }

    //Move assignment operator
    Test& operator=(Test&& old) noexcept {
        if(this != &old) {
            this->swap(old);
            this->reset(old);
        }
        return *this;
    }

    //Swaps obj with this
    void swap(Test& old) {
        std::swap(cptr, old.cptr);
        std::swap(size, old.size);
    }

    //Destructor
    ~Test() {
        reset(*this);
    }
private:
    shared_ptr<char> cptr = nullptr;
    size_t size = 0;
    
    //Resets obj
    static void reset(Test& obj) {
        obj.size = 0;
    }
};
