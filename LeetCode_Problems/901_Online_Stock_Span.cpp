/*
LeetCode Problem 901: Online Stock Span
Difficulty: Medium
Algorithm: Stack
Time Complexity: O(n)
Space Complexity: O(n)

Description:

Design an algorithm that collects daily price quotes for some stock and returns the span of that stock's price for the current day.

The span of the stock's price in one day is the maximum number of consecutive days (starting from that day and going backward) for which the stock price was less than or equal to the price of that day.

For example, if the prices of the stock in the last four days is [7,2,1,2] and the price of the stock today is 2, then the span of today is 4 because starting from today, the price of the stock was less than or equal 2 for 4 consecutive days.
Also, if the prices of the stock in the last four days is [7,34,1,2] and the price of the stock today is 8, then the span of today is 3 because starting from today, the price of the stock was less than or equal 8 for 3 consecutive days.
Implement the StockSpanner class:

StockSpanner() Initializes the object of the class.
int next(int price) Returns the span of the stock's price given that today's price is price.
 

Example 1:

Input
["StockSpanner", "next", "next", "next", "next", "next", "next", "next"]
[[], [100], [80], [60], [70], [60], [75], [85]]
Output
[null, 1, 1, 1, 2, 1, 4, 6]

Explanation
StockSpanner stockSpanner = new StockSpanner();
stockSpanner.next(100); // return 1
stockSpanner.next(80);  // return 1
stockSpanner.next(60);  // return 1
stockSpanner.next(70);  // return 2
stockSpanner.next(60);  // return 1
stockSpanner.next(75);  // return 4, because the last 4 prices (including today's price of 75) were less than or equal to today's price.
stockSpanner.next(85);  // return 6
 

Constraints:

1 <= price <= 105
At most 104 calls will be made to next.
*/


#include <iostream>
#include <stack>
using namespace std;

class StockSpanner {
    // Stack stores pairs of {price, span}
    stack<pair<int, int>> st;

public:
    // Constructor
    StockSpanner() {}

    // This function is called each time a new price comes in
    int next(int price) {
        int span = 1; // Every price has at least 1-day span (itself)

        // While stack is not empty and the top price is less than or equal to current price
        while (!st.empty() && st.top().first <= price) {
            // Add the span of the top element to current span
            // Because all prices less than current can be part of the span
            span += st.top().second;

            // Remove the price since it’s no longer needed (it's merged into span)
            st.pop();
        }

        // Push current price with its span into the stack
        st.push({price, span});

        // Return the span
        return span;
    }
};

int main() {
    StockSpanner obj;

    // Sample input
    vector<int> prices = {100, 80, 60, 70, 60, 75, 85};
    
    for (int price : prices) {
        int span = obj.next(price);
        cout << span << " ";
    }
    cout << endl;

    return 0;
}