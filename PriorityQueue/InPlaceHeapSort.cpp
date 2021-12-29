#include <iostream>
using namespace std;

void removeMin(int *pq,int n)
{
    if (n == 0)
        return ;
      int parentIndex = 0;
        
        int LeftChild = 2*parentIndex + 1;
        int RightChild = 2*parentIndex + 2;

        while(LeftChild < n)
        {
            int minIndex = parentIndex;
            if (pq[minIndex] > pq[LeftChild])
                minIndex = LeftChild;
            
            if (RightChild < n && pq[RightChild] < pq[minIndex])
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
}
void heapSort(int arr[], int n) {
    // Write your code
    if (n == 0)
        return;
    int parentIndex;
    for (int i{1}; i < n; i++)
    {
	    int childIndex = i;
        while(childIndex > 0)
        {
            parentIndex = (childIndex-1)/2;
            if (arr[parentIndex] > arr[childIndex])
            {
                int temp = arr[parentIndex];
                arr[parentIndex] = arr[childIndex];
                arr[childIndex] = temp;
            }
            else
            {
                break;
            }
            childIndex = parentIndex;
        }
    }
    for (int i{n-1}; i >= 0; i--)
    {
        int temp = arr[i];
        arr[i] = arr[0];
        arr[0] = temp;
        
        removeMin(arr,i);
    }
    
}
int main() {
    int size;
    cin >> size;

    int *input = new int[size];

    for (int i = 0; i < size; i++) {
        cin >> input[i];
    } 

    heapSort(input, size);

    for (int i = 0; i < size; i++) {
        cout << input[i] << " ";
    } 

    delete[] input;
}