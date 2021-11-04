#include <iostream>
using namespace std;

void merge(int input[], int const beg, int const mid, int const end)
{
  int sub1 = mid-beg +1;
  int sub2 = end-mid;

  int *temp1 = new int[sub1];
  int *temp2 = new int[sub2];

  for (int i{0}; i < sub1; i++)
  {
    temp1[i] = input[beg+i];
  }
  
  for (int i{0}; i < sub2; i++)
  {
    temp2[i] = input[mid+1+i];
  }
  auto indexsub1{0},indexsub2{0};
  int mergeindex = beg;
  while (indexsub1 < sub1 && indexsub2 < sub2)
  {
    if (temp1[indexsub1] <= temp2[indexsub2])
    {
      input[mergeindex] = temp1[indexsub1];
      indexsub1++;
    }
    else{
      input[mergeindex] = temp2[indexsub2];
      indexsub2++;
    }
    mergeindex++;
  }

  while(indexsub1 < sub1)
  {
    input[mergeindex] = temp1[indexsub1];
    mergeindex++;
    indexsub1++;
  }

  while(indexsub2 < sub2)
  {
    input[mergeindex] = temp2[indexsub2];
    mergeindex++;
    indexsub2++;
  }
  delete [] temp1;
  delete [] temp2;
}
void MergeSort(int* input,int beg,int end)
{
    if ( beg >= end)
        return;
    int mid = beg + (end-beg)/2;

    MergeSort(input,beg,mid);
    MergeSort(input,mid+1,end);

    merge(input,beg,mid,end);
}
void mergeSort(int input[], int size){
	// Write your code here
    MergeSort(input,0,size-1);
}
int main() {
  int length;
  cin >> length;
  int* input = new int[length];
  for(int i=0; i < length; i++)
    cin >> input[i];
  mergeSort(input, length);
  for(int i = 0; i < length; i++) {
    cout << input[i] << " ";
  }
}