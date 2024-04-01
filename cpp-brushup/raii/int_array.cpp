#include <iostream>

class IntArray
{
    size_t m_size;
    int *m_arr;

public:
    IntArray(size_t size) : m_size(size), m_arr(new int[size])
    {
        std::cout << "Array Constructor";
    }
    ~IntArray()
    {
        delete[] m_arr;
        std::cout << "Array Destructor";
    }
    void print() const
    {
        for (size_t i = 0; i < m_size; i++)
        {
            std::cout << m_arr[i] << "\n";
        }
    }
    const int &operator[](size_t size) const
    {
        return m_arr[size];
    }

    int &operator[](size_t size)
    {
        return m_arr[size];
    }
};

int main(int argc, char *argv[])
{
    IntArray intArr(10);
    intArr[5] = 10;
    std::cout << "\n"
              << intArr[5] << "\n";
    intArr.print();
    return 0;
}