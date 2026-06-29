#include <bits/stdc++.h>

using namespace std;
//Time complexity is O(N²)
int main() {
    int n;
    cout << "Enter size:\n";
    cin >> n;
    int arr[n];
    
    cout << "Enter elements:\n";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    
    // SELECTION SORT LOGIC
    // The outer loop moves the boundary between the sorted and unsorted parts.
    for (int i = 0; i < n; i++) {
        
        // Assume the first element of the unsorted portion is the smallest
        int min = i;
        
        // The inner loop searches through the rest of the UNSORTED portion 
        for (int j = i + 1; j < n; j++) {
            
            // If we find a number smaller than our current minimum...
            if (arr[min] >= arr[j]) {
                // ...update the 'min' index to point to this new smallest number
                min = j;
            }
        }
        
        // Swap if the minimum is not already at the start of the unsorted portion
        if (i != min) {
            swap(arr[min], arr[i]);
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
Let's assume the user enters:
Size (n) = 5
Elements = [5, 2, 4, 1, 3]

Initial Array: [5, 2, 4, 1, 3]

--- PASS 1 (i = 0) ---
- min starts at index 0 (value: 5)
- j loop starts at 1, goes to 4:
  - j = 1 (value 2): 5 >= 2? Yes. min becomes 1.
  - j = 2 (value 4): 2 >= 4? No. min stays 1.
  - j = 3 (value 1): 2 >= 1? Yes. min becomes 3.
  - j = 4 (value 3): 1 >= 3? No. min stays 3.
- End of j loop. min is 3. 
- i (0) != min (3), so swap arr[0] and arr[3] (Swap 5 and 1).
- Array is now: [1, 2, 4, 5, 3]
  (The '1' is now in its final, sorted position)

--- PASS 2 (i = 1) ---
- min starts at index 1 (value: 2)
- j loop starts at 2, goes to 4:
  - j = 2 (value 4): 2 >= 4? No. min stays 1.
  - j = 3 (value 5): 2 >= 5? No. min stays 1.
  - j = 4 (value 3): 2 >= 3? No. min stays 1.
- End of j loop. min is 1.
- i (1) == min (1), so NO SWAP occurs.
- Array is still: [1, 2, 4, 5, 3]
  (The '1' and '2' are now sorted)

--- PASS 3 (i = 2) ---
- min starts at index 2 (value: 4)
- j loop starts at 3, goes to 4:
  - j = 3 (value 5): 4 >= 5? No. min stays 2.
  - j = 4 (value 3): 4 >= 3? Yes. min becomes 4.
- End of j loop. min is 4.
- i (2) != min (4), so swap arr[2] and arr[4] (Swap 4 and 3).
- Array is now: [1, 2, 3, 5, 4]

--- PASS 4 (i = 3) ---
- min starts at index 3 (value: 5)
- j loop starts at 4, goes to 4:
  - j = 4 (value 4): 5 >= 4? Yes. min becomes 4.
- End of j loop. min is 4.
- i (3) != min (4), so swap arr[3] and arr[4] (Swap 5 and 4).
- Array is now: [1, 2, 3, 4, 5]

--- PASS 5 (i = 4) ---
- min starts at index 4 (value: 5)
- j loop starts at 5. Since j < 5 is false, inner loop doesn't run.
- i (4) == min (4), so NO SWAP occurs.
- Array is finalized: [1, 2, 3, 4, 5]
=========================================
*/
