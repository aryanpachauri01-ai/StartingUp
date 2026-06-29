#include<bits/stdc++.h>
using namespace std;

int main() {
    cout << "Enter size of array\n";
    int n;
    cin >> n;
    
    // Create an array of characters of size 'n'
    char arr[n];
    cout << "Enter Elements of Array\n";
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    
    // --- MAP DECLARATION ---
    // Syntax: unordered_map<key_type, value_type> map_name;
    // We changed the key_type to 'char' since our array holds characters.
    unordered_map<char, int> mpp;
    
    /* --- REVISION NOTES: unordered_map vs map ---
     * 1. unordered_map (Uses Hashing under the hood)
     * - Best/Average Case Time Complexity: O(1)
     * - Worst Case Time Complexity: O(N) (Happens in rare cases of severe hash collisions)
     * 2. map (Uses a Red-Black Tree under the hood)
     * - Time Complexity in ALL cases: O(log N)
     * - Elements are stored in alphabetically sorted order of their char keys.
     */
     
    // --- PRE-COMPUTATION (Populating the Map) ---
    for(int i = 0; i < n; i++) {
        // arr[i] acts as the KEY. 
        // We go to that character key in the map and increment its VALUE (the frequency).
        // If the character doesn't exist yet, it's created with a value of 0, then incremented to 1.
        mpp[arr[i]]++; 
    }
    
    int q;
    cout << "Enter no of times you want to search\n";
    cin >> q;
    
    // --- FETCHING (Processing Queries) ---
    while(q--) {
        // FIXED: Changed >> to << for cout
        cout << "Enter element to be searched \n";
        char ch;
        cin >> ch;
        
        // We look up 'ch' (the KEY) to find its frequency (the VALUE)
        // This lookup happens in O(1) average time!
        cout << "Frequency is " << mpp[ch] << "\n";
    }
    
    return 0;
}

/* ==============================================================================
   ==================== REVISION: EXAMPLES AND DRY RUN ==========================
   ==============================================================================
   
   WHAT ARE THE "KEY" AND "VALUE" HERE?
   Because we are working with an array of characters, our map types are <char, int>.
   * KEY: The unique character from your array (e.g., 'a', 'z', 'A'). Keys are strictly unique!
   * VALUE: The integer frequency count (how many times that character appeared).
   
   EXAMPLE DRY RUN:
   Assume User Inputs: 
   Array Size (n): 6
   Array Elements: {'a', 'b', 'c', 'a', 'a', 'b'}
   
   STEP 1: Populating the Map ( mpp[arr[i]]++ )
   Initially, the map is completely empty: {}
   
   i = 0 | Element: 'a' | Action: Increment value for key 'a' | Map State: { 'a': 1 }
   i = 1 | Element: 'b' | Action: Increment value for key 'b' | Map State: { 'a': 1, 'b': 1 }
   i = 2 | Element: 'c' | Action: Increment value for key 'c' | Map State: { 'a': 1, 'b': 1, 'c': 1 }
   i = 3 | Element: 'a' | Action: Increment value for key 'a' | Map State: { 'a': 2, 'b': 1, 'c': 1 }
   i = 4 | Element: 'a' | Action: Increment value for key 'a' | Map State: { 'a': 3, 'b': 1, 'c': 1 }
   i = 5 | Element: 'b' | Action: Increment value for key 'b' | Map State: { 'a': 3, 'b': 2, 'c': 1 }
   
   Final Map State:
   Key 'a' has Value 3 (Appeared three times)
   Key 'b' has Value 2 (Appeared twice)
   Key 'c' has Value 1 (Appeared once)
   
   STEP 2: Processing Queries ( cin >> ch; cout << mpp[ch]; )
   Assume user wants to search q = 3 times.
   
   Query 1: User searches for 'a'.
   - Code executes: mpp['a']
   - Map looks up key 'a', finds the value 3.
   - Output: Frequency is 3
   
   Query 2: User searches for 'c'.
   - Code executes: mpp['c']
   - Map looks up key 'c', finds the value 1.
   - Output: Frequency is 1
   
   Query 3: User searches for 'z'.
   - Code executes: mpp['z']
   - Map looks up key 'z'. Since 'z' was never inserted, the map automatically
     creates it and returns the default integer value, which is 0.
   - Output: Frequency is 0
   ============================================================================== */
   