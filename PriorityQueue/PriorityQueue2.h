#include <vector>
class PriorityQueue {
    // Declare the data members here
	std::vector<int> pq;
	 public:
    PriorityQueue() {
        // Implement the constructor here
    }
	bool isEmpty()
    {
        return pq.size() == 0;
    }
    int getSize()
    {
        return pq.size();
    }
    /**************** Implement all the public functions here ***************/

    void insert(int data) {
        // Implement the insert() function here
        
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
            if (pq.at(parentIndex) < pq.at(childIndex))
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

    int getMax() {
        // Implement the getMax() function here
        if (isEmpty())
            return 0;
        
        return pq.at(0);
    }

    int removeMax() {
        // Implement the removeMax() function here
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
            int maxindex = parentIndex;
            if (pq[maxindex] < pq[LeftChild])
                maxindex = LeftChild;
            
            if (RightChild < pq.size() && pq[RightChild] > pq[maxindex])
                maxindex = RightChild;
			
            if (maxindex == parentIndex)
                break;
            
            int temp = pq[maxindex];
            pq[maxindex] = pq[parentIndex];
            pq[parentIndex] = temp;

            parentIndex = maxindex;
            LeftChild = 2*parentIndex + 1;
            RightChild = 2*parentIndex + 2;
        }
        return temp;
    }
};