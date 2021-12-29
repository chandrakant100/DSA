#include <vector>
class PriorityQueue
{
    std::vector<int> pq;
    public:
    PriorityQueue()
    {

    }
    bool isEmpty()
    {
        return pq.size() == 0;
    }
    int getSize()
    {
        return pq.size();
    }
    int getMin()
    {
        if (isEmpty())
            return 0;
        return pq.at(0);
    }
    void insert(int data)
    {
        if (pq.size() == 0)
        {
            pq.push_back(data);
            return;
        }
        pq.push_back(data);
        int childIndex = pq.size()-1;
        int parentIndex = (childIndex-1)/2;
        while(childIndex > 0)
        {
            parentIndex = (childIndex-1)/2;
            if (pq.at(parentIndex) > pq.at(childIndex))
            {
                int temp = pq.at(parentIndex);
                pq.at(parentIndex) = pq.at(childIndex);
                pq.at(childIndex) = temp;
            }
            else
            {
                break;
            }
            childIndex = parentIndex;
        }
    }
    int removeMin()
    {       
        if (isEmpty())
            return 0;
        
        int temp = pq[0];
        pq[0] = pq[pq.size()-1];
        pq[pq.size()-1] = temp;
        
        pq.pop_back();
        
        int parentIndex = 0;
        
        int LeftChild = 2*parentIndex + 1;
        int RightChild = 2*parentIndex + 2;

        while(LeftChild < pq.size())
        {
            int minIndex = parentIndex;
            if (pq[minIndex] > pq[LeftChild])
                minIndex = LeftChild;
            
            if (RightChild < pq.size() && pq[RightChild] < pq[minIndex])
                minIndex = RightChild;
			
            if (minIndex == parentIndex)
                break;
            
            int temp = pq[minIndex];
            pq[minIndex] = pq[parentIndex];
            pq[parentIndex] = temp;

            parentIndex = minIndex;
            LeftChild = 2*parentIndex + 1;
            RightChild = 2*parentIndex + 2;
        }
        return temp;
    }
};