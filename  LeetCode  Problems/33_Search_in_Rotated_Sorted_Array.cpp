// LeetCode Problem (33) : Search in Rotated Sorted Array.

// Difficulty : Medium

// Algorithm Used : Binary Search

// Time Complexity : O(logn)


// DESCRIPTION :

// There is an integer array nums sorted in ascending order (with distinct values).

// Prior to being passed to your function, nums is possibly rotated at an unknown pivot index k (1 <= k < nums.length) such that the resulting array is [nums[k], nums[k+1], ..., nums[n-1], nums[0], nums[1], ..., nums[k-1]] (0-indexed). For example, [0,1,2,4,5,6,7] might be rotated at pivot index 3 and become [4,5,6,7,0,1,2].

// Given the array nums after the possible rotation and an integer target, return the index of target if it is in nums, or -1 if it is not in nums.

// You must write an algorithm with O(log n) runtime complexity.

 

// Example 1:

// Input: nums = [4,5,6,7,0,1,2], target = 0
// Output: 4
// Example 2:

// Input: nums = [4,5,6,7,0,1,2], target = 3
// Output: -1
// Example 3:

// Input: nums = [1], target = 0
// Output: -1
 

// Constraints:

// 1 <= nums.length <= 5000
// -104 <= nums[i] <= 104
// All values of nums are unique.
// nums is an ascending array that is possibly rotated.
// -104 <= target <= 104


#include <iostream>
#include <vector>
using namespace std;

int search(vector<int>& nums, int target) {
    int start = 0;
    int end = nums.size() - 1;
    
    while (start < end){
        int mid = start + (end - start)/2;
        if (nums[mid] > nums[end]){
            start = mid + 1;
        }else if(nums[mid] < nums[end]){
            end = mid;
        }
    }

    int pivot = start; // Pivot is the smallest element's index

    // Step 2: Determine which half to search
    start = 0, end = nums.size() - 1;
    if (target >= nums[pivot] && target <= nums[end]) {
        start = pivot;  // Search in the right half
    } else {
        end = pivot - 1;  // Search in the left half
    }

    // Left Half :
    while (start <= end){
        int mid = start + (end-start)/2;

        if (target == nums[mid]){
            return mid;
        }else if(target < nums[mid]){
            end = mid-1;
        }else if(target > nums[mid]){
            start = mid+1;
        }
    }

    return -1;
}

int main() {
    vector<int> nums = {4, 5, 6, 7, 0, 1, 2}; // Example input
    int target = 0;
    int result = search(nums, target);
    cout << "Target Index: " << result << endl;
    return 0;
}