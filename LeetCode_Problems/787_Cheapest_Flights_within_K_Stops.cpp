/*
LeetCode Problem 787: Cheapest Flights Within K Stops
Difficulty: Medium
Algorithm: Bellman-Ford Algorithm
Time Complexity: O(E * K), where k is the maximum number of stops and E is the number of edges (flights).
Space Complexity: O(N), where N is the number of nodes (cities).

Description:
There are n cities connected by some number of flights. You are given an array flights where flights[i] = [fromi, toi, pricei] indicates that there is a flight from city fromi to city toi with cost pricei.

You are also given three integers src, dst, and k, return the cheapest price from src to dst with at most k stops. If there is no such route, return -1.

 

Example 1:


Input: n = 4, flights = [[0,1,100],[1,2,100],[2,0,100],[1,3,600],[2,3,200]], src = 0, dst = 3, k = 1
Output: 700
Explanation:
The graph is shown above.
The optimal path with at most 1 stop from city 0 to 3 is marked in red and has cost 100 + 600 = 700.
Note that the path through cities [0,1,2,3] is cheaper but is invalid because it uses 2 stops.
Example 2:


Input: n = 3, flights = [[0,1,100],[1,2,100],[0,2,500]], src = 0, dst = 2, k = 1
Output: 200
Explanation:
The graph is shown above.
The optimal path with at most 1 stop from city 0 to 2 is marked in red and has cost 100 + 100 = 200.
Example 3:


Input: n = 3, flights = [[0,1,100],[1,2,100],[0,2,500]], src = 0, dst = 2, k = 0
Output: 500
Explanation:
The graph is shown above.
The optimal path with no stops from city 0 to 2 is marked in red and has cost 500.
 

Constraints:

1 <= n <= 100
0 <= flights.length <= (n * (n - 1) / 2)
flights[i].length == 3
0 <= fromi, toi < n
fromi != toi
1 <= pricei <= 104
There will not be any multiple flights between two cities.
0 <= src, dst, k < n
src != dst
*/

#include <iostream>
#include <vector>
#include <climits> // for INT_MAX
using namespace std;

// Function to find the cheapest price
int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
    vector<int> prices(n, INT_MAX);
    prices[src] = 0;

    for (int i = 0; i <= k; i++) {
        vector<int> temp = prices;

        for (int j = 0; j < flights.size(); j++) {
            int s = flights[j][0];
            int d = flights[j][1];
            int p = flights[j][2];

            if (prices[s] == INT_MAX) continue;

            if (prices[s] + p < temp[d]) {
                temp[d] = prices[s] + p;
            }
        }

        prices = temp;
    }

    return prices[dst] == INT_MAX ? -1 : prices[dst];
}

int main() {
    int n, m;
    cout << "Enter number of cities (nodes): ";
    cin >> n;

    cout << "Enter number of flights (edges): ";
    cin >> m;

    vector<vector<int>> flights(m, vector<int>(3));

    cout << "Enter flights in format (source destination price):\n";
    for (int i = 0; i < m; i++) {
        cin >> flights[i][0] >> flights[i][1] >> flights[i][2];
    }

    int src, dst, k;
    cout << "Enter source city, destination city, and max stops (k): ";
    cin >> src >> dst >> k;

    int result = findCheapestPrice(n, flights, src, dst, k);

    if (result == -1) {
        cout << "No path found within " << k << " stops." << endl;
    } else {
        cout << "Cheapest price: " << result << endl;
    }

    return 0;
}
