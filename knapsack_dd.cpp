#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int knapsack(const vector<int>& weight, const vector<int>& value, int capacity, vector<int>& selectedItems) {
    int n = value.size();
    vector<vector<int>> dp(n + 1, vector<int>(capacity + 1, 0));

    // Build the dp table
    for (int i = 1; i <= n; i++) {
        for (int w = 0; w <= capacity; w++) {
            if (weight[i - 1] <= w) {
                dp[i][w] = max(value[i - 1] + dp[i - 1][w - weight[i - 1]], dp[i - 1][w]);
            } else {
                dp[i][w] = dp[i - 1][w];
            }
        }
    }

    // Find out which items were selected
    int w = capacity;
    for (int i = n; i > 0 && w > 0; i--) {
        // Check if the item was included
        if (dp[i][w] != dp[i - 1][w]) {
            selectedItems.push_back(i - 1); // Store the index of the included item
            w -= weight[i - 1]; // Reduce the remaining weight
        }
    }

    return dp[n][capacity]; // Return the maximum value
}

int main() {
    vector<int> weight = {10, 20, 30};
    vector<int> value = {60, 100, 120}; // Correcting 'height' to 'value'
    int capacity = 50;

    vector<int> selectedItems; // To store the indices of selected items
    int max_val = knapsack(weight, value, capacity, selectedItems);
    
    cout << "Maximum value: " << max_val << endl;
    cout << "Selected items (0-indexed): ";
    for (int index : selectedItems) {
        cout << index << " "; // Print selected item indices
    }
    cout << endl;

    return 0;
}



// def knapsack(weight, value, capacity):
//     n = len(value)
//     dp = [[0 for _ in range(capacity + 1)] for _ in range(n + 1)]

//     # Build the dp table
//     for i in range(1, n + 1):
//         for w in range(capacity + 1):
//             if weight[i - 1] <= w:
//                 dp[i][w] = max(value[i - 1] + dp[i - 1][w - weight[i - 1]], dp[i - 1][w])
//             else:
//                 dp[i][w] = dp[i - 1][w]

//     # Find out which items were selected
//     selected_items = []
//     w = capacity
//     for i in range(n, 0, -1):
//         # Check if the item was included
//         if dp[i][w] != dp[i - 1][w]:
//             selected_items.append(i - 1)  # Store the index of the included item
//             w -= weight[i - 1]  # Reduce the remaining weight

//     return dp[n][capacity], selected_items  # Return the maximum value and selected items


// # Example usage
// weight = [10, 20, 30]
// value = [60, 100, 120]
// capacity = 50

// max_val, selected_items = knapsack(weight, value, capacity)

// print(f"Maximum value: {max_val}")
// print(f"Selected items (0-indexed): {selected_items}")



// #include <iostream>
// #include <vector>
// using namespace std;

// // Function to solve the 0-1 Knapsack problem using dynamic programming
// int knapsack(int W, vector<int>& weights, vector<int>& values, int n) {
//     // Create a 2D array to store the maximum value for each weight and item
//     vector<vector<int>> dp(n + 1, vector<int>(W + 1, 0));

//     // Build the dp array in a bottom-up manner
//     for (int i = 1; i <= n; i++) {
//         for (int w = 1; w <= W; w++) {
//             if (weights[i - 1] <= w) {
//                 // Take the maximum of including the item or not including it
//                 dp[i][w] = max(dp[i - 1][w], dp[i - 1][w - weights[i - 1]] + values[i - 1]);
//             } else {
//                 // Item cannot be included, carry forward the value
//                 dp[i][w] = dp[i - 1][w];
//             }
//         }
//     }
    
//     // The maximum value will be found at dp[n][W]
//     return dp[n][W];
// }

// int main() {
//     // Example input
//     int W = 50; // Maximum weight capacity of the knapsack
//     vector<int> weights = {10, 20, 30}; // Weights of the items
//     vector<int> values = {60, 100, 120}; // Values of the items
//     int n = values.size(); // Number of items

//     int maxValue = knapsack(W, weights, values, n);
//     cout << "Maximum value in the knapsack: " << maxValue << endl;

//     return 0;
// }



