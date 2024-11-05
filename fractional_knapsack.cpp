#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

struct item {
    int profit;
    int weight;

    item(int profit, int weight) {
        this->profit = profit;
        this->weight = weight;
    }
};

bool compare(item a, item b) {
    double r1 = (double)a.profit / a.weight;
    double r2 = (double)b.profit / b.weight;
    return r1 > r2;
}

double fractional_knapsack(vector<item> items, int capacity) {
    double tot_profit = 0.0;
    sort(items.begin(), items.end(), compare);

    for (item it : items) {
        if (it.weight <= capacity) {
            tot_profit += it.profit;
            capacity -= it.weight;
        } else {
            tot_profit += it.profit * ((double)capacity / it.weight);
            break;
        }
    }
    return tot_profit;
}

int main() {
    vector<item> items = {{60, 10}, {100, 20}, {120, 30}};
    int capacity = 50;  // Corrected variable name

    double maxval = fractional_knapsack(items, capacity);
    cout << maxval << endl;  // Added endl for better output formatting

    return 0;
}





// #include <iostream>
// #include <vector>
// #include <algorithm>

// using namespace std;

// // Structure to represent an item
// struct Item {
//     int value;
//     int weight;
// };

// // Comparator function to sort items based on value/weight ratio
// bool cmp(Item a, Item b) {
//     double r1 = (double)a.value / a.weight;
//     double r2 = (double)b.value / b.weight;
//     return r1 > r2; // Sort in descending order
// }

// // Function to solve the fractional knapsack problem
// double fractionalKnapsack(int W, vector<Item>& items) {
//     // Sort items by value/weight ratio
//     sort(items.begin(), items.end(), cmp);

//     double totalValue = 0.0; // Total value accumulated in knapsack

//     for (const auto& item : items) {
//         // If the item can fit into the knapsack
//         if (W >= item.weight) {
//             W -= item.weight; // Decrease remaining weight
//             totalValue += item.value; // Add its value to total value
//         } else {
//             // If the item can't fit, take the fractional part
//             totalValue += item.value * ((double)W / item.weight);
//             break; // Knapsack is now full
//         }
//     }

//     return totalValue; // Return the total value of knapsack
// }

// int main() {
//     int W; // Maximum weight of knapsack
//     int n; // Number of items

//     cout << "Enter the maximum weight of the knapsack: ";
//     cin >> W;
//     cout << "Enter the number of items: ";
//     cin >> n;

//     vector<Item> items(n); // Vector to store items

//     // Input item values and weights
//     for (int i = 0; i < n; i++) {
//         cout << "Enter value and weight of item " << i + 1 << ": ";
//         cin >> items[i].value >> items[i].weight;
//     }

//     // Calculate maximum value in the knapsack
//     double maxValue = fractionalKnapsack(W, items);

//     cout << "Maximum value in the knapsack: " << maxValue << endl;

//     return 0;
// }



// # Class to represent an item
// class Item:
//     def __init__(self, value, weight):
//         self.value = value
//         self.weight = weight

// # Function to compare items based on value-to-weight ratio
// def value_per_weight(item):
//     return item.value / item.weight

// # Function to solve the fractional knapsack problem
// def fractional_knapsack(W, items):
//     # Sort items by value/weight ratio in descending order
//     items.sort(key=value_per_weight, reverse=True)

//     total_value = 0.0  # Total value accumulated in knapsack

//     for item in items:
//         if W >= item.weight:  # If the item can fit into the knapsack
//             W -= item.weight  # Decrease remaining weight
//             total_value += item.value  # Add its value to total value
//         else:  # If the item can't fit, take the fractional part
//             total_value += item.value * (W / item.weight)
//             break  # Knapsack is now full

//     return total_value  # Return the total value of knapsack

// # Main function
// if __name__ == "__main__":
//     W = float(input("Enter the maximum weight of the knapsack: "))
//     n = int(input("Enter the number of items: "))

//     items = []
    
//     # Input item values and weights
//     for i in range(n):
//         value, weight = map(float, input(f"Enter value and weight of item {i + 1} (space-separated): ").split())
//         items.append(Item(value, weight))

//     # Calculate maximum value in the knapsack
//     max_value = fractional_knapsack(W, items)

//     print(f"Maximum value in the knapsack: {max_value:.2f}")
