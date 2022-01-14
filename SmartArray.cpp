// SmartArray.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
using namespace std;

class SmartArray
{
    int* elem;
    int size;
    public:
    SmartArray()
    {
        size = 0;
    }
    SmartArray(int s)
    {
        if (s < 1) {
            std::cout << "number of elementes 'ill not be below 1";
            s = 1;
        }
        elem = new int[s];
        for (int i = 0; i < s; i++)elem[i] = 0;
        size = s;
    }
    SmartArray(SmartArray& source)
    {
        size = source.getSize();
        elem = new int[size];
        for (int i = 0; i < size; i++)elem[i] = source.elem[i];
    }
    ~SmartArray()
    {
        if (elem)delete[] elem;
        std::cout << "this object was destructed success!" << std::endl;
    }
    int& operator[](int index)
    {
        return elem[index];
    }
    friend ostream& operator<<(ostream& os, SmartArray& arr){
        for (int i = 0; i < arr.getSize(); i++){
            os << arr[i];
        }
        return os;
    }
    SmartArray& operator=(SmartArray& source) {
        if (elem)
            delete[] elem;
        size = source.getSize();
        elem = new int[size];
        for (int i = 0; i < size; i++)
            elem[i] = source.elem[i];
        return *this;
    }
    /*
    void Set(int index,int m)
    {
        if (index < 0)
        {
            std::cout << "Error! Index is below zero";
        }
        else if (index < size)
            elem[index] = m;
        else std::cout << "Error! Index is upper then size of array";
    }
    int Get(int index)
    {
        if (index < 0)
        {
            std::cout << "Error! Index is below zero";
            return index;
        }
        else if (index < size)
            return elem[index];
        else
        {
            std::cout << "Error! Index is upper then size of array";
            return index;
        }
    }
    */
    void push(int a) {
        if (size > 0)
        {
            int* tmp = new int[size + 1];
            for (int i = 0; i < size; i++)
                tmp[i] = elem[i];
            tmp[size] = a;
            ++size;
            delete[] elem;
            elem = tmp;
            
        }
    }
    SmartArray& operator+(SmartArray& inArr) {
        int newSize = this->size + inArr.getSize();
        
        int* tmpBuff = new int[newSize];

        for (int i = 0; i < size; ++i) 
            tmpBuff[i] = elem[i];    

        for (int i = 0; i < inArr.getSize(); ++i) 
            tmpBuff[i + size] = inArr[i];            
        
        delete[] elem;
        elem = tmpBuff;        
        size = newSize;
        return *this;
    }

    int getSize()
    {
        return size;
    }
};

int main()
{
    SmartArray smr(10);
    for (int i = 0; i < smr.getSize(); ++i)
        smr[i] = i;
    SmartArray smr2(10);
    for (int i = 0; i < smr.getSize(); ++i)
        smr2[i] = i;

    std::cout << smr;
    std::cout << std::endl;
    std::cout << smr2;
    std::cout << std::endl;

    smr = smr2 + smr;
    std::cout << "smr2 + smr: ";
    std::cout << smr;
    
}
    

