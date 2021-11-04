#include <iostream>
using namespace std;

int findUnique(int *arr, int n) {
    // Write your code here
    int count{0};
    for (int i{0}; i < n; i++)
    {
        count ^= arr[i];
    }
    return count;
}
int main() {
    int t;
    cin >> t;

    while (t--) {
        int size;
        cin >> size;
        int *input = new int[size];

        for (int i = 0; i < size; ++i) {
            cin >> input[i];
        }

        cout << findUnique(input, size) << endl;
    }

    return 0;
}