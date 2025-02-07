// LeetCode Problem (238) : Product of array except self

// Difficulty : Medium 

// Time Complexity : O(n) , Space Complexity : O(1)



// DESCRIPTION : 


// Given an integer array nums, return an array answer such that answer[i] is equal to the product of all the elements of nums except nums[i].

// The product of any prefix or suffix of nums is guaranteed to fit in a 32-bit integer.

// You must write an algorithm that runs in O(n) time and without using the division operation.



// Example 1:

// Input: nums = [1,2,3,4]
// Output: [24,12,8,6]
// Example 2:

// Input: nums = [-1,1,0,-3,3]
// Output: [0,0,9,0,0]
 

// Constraints:

// 2 <= nums.length <= 105
// -30 <= nums[i] <= 30
// The input is generated such that answer[i] is guaranteed to fit in a 32-bit integer.


#include <iostream>
#include <vector>
using namespace std;

// Function to calculate the product of all elements except itself
vector<int> productExceptSelf(vector<int>& nums) {
    int n = nums.size();
    vector<int> ans(n, 1); // Initialize output array with 1s

    // Step 1: Compute prefix product for each element
    // Prefix product stores the product of all elements to the left of the current element
    for (int i = 1; i < n; i++) {
        ans[i] = ans[i - 1] * nums[i - 1]; // ans[i] = (product of all previous elements)
    }

    // Step 2: Compute suffix product and multiply with prefix product
    int suffix = 1; // Suffix product (stores product of all elements to the right)
    for (int i = n - 2; i >= 0; i--) {
        suffix *= nums[i + 1]; // Multiply suffix by the next element
        ans[i] *= suffix; // Multiply suffix with prefix product already stored in ans[i]
    }

    return ans;
}

int main() {
    vector<int> nums = {1, 2, 3, 4}; // Example input array
    vector<int> result = productExceptSelf(nums); // Call the function

    // Print the resulting array
    cout << "Product Except Self: ";
    for (int num : result) {
        cout << num << " ";
    }

    return 0;
}
