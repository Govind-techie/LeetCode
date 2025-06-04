/*
LeetCode Problem 496: Next Greater Element I
Difficulty: Easy
Algorithm: Stack
Time Complexity: O(n)
Space Complexity: O(n)

Description:

The next greater element of some element x in an array is the first greater element that is to the right of x in the same array.

You are given two distinct 0-indexed integer arrays nums1 and nums2, where nums1 is a subset of nums2.

For each 0 <= i < nums1.length, find the index j such that nums1[i] == nums2[j] and determine the next greater element of nums2[j] in nums2. If there is no next greater element, then the answer for this query is -1.

Return an array ans of length nums1.length such that ans[i] is the next greater element as described above.

 

Example 1:

Input: nums1 = [4,1,2], nums2 = [1,3,4,2]
Output: [-1,3,-1]
Explanation: The next greater element for each value of nums1 is as follows:
- 4 is underlined in nums2 = [1,3,4,2]. There is no next greater element, so the answer is -1.
- 1 is underlined in nums2 = [1,3,4,2]. The next greater element is 3.
- 2 is underlined in nums2 = [1,3,4,2]. There is no next greater element, so the answer is -1.
Example 2:

Input: nums1 = [2,4], nums2 = [1,2,3,4]
Output: [3,-1]
Explanation: The next greater element for each value of nums1 is as follows:
- 2 is underlined in nums2 = [1,2,3,4]. The next greater element is 3.
- 4 is underlined in nums2 = [1,2,3,4]. There is no next greater element, so the answer is -1.
 

Constraints:

1 <= nums1.length <= nums2.length <= 1000
0 <= nums1[i], nums2[i] <= 104
All integers in nums1 and nums2 are unique.
All the integers of nums1 also appear in nums2.
*/

#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n = nums2.size();
        vector<int> nge(n, -1);
        stack<int> st;

        // Step 1: Precompute NGE for nums2
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && st.top() <= nums2[i]) {
                st.pop();
            }

            if (!st.empty()) {
                nge[i] = st.top();
            }

            st.push(nums2[i]);
        }

        // Step 2: Build result for nums1 based on nums2's NGE
        vector<int> result;
        for (int num : nums1) {
            for (int i = 0; i < n; ++i) {
                if (nums2[i] == num) {
                    result.push_back(nge[i]);
                    break;
                }
            }
        }

        return result;
    }

    /*
    Explanation of Step 2:
    
    Since nums1 is a subset of nums2, and you’ve already precomputed the Next Greater Element (nge[]) for every index in nums2 using a stack, then:
	•	Every element in nums1 exists somewhere in nums2.
	•	You just need to find the index of that element in nums2, and use the nge[] value at that index.
	•	This avoids recomputing anything and keeps your result construction clean.

    This is a classic example of:
	•	Preprocessing the larger array (nums2)
	•	Using that preprocessed info to answer multiple queries efficiently (for nums1)
    */
};

// Driver Code
int main() {
    Solution sol;
    vector<int> nums1 = {4, 1, 2};
    vector<int> nums2 = {1, 3, 4, 2};

    vector<int> result = sol.nextGreaterElement(nums1, nums2);

    cout << "Next Greater Elements: ";
    for (int val : result) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}

