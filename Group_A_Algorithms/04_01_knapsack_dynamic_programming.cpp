
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int knapsack01_MemoDP(vector<vector<int>> &items,
                      int W, int n,
                      vector<vector<int>> &dp)
{

    if (n == 0 || W == 0)
        return 0;

    if (dp[n][W] != -1)
        return dp[n][W];

    int val = items[n - 1][0];
    int wt = items[n - 1][1];

    if (wt <= W)
    {

        int include = val + knapsack01_MemoDP(items, W - wt, n - 1, dp);

        int exclude = knapsack01_MemoDP(items, W, n - 1, dp);

        return dp[n][W] = max(include, exclude);
    }
    else
    {
        return dp[n][W] = knapsack01_MemoDP(items, W, n - 1, dp);
    }
}

int main()
{

    int n, W;

    cout << "Enter number of items: ";
    cin >> n;

    vector<vector<int>> items(n, vector<int>(2));

    cout << "Enter value and weight of items:\n";

    for (int i = 0; i < n; i++)
    {
        cin >> items[i][0] >> items[i][1];
    }

    cout << "Enter knapsack capacity: ";
    cin >> W;

    vector<vector<int>> dp(n + 1, vector<int>(W + 1, -1));

    cout << "Maximum Profit = "
         << knapsack01_MemoDP(items, W, n, dp);

    return 0;
}
