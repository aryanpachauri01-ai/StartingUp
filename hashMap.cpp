#include<bits/stdc++.h>
using namespace std;

int main() {
    cout << "Enter size of array\n";
    int n;
    cin >> n;
    
    // Create an array of size 'n'
    int arr[n];
    cout << "Enter Elements of Array\n";
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    
    // --- MAP DECLARATION ---
    // Syntax: unordered_map<key_type, value_type> map_name;
    unordered_map<int, int> mpp;
    
    /* --- REVISION NOTES: unordered_map vs map ---
     * 1. unordered_map (Uses Hashing under the hood)
     * - Best/Average Case Time Complexity: O(1)
     * - Worst Case Time Complexity: O(N) (Happens when there are many hash collisions)
     * 2. map (Uses a Red-Black Tree under the hood)
     * - Time Complexity in ALL cases: O(log N)
     * - Elements are stored in sorted order of their keys.
     */
     
    // --- PRE-COMPUTATION (Populating the Map) ---
    for(int i = 0; i < n; i++) {
        // arr[i] acts as the KEY. 
        // We go to that key in the map and increment its VALUE (the frequency).
        // If the key doesn't exist yet, C++ automatically creates it with a value of 0, then increments it to 1.
        mpp[arr[i]]++; 
    }
    
    int q;
    cout << "Enter no of times you want to search\n";
    cin >> q;
    
    // --- FETCHING (Processing Queries) ---
    while(q--) {
        cout << "Enter element to be searched \n";
        int num;
        cin >> num;
        
        // We look up 'num' (the KEY) to find its frequency (the VALUE)
        // This lookup happens in O(1) average time!
        cout << "Frequency is " << mpp[num] << "\n";
    }
    
    return 0;
}

/* ==============================================================================
   ==================== REVISION: EXAMPLES AND DRY RUN ==========================
   ==============================================================================
   
   WHAT ARE THE "KEY" AND "VALUE"?
   An unordered_map stores data in Key-Value pairs (like a dictionary).
   * KEY: The unique element/number from your array. Keys must be unique!
   * VALUE: The frequency count (how many times that key appeared).
   
   EXAMPLE DRY RUN:
   Assume User Inputs: 
   Array Size (n): 5
   Array Elements: {1, 2, 1, 3, 2}
   
   STEP 1: Populating the Map ( mpp[arr[i]]++ )
   Initially, map is completely empty: {}
   
   i = 0 | Element: 1 | Action: Increment value for key 1 | Map State: { 1: 1 }
   i = 1 | Element: 2 | Action: Increment value for key 2 | Map State: { 1: 1, 2: 1 }
   i = 2 | Element: 1 | Action: Increment value for key 1 | Map State: { 1: 2, 2: 1 }
   i = 3 | Element: 3 | Action: Increment value for key 3 | Map State: { 1: 2, 2: 1, 3: 1 }
   i = 4 | Element: 2 | Action: Increment value for key 2 | Map State: { 1: 2, 2: 2, 3: 1 }
   
   Final Map State:
   Key 1 has Value 2 (Appeared twice)
   Key 2 has Value 2 (Appeared twice)
   Key 3 has Value 1 (Appeared once)
   
   STEP 2: Processing Queries ( cin >> num; cout << mpp[num]; )
   Assume user wants to search q = 3 times.
   
   Query 1: User searches for 2.
   - Code executes: mpp[2]
   - Map looks up key 2, finds the value 2.
   - Output: Frequency is 2
   
   Query 2: User searches for 3.
   - Code executes: mpp[3]
   - Map looks up key 3, finds the value 1.
   - Output: Frequency is 1
   
   Query 3: User searches for 7.
   - Code executes: mpp[7]
   - Map looks up key 7. Since it was never inserted, the map returns 
     the default integer value, which is 0.
   - Output: Frequency is 0
   ============================================================================== */
   