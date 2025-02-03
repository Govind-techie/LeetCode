// LeetCode Problem (50) : Pow(x,n)
// Difficulty : (Medium)

// Time Complexity : O(logn)

// Implement pow(x, n), which calculates x raised to the power n (i.e. , x^n).


// Example 1:

// Input: x = 2.00000, n = 10
// Output: 1024.00000
// Example 2:

// Input: x = 2.10000, n = 3
// Output: 9.26100
// Example 3:

// Input: x = 2.00000, n = -2
// Output: 0.25000
// Explanation: 2-2 = 1/22 = 1/4 = 0.25
 

// Constraints:

// -100.0 < x < 100.0
// -231 <= n <= 231-1
// n is an integer.
// Either x is not zero or n > 0.
// -104 <= xn <= 104

#include<iostream>
using namespace std;

double Pow(double x, int n) {
    // Edge Cases
    if (n == 0) return 1.0;
    if (x == 0) return 0.0;
    if (x == 1) return 1.0;
    if (x == -1 && n%2 == 0) return 1.0;
    if (x == -1 && n%2 != 0) return -1.0;

    double ans = 1;

    if (n == INT_MIN){
        x = 1/x;
        n = INT_MAX;
    }

    if (n < 0){
        x = 1/x;
        n = -n;
    }

    while (n > 0){
        if (n%2 == 1){
            ans *= x;
        }
        x *= x;
        n /= 2;
    }
    return ans;
}


int main(){
    int x;
    cout<<"Enter an integer value : ";
    cin>>x;

    int n;
    cout<<"Enter its power : ";
    cin>>n;

    cout<<x<<"^"<<n<<"is : "<<Pow(x,n)<<endl;
    return 0;
}