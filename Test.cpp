#include <cstring>
#include <memory>
#include <utility>

namespace Testing
{

    class Test
    {
        public:
            // Default constructor
            Test() = default;

            // Parametrized constructor
            Test(std::size_t len, const char* data)
                : m_size(len)
                , m_buffer(new char[len]())
            {
                // Should validate the input here.
                // It is the only time you get outside input.
                // Potentially you could throw here I choose
                // not too (because I can see it as a valid input)
                // Your use case may be different.
                if (data) {
                    strncpy(m_buffer.get(), data, m_size);
                }
            }

            // Copy constructor
            Test(const Test& other)
                : m_size(other.m_size)
                , m_buffer(new char[m_size]())
            {
                strncpy(m_buffer.get(), other.m_buffer.get(), m_size);
            }     

            // Copy Assignment operator
            Test& operator=(Test other)
            {
                swap(other);
                return *this;
            }

            // Move constructor
            Test(Test&& other) noexcept
            {
                swap(other);
            }

            // Move assignment operator
            Test& operator=(Test&& other) noexcept
            {
                swap(other);
                return *this;
            }

            void swap(Test& rhs) noexcept
            {
                using std::swap;
                swap(m_size,    rhs.m_size);
                swap(m_buffer,  rhs.m_buffer);
            }
        private:
            std::size_t m_size = 0;    
            std::unique_ptr<char[]> m_buffer = nullptr;
    };

    void swap(Test& lhs, Test& rhs) noexcept
    {
        lhs.swap(rhs);
    }
}
