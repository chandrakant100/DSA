#include<iostream>
#include <climits>

template <typename T>

class StackArray
{
    private:
        T *data;
        int nextindex;
        int capacity;
    public:
        StackArray(int totalsize)
        {
            data = new T [totalsize];
            capacity  = totalsize;
            nextindex = 0;
        }
        int size(){return nextindex;}
        bool isEmpty(){return nextindex == 0;}
        void push(T val)
        {
            if (nextindex == capacity)
            {
                std::cout<<"Stack is Full !!"<<std::endl;
                return ;
            }
            data[nextindex] = val;
            nextindex ++;
        }
        T pop()
        {
            if (isEmpty())
            {
                std::cout<<"Stack is Empty !!"<<std::endl;
                return 0;
            }
            nextindex--;
            return data[nextindex];
        }
        T top()
        {
            if (isEmpty())
            {
                std::cout<<"Stack is Empty !!"<<std::endl;
                return 0;
            }
            return data[nextindex-1];
        }

};