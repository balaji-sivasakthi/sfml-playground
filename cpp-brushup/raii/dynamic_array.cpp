#include <iostream>
template <typename T>
class DynamicArray
{
    size_t m_size;
    T *m_arr;

public:
    DynamicArray(size_t size) : m_size(size), m_arr(new T[size])
    {
        std::cout << "Array Constructor";
    }
    ~DynamicArray()
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
    const T &operator[](size_t size) const
    {
        return m_arr[size];
    }

    T &operator[](size_t size)
    {
        return m_arr[size];
    }
};

int main(int argc, char *argv[])
{
    DynamicArray<int> intArr(10);
    DynamicArray<float> floatArr(10);
    intArr[5] = 10;
    floatArr[5] = 10.4;
    intArr.print();
    floatArr.print();
    return 0;
}