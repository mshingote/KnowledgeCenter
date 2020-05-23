#include <iostream>
#include <cstring>

using namespace std;

class Test {
public:
    //Simple contructor
    Test() {
        cptr = nullptr;
        size = 0;
    }

    //Copy constructor
    Test(const Test& obj) {
        //Use existing assignment operator
        *this = obj;
    }

    //Assignment operator
    Test& operator=(const Test& obj) {
        if(this != &obj) {
            Test *temp = new Test;
            temp->size = obj.size;

            //It is assumed that size > len(cptr)
            temp->cptr = new char[temp->size];

            strncpy(temp->cptr, obj.cptr, temp->size);
            *this = std::move(*temp);
        }
        return *this;
    }

    //Move constructor
    Test(Test&& old) noexcept {
        //Use existing move assignment operator code
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

    //Resets obj
    void reset(Test& obj) {
        if(obj.cptr) {
            delete []obj.cptr;
            obj.cptr = nullptr;
        }
        obj.size = 0;
    }

    //Destructor
    virtual ~Test() {
        if(cptr != nullptr) {
            delete []cptr;
            cptr = nullptr;
        }
        size = 0;
    }
private:
    char *cptr;
    size_t size;
};
