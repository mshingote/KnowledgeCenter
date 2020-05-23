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
            temp.cptr = make_shared<char>(*obj.cptr);
            *this = std::move(temp);
        }
        return *this;
    }

    //Move constructor
    Test(Test&& old) noexcept {
        //Using existing move assignment operator code
        size = std::exchange(old.size, 0);
        cptr = std::exchange(old.cptr, nullptr);
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
    void swap(Test& old) noexcept{
        std::swap(cptr, old.cptr);
        std::swap(size, old.size);
    }

    //Destructor
    ~Test() {
        reset(*this);
    }
private:
    shared_ptr<char> cptr = nullptr;
    int size = 0;
    
    //Resets obj
    static void reset(Test& obj) noexcept {
        obj.size = 0;
    }
};
