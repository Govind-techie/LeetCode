/*
LeetCode Problem 234: Palindrome Linked List
Difficulty: Easy
Algorithm: Linked List, reverse linked list, split linked list, fast and slow pointers
Time Complexity: O(n)
Space Complexity: O(1)

Description:

Given the head of a singly linked list, return true if it is a palindrome or false otherwise.

Example 1:

Input: head = [1,2,2,1]
Output: true
Example 2:


Input: head = [1,2]
Output: false
 

Constraints:

The number of nodes in the list is in the range [1, 105].
0 <= Node.val <= 9

*/

#include <iostream>
using namespace std;

// Definition for singly-linked list node
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* splitAtMid(ListNode* head){
        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* prev = NULL;

        while (fast != NULL && fast->next != NULL){
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        if (prev != NULL) {
            prev->next = NULL;
        }

        return slow;
    }

    ListNode* reverse(ListNode* head){
        ListNode* prev = NULL;
        ListNode* curr = head;
        
        while (curr != NULL){
            ListNode* next = curr->next;
            curr->next = prev;
            
            prev = curr;
            curr = next;
        }
        return prev;
    }

    bool isPalindrome(ListNode* head) {
        if (head == NULL || head->next == NULL) return true;

        ListNode* rightHead = splitAtMid(head);
        ListNode* right = reverse(rightHead);
        ListNode* left = head;

        while (left != NULL && right != NULL){
            if (left->val != right->val){
                return false;
            }
            left = left->next;
            right = right->next;
        }
        return true;
    }
};

// Utility function to create a linked list from array
ListNode* createList(int arr[], int n){
    if (n == 0) return NULL;
    ListNode* head = new ListNode(arr[0]);
    ListNode* curr = head;
    for (int i = 1; i < n; i++){
        curr->next = new ListNode(arr[i]);
        curr = curr->next;
    }
    return head;
}

// Utility function to print linked list
void printList(ListNode* head){
    ListNode* curr = head;
    while (curr != NULL){
        cout << curr->val;
        if (curr->next != NULL) cout << " -> ";
        curr = curr->next;
    }
    cout << "\n";
}

int main(){
    // Example test case
    int arr[] = {1, 2, 3, 2, 1};
    int n = sizeof(arr)/sizeof(arr[0]);

    ListNode* head = createList(arr, n);
    cout << "Original List: ";
    printList(head);

    Solution sol;
    bool result = sol.isPalindrome(head);
    cout << "Is Palindrome? " << (result ? "Yes" : "No") << "\n";

    return 0;
}