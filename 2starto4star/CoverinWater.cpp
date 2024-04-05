#include <iostream>
#include <vector>
using namespace std;

// Function to print all subarrays of an array
void printSubarrays(const vector<int>& arr) {
    int n = arr.size();
    int count = 0;
    // Iterate through all possible starting indices
    for (int i = 0; i < n; ++i) {
        // Iterate through all possible ending indices
        for (int j = i; j < n; ++j) {
            // Print subarray from index i to j
            cout << " index : " << j << " : [";
            for (int k = i; k <= j; ++k) {
                cout << arr[k];
                if (k != j) cout << ", ";
            }
            count++;
            cout << "]" << endl;
        }
        cout << endl;
    }
    cout << count << endl;
}

int main() {
    vector<int> arr = {1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 0, 1, 0, 1, 0, 1};
    cout << "All subarrays of the given array: " << endl;
    printSubarrays(arr);
    return 0;
}
