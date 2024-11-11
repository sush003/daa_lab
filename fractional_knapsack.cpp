#include <iostream>
#include <algorithm>  // For sorting
using namespace std;

// Function to calculate the maximum value in the knapsack
double fractionalKnapsack(int W, int weights[], int values[], int n) {
    // Calculate value per weight ratio and store them in an array
    double ratio[n];
    for (int i = 0; i < n; i++) {
        ratio[i] = (double)values[i] / weights[i];
    }

    // Simple sorting of items based on value-to-weight ratio
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (ratio[i] < ratio[j]) {
                // Swap ratios
                swap(ratio[i], ratio[j]);
                // Swap the corresponding weights and values
                swap(values[i], values[j]);
                swap(weights[i], weights[j]);
            }
        }
    }

    double totalValue = 0.0;  // To store the total value in the knapsack
    for (int i = 0; i < n; i++) {
        if (W == 0) break;  // If the knapsack is full, stop

        if (weights[i] <= W) {
            // Take the entire item if it fits
            W -= weights[i];
            totalValue += values[i];
        } else {
            // Take the fractional part of the item
            totalValue += values[i] * ((double)W / weights[i]);
            W = 0;  // Knapsack is now full
        }
    }

    return totalValue;
}

int main() {
    int n, W;

    // Input the number of items and the capacity of the knapsack
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

    double maxValue = fractionalKnapsack(W, weights, values, n);
    cout << "Maximum value in the knapsack: " << maxValue << endl;

    return 0;
}
