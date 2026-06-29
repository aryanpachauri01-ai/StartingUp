#include<bits/stdc++.h>
using namespace std;

// Time Complexity of Insertion Sort:
// Worst/Average Case: O(N²) (When array is in reverse or random order)
// Best Case: O(N) (When the array is already sorted, the inner loop never runs!)
// Just like before, STL sort(arr, arr+n) can be used for O(N log N) performance.

int main() {
    int n;
    cout << "Enter Size:\n";
    cin >> n;
    int arr[n];
    
    cout << "Enter elements:\n";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    
    // INSERTION SORT LOGIC
    // The outer loop picks the next element to be inserted into the sorted portion.
    // Everything to the left of 'i' is considered sorted.
    for (int i = 0; i <= n - 1; i++) {
        int j = i;
        
        // The inner loop checks the current element against the sorted elements to its left.
        // It keeps swapping the element leftwards as long as it is smaller than the one before it.
        // (j > 0 ensures we don't try to compare an element at index 0 with index -1, avoiding a crash)
        while (j > 0 && arr[j - 1] > arr[j]) {
            swap(arr[j - 1], arr[j]);
            j--; // Move our pointer leftward to track the element we are pushing down
        }
    }
    
    // Print the final sorted array
    cout << "Sorted Array:\n";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " "; 
    }
    cout << "\n";
    
    return 0;
}

/* =========================================
      DRY RUN (Step-by-Step Trace)
=========================================
Let's use an array that requires some shifting to see it in action.
Size (n) = 5
Elements = [4, 2, 5, 1, 3]

Initial Array: [4, 2, 5, 1, 3]

--- PASS 1 (i = 0) ---
- We are looking at index 0 (value: 4).
- j = 0. The while loop condition requires j > 0, so it immediately fails.
- (A single element is always trivially sorted!)
- Array remains: [4, 2, 5, 1, 3]

--- PASS 2 (i = 1) ---
- We pick up the element at index 1 (value: 2).
- j = 1. Is arr[0] > arr[1]? (4 > 2?) Yes!
  - Swap them. Array -> [2, 4, 5, 1, 3].
  - j becomes 0.
- j is no longer > 0, so loop ends.
- The first two elements [2, 4] are now sorted.

--- PASS 3 (i = 2) ---
- We pick up the element at index 2 (value: 5).
- j = 2. Is arr[1] > arr[2]? (4 > 5?) No.
- The while loop doesn't even run. The element 5 is already in the right spot!
- The first three elements [2, 4, 5] are sorted.

--- PASS 4 (i = 3) ---
- We pick up the element at index 3 (value: 1). This is a tiny number, so it will shift far!
- j = 3. Is arr[2] > arr[3]? (5 > 1?) Yes. Swap. Array -> [2, 4, 1, 5, 3]. j becomes 2.
- j = 2. Is arr[1] > arr[2]? (4 > 1?) Yes. Swap. Array -> [2, 1, 4, 5, 3]. j becomes 1.
- j = 1. Is arr[0] > arr[1]? (2 > 1?) Yes. Swap. Array -> [1, 2, 4, 5, 3]. j becomes 0.
- Loop ends. The '1' successfully traveled all the way to the front!

--- PASS 5 (i = 4) ---
- We pick up the last element at index 4 (value: 3).
- j = 4. Is arr[3] > arr[4]? (5 > 3?) Yes. Swap. Array -> [1, 2, 4, 3, 5]. j becomes 3.
- j = 3. Is arr[2] > arr[3]? (4 > 3?) Yes. Swap. Array -> [1, 2, 3, 4, 5]. j becomes 2.
- j = 2. Is arr[1] > arr[2]? (2 > 3?) No. 
- Loop ends. The '3' stopped right where it belongs.
- Array is finalized: [1, 2, 3, 4, 5]
=========================================
*/
