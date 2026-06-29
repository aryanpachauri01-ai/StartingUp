#include <bits/stdc++.h>
using namespace std;

// Time Complexity of bubble sort is O(N²) in the worst/average case, but O(N) in the best case with optimization.
// We can also straight up use sort(arr, arr+n) from the STL to sort it with time complexity O(N log N).
int main() {
    int n;
    cout << "Enter size:\n";
    cin >> n;
    int arr[n];
    
    cout << "Enter elements:\n";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    // OPTIMIZED BUBBLE SORT LOGIC
    // The outer loop runs 'n' times to ensure all elements are sorted.
    for (int i = 0; i < n; i++) {
        // We initialize didSwap to 0 at the start of every new pass.
        // This tracks if we actually moved anything during this specific pass.
        int didSwap = 0;  
        
        // The inner loop compares adjacent elements. 
        // We use (n - i - 1) because the last 'i' elements are already sorted.
        for (int j = 0; j < n - i - 1; j++) {
            
            // If the current element is greater than the next element, swap them.
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j+1]); // Added the missing semicolon here!
                
                // Increment our counter because a swap happened.
                didSwap++;
            }
        }
        
        // If didSwap is still 0 after checking the whole unsorted portion, 
        // it means everything is already in perfect order. We can break early!
        if (didSwap == 0) {
            break;
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
Let's use an array that is almost completely sorted to see the optimization work.
Size (n) = 5
Elements = [3, 1, 2, 4, 5]

Initial Array: [3, 1, 2, 4, 5]

--- PASS 1 (i = 0) ---
- didSwap is initialized to 0.
- Inner loop goes from j = 0 to j = 3
  - j=0: 3 > 1? Yes. Swap. didSwap=1. Array -> [1, 3, 2, 4, 5]
  - j=1: 3 > 2? Yes. Swap. didSwap=2. Array -> [1, 2, 3, 4, 5]
  - j=2: 3 > 4? No. No swap.          Array -> [1, 2, 3, 4, 5]
  - j=3: 4 > 5? No. No swap.          Array -> [1, 2, 3, 4, 5]
- The largest unsorted number (3) bubbled to its proper place before the 4.
- didSwap is 2, so the break condition is skipped.

--- PASS 2 (i = 1) ---
- didSwap is reset to 0 for this new pass.
- Inner loop goes from j = 0 to j = 2
  - j=0: 1 > 2? No. No swap.
  - j=1: 2 > 3? No. No swap.
  - j=2: 3 > 4? No. No swap.
- The inner loop finishes. 
- didSwap is still 0! 

--- EARLY EXIT ---
- Because didSwap == 0, the 'break' statement is triggered.
- Passes 3, 4, and 5 are completely skipped!
- Array is finalized: [1, 2, 3, 4, 5]

Notice how the optimized Bubble Sort realized the array was sorted after 
just two passes, saving the computer from doing unnecessary loops!
=========================================
*/
