#include <iostream>
using namespace std;

class MyArray
{
    int* buff;
    int size;
public:
    MyArray() {
        buff = nullptr;
        size = 0;
    }
    MyArray(int s) :size(s) {
        buff = new int[size];
        for (int i = 0; i < size; i++)buff[i] = 0;
    }
    ~MyArray() {
        if (buff)delete[] buff;
    }
    int& operator[](int index) {
        return buff[index];
    }

};


int main()
{
    MyArray arr(10);
    arr[4] = 222;
    arr[4]++;
    std::cout << "arr[4] = " << arr[4] << std::endl;
    std::cout << "Hello World!\n";
}
