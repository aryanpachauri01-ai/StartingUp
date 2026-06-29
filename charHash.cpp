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
    
    // --- HASH ARRAY DECLARATION ---
    // Why size 256? There are exactly 256 characters in the extended ASCII table.
    // So, indices 0 to 255 will safely cover every possible character input.
    // VERY IMPORTANT: = {0} initializes all 256 elements to zero.
    int hash[256] = {0};
    
    /* --- REVISION NOTES: Array vs unordered_map ---
     * 1. Frequency Array (int hash[256])
     * - Time Complexity: O(1) strictly for BOTH fetching and insertion.
     * - Space Complexity: O(1) because the size (256) is fixed and independent of 'n'.
     * - Best used when the range of possible inputs is small and known (like characters).
     */
     
    // --- PRE-COMPUTATION (Populating the Frequency Array) ---
    for(int i = 0; i < n; i++) {
        // HOW DOES THIS WORK?
        // arr[i] is a character. In C++, characters are stored as ASCII integers behind the scenes.
        // E.g., 'a' is 97, 'A' is 65.
        // Writing hash[arr[i]]++ is effectively writing hash[97]++.
        // We use the character's ASCII value as the direct index (KEY) and increment its VALUE.
        hash[arr[i]]++; 
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
        
        // We look up the character 'ch'. Its ASCII integer value maps directly to the array index!
        // This lookup happens in strictly O(1) time.
        cout << "Frequency is " << hash[ch] << "\n";
    }
    
    return 0;
}

/* ==============================================================================
   ==================== REVISION: EXAMPLES AND DRY RUN ==========================
   ==============================================================================
   
   WHAT ARE THE "KEY" AND "VALUE" HERE?
   Unlike an unordered_map where the system maps keys dynamically, here we use
   the structure of an array combined with ASCII integer values.
   
   * KEY: The Array Index! (Specifically, the ASCII value of the character).
          For example, the key for 'a' is the index 97.
   * VALUE: The integer stored at that specific index (the frequency count).
   
   EXAMPLE DRY RUN:
   Assume User Inputs: 
   Array Size (n): 5
   Array Elements: {'a', 'b', 'A', 'a', 'b'}
   
   STEP 1: Populating the Array ( hash[arr[i]]++ )
   Initially, hash array is fully zeros: {0, 0, 0, ..., 0} (256 items)
   
   i = 0 | Element: 'a' (ASCII 97) | Action: hash[97]++ | State: index 97 has value 1
   i = 1 | Element: 'b' (ASCII 98) | Action: hash[98]++ | State: index 98 has value 1
   i = 2 | Element: 'A' (ASCII 65) | Action: hash[65]++ | State: index 65 has value 1
   i = 3 | Element: 'a' (ASCII 97) | Action: hash[97]++ | State: index 97 has value 2
   i = 4 | Element: 'b' (ASCII 98) | Action: hash[98]++ | State: index 98 has value 2
   
   Final Array State (showing only non-zero values):
   Index 65 ('A') has Value 1
   Index 97 ('a') has Value 2
   Index 98 ('b') has Value 2
   
   STEP 2: Processing Queries ( cin >> ch; cout << hash[ch]; )
   Assume user wants to search q = 3 times.
   
   Query 1: User searches for 'a'.
   - Code executes: hash['a'] -> which evaluates to hash[97]
   - Array looks at index 97, finds the value 2.
   - Output: Frequency is 2
   
   Query 2: User searches for 'A'.
   - Code executes: hash['A'] -> which evaluates to hash[65]
   - Array looks at index 65, finds the value 1.
   - Output: Frequency is 1
   
   Query 3: User searches for 'z'.
   - Code executes: hash['z'] -> which evaluates to hash[122]
   - 'z' was never in the array. Since we initialized the array with {0}, 
     index 122 contains the value 0.
   - Output: Frequency is 0
   ============================================================================== */
   