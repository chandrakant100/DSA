#include<iostream>
#include <climits>

template<typename T>

class StackArrayNolimit
{
    private:
        T *data;
        int nextindex;
        int capacity;
    public:
        StackArrayNolimit()
        {
            data = new T [5];
            capacity  = 5;
            nextindex = 0;
        }
        int size(){return nextindex;}
        bool isEmpty(){return nextindex == 0;}
        void push(int val)
        {
            if (nextindex == capacity)
            {
                T *newData = new T[capacity*2];
                for (int i{0}; i<capacity; i++)
                    newData[i] = data[i];
                delete [] data;
                data = newData;

                capacity *= 2;
            }
            data[nextindex] = val;
            nextindex ++;
        }
        int pop()
        {
            if (isEmpty())
            {
                std::cout<<"Stack is Empty !!"<<std::endl;
                return 0;
            }
            nextindex--;
            return data[nextindex];
        }
        int top()
        {
            if (isEmpty())
            {
                std::cout<<"Stack is Empty !!"<<std::endl;
                return 0;
            }
            return data[nextindex-1];
        }

};