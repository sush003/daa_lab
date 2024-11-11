#include <iostream>
#include <algorithm>
using namespace std;

// Function to find the maximum value that can be obtained
int knapsack(int W, int weights[], int values[], int n) {
    // Create a DP array to store the maximum value at each weight capacity
    int dp[W + 1] = {0};

    // Iterate over each item
    for (int i = 0; i < n; i++) {
        // Traverse the dp array backward to avoid reusing the same item multiple times
        for (int w = W; w >= weights[i]; w--) {
            // Update dp[w] to the maximum value by either including or excluding the current item
            dp[w] = max(dp[w], dp[w - weights[i]] + values[i]);
        }
    }

    // The last element of dp array contains the maximum value that can be carried in the knapsack
    return dp[W];
}

int main() {
    int n, W;

    // Input number of items and the capacity of the knapsack
    cout << "Enter the number of items: ";
    cin >> n;
    cout << "Enter the capacity of the knapsack: ";
    cin >> W;

    int weights[n], values[n];

    // Input the weights and values of the items
    cout << "Enter the weights and values of the items:\n";
    for (int i = 0; i < n; i++) {
        cin >> weights[i] >> values[i];
    }

    int maxValue = knapsack(W, weights, values, n);
    cout << "Maximum value in the knapsack: " << maxValue << endl;

    return 0;
}
