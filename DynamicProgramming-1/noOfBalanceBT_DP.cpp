#include <iostream>
#include <cmath>
using namespace std;

#define mod 1000000007

int balancedBTs(int n) {
    // Write your code here
    long arr[n+1];
    arr[0] = 1;
    arr[1] = 1;
    
    for (int i{2}; i<=n; i++)
    {
        // arr[i] = (int)(((long)(arr[i-1])*arr[i-1])%mod) + (int)((2 * (long)(arr[i-1]) * arr[i-2])%mod);
        arr[i] = (arr[i - 1] * ((2 * arr[i - 2])%mod + arr[i - 1])%mod) % mod;
    }
    return arr[n];
}
int main() {
    int n;
    cin >> n;
    cout << balancedBTs(n);
}