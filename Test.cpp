#include <cstring>
#include <memory>
#include <utility>

class Test {
public:
    //Default constructor
    Test() = default;

    //Copy constructor
    Test(const Test& other) : m_size(other.m_size), m_buffer(new char[m_size]()) {
        strncpy(m_buffer.get(), other.m_buffer.get(), m_size);
    } 

    //Parametarized constructor
    Test(std::size_t len, const char* data) : m_size(len), m_buffer(new char[len]()) {
        strncpy(m_buffer.get(), data, m_size);
    }

    //Move constructor
    Test(Test&& other) noexcept {
        Test temp(other);
        swap(*this, temp);
    }

    //Assignment operator
    Test& operator=(Test& other) {
        if(this != &other) {
            Test test(other);
            swap(*this, test);
        }
        return *this;
    }

    //Move assignment operator
    Test& operator=(Test&& other) noexcept {
        if(this != &other) {
            Test temp(other);
            swap(*this, temp);
        }
        return *this;
    }

private:
    std::size_t m_size;
    std::unique_ptr<char[]> m_buffer;

    static void swap(Test& first, Test& second) noexcept{
        using std::swap;
        swap(first.m_size, second.m_size);
        swap(first.m_buffer, second.m_buffer);
    }
};
