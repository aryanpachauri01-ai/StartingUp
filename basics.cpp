#include <bits/stdc++.h>
using namespace std;

/**
 * UTILITY METHOD: printvec
 * ------------------------
 * Time Complexity: O(N) linear time to traverse and display elements.
 */
void printvec(vector<int> v) {
    cout << "Elements are -" << endl;
    
    // Quick check if vector is empty to avoid iterator errors
    if(v.empty()) {
        cout << endl;
        return;
    }
    
    auto end = v.end(); 
    for (auto it = v.begin(); it < end; it++) {
        cout << *it; // Dereferences the memory pointer 'it'
        
        // Only print the comma and space if it's NOT the last element
        if (it + 1 != end) {
            cout << ", ";
        }
    }
    cout << endl;
}

/**
 * SECTION 1: PAIRS & VECTORS
 * --------------------------
 * Complexities:
 * - Accessing elements (v[i]): O(1) [Constant time]
 * - push_back() / pop_back(): O(1) amortized
 * - insert() / erase(): O(N) [Linear time due to element shifting]
 */
void explainVector() {
    // =========================================================================
    // 1.1 PAIR UTILITIES (std::pair)
    // =========================================================================
    pair<int, int> p = {1, 3};                  // Simple pair initialization -> p = {1, 3}
    pair<int, pair<int, int>> pr = {1, {2, 3}}; // Nested pair initialization -> pr = {1, {2, 3}}
    
    cout << "pair is \n" << p.first << "," << p.second << endl; // Prints -> 1,3
    cout << "nested pair is \n" << pr.first << ", {" << pr.second.first << "," << pr.second.second << "} " << endl; // Prints -> 1, {2,3}
    
    pair<int, int> arr[] = {{1, 2}, {2, 3}, {3, 4}}; // Array of pairs -> arr[0]={1,2}, arr[1]={2,3}, arr[2]={3,4}
    cout << "array pair is " << arr[1].first << "," << arr[1].second << endl; // Accesses 2nd pair -> Prints 2,3
    
    // =========================================================================
    // 1.2 VECTOR CORE MECHANICS (std::vector)
    // =========================================================================
    vector<int> v = {1, 2, 3, 4, 5}; // State: v = {1, 2, 3, 4, 5}
    cout << "OG VECTOR V-" << endl;
    printvec(v);
    
    v.push_back(6); // Appends 6 to the end (O(1)) -> State: v = {1, 2, 3, 4, 5, 6}
    cout << "Final vector v= " << endl;
    printvec(v);
    
    vector<int> vc(5, 10); // Creates 5 elements initialized to 10 -> State: vc = {10, 10, 10, 10, 10}
    cout << "OG VECTOR VC-" << endl;
    printvec(vc);
    
    vector<int> vec(5); // Creates 5 elements value-initialized to 0 -> State: vec = {0, 0, 0, 0, 0}
    cout << "OG VECTOR VEC-" << endl;
    printvec(vec);
    
    vector<int> vect(v); // Performs a deep copy of v into vect -> State: vect = {1, 2, 3, 4, 5, 6}
    cout << "FINAL VECTOR vect = " << endl;
    printvec(vect);
    
    // =========================================================================
    // 1.3 ERASURE, INSERTION & UTILITIES
    // =========================================================================
    // Current vc state context before erase: {10, 10, 10, 10, 10}
    vc.erase(vc.begin() + 1); // Erases element at index 1 (O(N)) -> State: vc = {10, 10, 10, 10}
    cout << "Vector vc after deleting 2nd element" << endl;
    printvec(vc);
    
    // Range erasure [start, end) is exclusive of the end marker
    // Let's reset vc for clear simulation visualization: vc is {10, 10, 10, 10}
    vc.erase(vc.begin() + 1, vc.begin() + 3); // Erases indices 1 and 2 -> State: vc = {10, 10}
    cout << "Vector vc after multiple deletion" << endl;
    printvec(vc);
    
    vc.insert(vc.begin() + 1, 67); // Inserts 67 at index 1 (O(N)) -> State: vc = {10, 67, 10}
    vc.swap(v);                    // Instantly swaps v and vc internal memory pointers (O(1)) -> v is now {10, 67, 10}, vc is {1, 2, 3, 4, 5, 6}
    vc.clear();                    // Completely empties vc (O(N)) -> State: vc = {}
    bool isempty = vc.empty();     // Checks if size is 0 -> isempty = true
}

/**
 * SECTION 2: LIST STRUCTURES (std::list)
 * --------------------------------------
 * Underlying Structure: Doubly Linked List
 * Complexities:
 * - push_front() / pop_front(): O(1) [Constant time]
 * - push_back() / pop_back(): O(1) [Constant time]
 * - Arbitrary insert / erase: O(1) if iterator pointer position is already known
 * - Random access (e.g., ls[i]): Not supported natively
 */
void explainList() {
    list<int> ls; 
    
    ls.push_back(2);    // Appends 2 to tail -> State: ls = {2}
    ls.emplace_back(4); // Constructs 4 directly at tail -> State: ls = {2, 4}
    
    ls.push_front(3);    // Prepends 3 to head -> State: ls = {3, 2, 4}
    ls.emplace_front(1); // Constructs 1 directly at head -> State: ls = {1, 3, 2, 4}
}

/**
 * SECTION 3: STACK CONTAINERS (std::stack)
 * ----------------------------------------
 * Protocol: LIFO (Last In, First Out)
 * Complexities:
 * - push(), pop(), top(), size(), empty(): All operations are O(1) constant time
 */
void explainStack() {
    stack<int> st; 
    
    st.push(1); // Element order: [1] (1 is at the bottom)
    st.push(2); // Element order: [2, 1]
    st.push(3); // Element order: [3, 2, 1]
    st.push(3); // Element order: [3, 3, 2, 1]
    st.push(5); // Element order: [5, 3, 3, 2, 1] (5 is at the top)
    
    cout << st.top() << endl; // Peeks at top element -> Prints 5 
    
    st.pop();         // Removes top element 5 -> Current elements: [3, 3, 2, 1]
    cout << st.top() << endl; // Peeks at new top element -> Prints 3
    
    cout << st.size() << endl;  // Counts tracking state items -> Prints 4
    cout << st.empty() << endl; // Evaluates false since items remain -> Prints 0 (false)
    
    stack<int> s1;
    s1.push(100); // s1 state: [100]
    s1.swap(st);  // Swaps stack mappings -> s1 is now [3, 3, 2, 1], st is now [100]
}

/**
 * SECTION 4: QUEUE STRUCTURES (std::queue)
 * ----------------------------------------
 * Protocol: FIFO (First In, First Out)
 * Complexities:
 * - push(), pop(), front(), back(), size(), empty(): All operations are O(1) constant time
 */
void explainQueue() {
    queue<int> q; 
    
    q.push(1);    // State: {1} -> 1 is front
    q.push(2);    // State: {1, 2}
    q.emplace(4); // State: {1, 2, 4} -> 4 is back
    
    q.back() += 5;    // Adds 5 to back element (4 + 5 = 9) -> State: {1, 2, 9}
    cout << q.back() << endl;  // Output back element -> Prints 9
    cout << q.front() << endl; // Output front element -> Prints 1
    
    q.pop();           // Pops front element 1 -> State: {2, 9} -> 2 is now front
    cout << q.front() << endl; // Output new front element -> Prints 2
}

/**
 * SECTION 5: DEQUE CONTAINERS (std::deque)
 * ----------------------------------------
 * Protocol: Double-Ended Queue (Double-ended vector structure)
 * Complexities:
 * - push_front() / pop_front(): O(1) [Constant time]
 * - push_back() / pop_back(): O(1) [Constant time]
 * - Access via index (dq[i]): O(1) [Constant time]
 */
void explainDeque() {
    deque<int> dq; 
    
    dq.push_back(1);    // Inserts at back -> State: {1}
    dq.emplace_back(2); // Constructs at back -> State: {1, 2}
    
    dq.push_front(3);    // Inserts at front -> State: {3, 1, 2}
    dq.emplace_front(4); // Constructs at front -> State: {4, 3, 1, 2}
}

/**
 * SECTION 6: PRIORITY QUEUE (std::priority_queue)
 * -----------------------------------------------
 * Underlying Structure: Max Binary Heap / Min Binary Heap
 * Complexities:
 * - push() [Insertion]: O(log N)
 * - pop() [Removal]: O(log N)
 * - top() [Access priority element]: O(1)
 */
void explainPriorityQueue() {
    // 6.1 DEFAULT MAX HEAP (Largest elements sit at top)
    priority_queue<int> pq;
    
    pq.push(5);  // Heap internally builds -> State: {5}
    pq.push(2);  // Heap internally builds -> State: {5, 2}
    pq.push(8);  // Heap internally builds -> State: {8, 5, 2}
    pq.push(10); // Heap internally builds -> State: {10, 8, 5, 2}
    pq.push(1);  // Heap internally builds -> State: {10, 8, 5, 2, 1}
    
    cout << pq.top() << endl; // Peeks at absolute max element -> Prints 10
    
    pq.pop(); // Removes max element 10 (O(log N)) -> Top rebalances to next max -> State: {8, 5, 2, 1}
    cout << pq.top() << endl; // Prints 8
}

void explainMinPQ() {
    // 6.2 MIN HEAP SPECIFICATION (Smallest elements sit at top)
    priority_queue<int, vector<int>, greater<int>> pq; 
    
    pq.push(5);    // Heap updates -> State: {5}
    pq.push(2);    // Heap updates -> State: {2, 5}
    pq.emplace(8); // Heap updates -> State: {2, 5, 8}
    
    cout << pq.top() << endl; // Peeks at absolute min element -> Prints 2
    
    pq.pop(); // Removes min element 2 (O(log N)) -> State: {5, 8}
}

/**
 * SECTION 7: SET STRUCTURES (std::set)
 * ------------------------------------
 * Underlying Structure: Balanced Red-Black BST
 * Properties: Stores **unique** elements in strictly **sorted ascending** order.
 * Complexities:
 * - insert(), erase(), find(), count(): All take O(log N) logarithmic time
 */
void explainSet() {
    set<int> st;
    
    st.insert(1); // State: {1}
    st.insert(2); // State: {1, 2}
    st.insert(2); // Duplicate element rejected! -> State remains: {1, 2}
    st.insert(4); // State: {1, 2, 4}
    st.insert(3); // Automatically sorted upon insertion -> State: {1, 2, 3, 4}
    
    auto it = st.find(3);  // Searches for 3 -> Returns an iterator pointing to 3
    auto itt = st.find(6); // Searches for 6 -> 6 is not in set, so itt evaluates to st.end()
    cout << (itt == st.end()) << endl; // Validates if missing -> Prints 1 (true)
    
    st.erase(2); // Erases element 2 by absolute value lookup -> State: {1, 3, 4}
    int cnt = st.count(2); // Counts occurrences of value 2 -> Since 2 was erased, cnt = 0
    
    auto it1 = st.find(3); // Finds iterator location for 3
    if(it1 != st.end()) {
        st.erase(it1); // Erases element using memory iterator directly if found -> State: {1, 4}
    }
    
    // Multiple range deletion: [start, end)
    set<int> s = {1, 2, 3, 4, 5};
    auto itt1 = s.find(2); // Points to 2
    auto itt2 = s.find(4); // Points to 4
    s.erase(itt1, itt2); // Removes 2 and 3 (excludes 4) -> State: s = {1, 4, 5}
}

/**
 * SECTION 8: MULTISET CONTAINER (std::multiset)
 * --------------------------------------------
 * Properties: Stores elements in **sorted** order, but **allows duplicate values**.
 * Complexities: All core operations (insert, erase, find) take O(log N).
 */
void explainMultiset() {
    multiset<int> ms; 
    
    ms.insert(1); // State: {1}
    ms.insert(1); // State: {1, 1}
    ms.insert(1); // State: {1, 1, 1}
    
    // CRITICAL TRAP: Passing raw values to erase removes ALL matching instances!
    // ms.erase(1); // If executed here, would wipe out ALL 1s -> ms = {}
    
    multiset<int> ms1 = {1, 1, 2, 3};
    int cnt = ms1.count(1); // Counts occurrences of value 1 -> cnt = 2
    
    // WORKAROUND FOR SINGLE INSTANCE DELETION: Pass the iterator address map instead!
    ms1.erase(ms1.find(1)); // Finds first instance iterator location and erases just that one -> State: {1, 2, 3}
    
    // Range deletion: removes two instances of 1 starting from find location using next utility
    ms1.erase(ms1.find(1), next(ms1.find(1), 2)); 
}

/**
 * SECTION 9: UNORDERED SET CONTAINERS (std::unordered_set)
 * --------------------------------------------------------
 * Underlying Structure: Hash Table
 * Properties: Unique elements only, but sequence is **completely randomized / unsorted**.
 * Complexities:
 * - insert(), erase(), find(): O(1) Average Case / O(N) Worst Case (Worst case is rare hash collisions)
 * Note: lower_bound and upper_bound cannot be used because sequence is unsorted.
 */
void explainUnorderedSet() {
    unordered_set<int> st;
    st.insert(10); // Hashed into a random bucket index slot
    cout << "Unordered Set architecture initialized!" << endl;
}

/**
 * SECTION 10: MAP DICTIONARIES (std::map)
 * ----------------------------------------
 * Properties: Stores data as **Key-Value pairs** sorted ascending by **unique Keys**.
 * Complexities:
 * - operator[], insert(), find(), erase(): All run in O(log N) time
 */
void explainMap() {
    map<int, int> mpp; // Format structure mapping setup -> map<Key, Value>
    
    mpp[1] = 2;          // Assigns Value 2 to Key 1 -> Current map: {(1,2)}
    mpp.emplace((pair<int, int>){3, 1}); // Constructs Key 3 with Value 1 -> Current map: {(1,2), (3,1)}
    mpp.insert({2, 4});  // Inserts Key 2 with Value 4 -> Map sorts automatically by keys: {(1,2), (2,4), (3,1)}
    
    map<pair<int, int>, int> mpp1; 
    mpp1[{2, 3}] = 10; // Composite coordinate key {2,3} maps directly to value 10 -> Current map: {({2,3}, 10)}
    
    map<int, pair<int, int>> mpp2; 
    mpp2[1] = {1, 2}; // Key 1 maps directly to an embedded values pair struct -> Current map: {(1, {1,2})}
    
    // Loop outputs key-value relations using .first and .second syntax parameters
    for(auto it : mpp1) {
        cout << it.first.first << "," << it.first.second << " -> " << it.second << "\n"; // Prints: 2,3 -> 10
    }
    
    cout << mpp[1] << endl; // Accesses key 1 value -> Prints 2
    
    // WARNING REVISION NOTE: Brackets map lookup on missing keys automatically creates that key set to 0!
    cout << mpp[5] << endl; // Key 5 did not exist; map creates key 5 mapped to default value -> Prints 0
    
    auto it = mpp.find(3); // Locates key 3 element pair iterator address map
    if(it != mpp.end()) {
        cout << it->second << "\n"; // Accesses key-value data target via pointer arrow layout -> Prints 1
    }
}

/**
 * SECTION 11: MULTIMAP & UNORDERED MAP
 * ------------------------------------
 * MultiMap: Sorted by keys, but keys **can duplicate**. mpp[key] syntax is unavailable. Complexity: O(log N)
 * Unordered Map: Hash Table map dictionary wrapper. Keys are unique, but sequence is **unsorted**. Complexity: O(1) Avg
 */
void explainMultiMap() {
    multimap<int, int> mmp; // Can store multiple identical keys. E.g., {(1,2), (1,5), (2,3)}
    cout << "MultiMap properties documented!" << endl;
}

void explainUnorderedMap() {
    unordered_map<int, int> umpp; // Hash table implementation of map dictionaries. Random ordering.
    cout << "Unordered Map properties documented!" << endl;
}

/**
 * SECTION 12: STANDARD ALGORITHMS (std::sort, Permutations, MaxElement)
 * ---------------------------------------------------------------------
 * Complexities:
 * - sort(): O(N log N) performance speed scaling runtime
 * - next_permutation(): O(N) linear iteration
 * - max_element(): O(N) linear sweep tracking scan
 */
void explainSort() {
    // 12.1 ASCENDING ORDER SORT
    int a[] = {1, 5, 6, 3, 9, 0, 4};
    int n = sizeof(a) / sizeof(a[0]); // Dynamically evaluates element space -> n = 7 elements
    sort(a, a + n); // Sorts array values ascending -> state: a = {0, 1, 3, 4, 5, 6, 9}
    
    vector<int> v = {1, 5, 6, 3, 9, 0, 4};
    sort(v.begin(), v.end()); // Vector wrapper equivalent notation -> state: v = {0, 1, 3, 4, 5, 6, 9}
    
    // 12.2 DESCENDING ORDER SORT
    int arr[] = {1, 5, 6, 3, 9, 0, 4};
    int nn = sizeof(arr) / sizeof(arr[0]);
    // Passes functor instantiation object greater<int>() as custom comparator constraint
    sort(arr, arr + nn, greater<int>()); // Sorts array descending -> state: arr = {9, 6, 5, 4, 3, 1, 0}
}

void explainPermutation() {
    string s = "123";
    sort(s.begin(), s.end()); // REMINDER: Input container must be sorted first for lexicographical precision loop
    
    // next_permutation rearranges elements to next lexicographical state -> Prints "123", "132", "213", "231", "312", "321"
    do {
        cout << s << "\n";
    } while(next_permutation(s.begin(), s.end()));
}

void explainMaxElement() {
    int a[] = {1, 5, 6, 3, 9, 0, 4};
    int n = sizeof(a) / sizeof(a[0]);
    
    // max_element returns raw memory iterator location address; * dereferences it to fetch the actual value
    int maxele = *max_element(a, a + n); // Scans sequence and resolves max element location pointer -> maxele = 9
    cout << "Max element is: " << maxele << endl; // Prints 9
}

// =========================================================================
// RUNTIME IMPLEMENTATION EXECUTION DRIVER BLOCK
// =========================================================================
int main() {
    // High speed competitive programming optimization stream adjustments
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cout << "--- TESTING VECTOR & PAIRS ---" << endl;     explainVector();         cout << endl;
    cout << "--- TESTING LIST ---" << endl;             explainList();           cout << endl;
    cout << "--- TESTING STACK ---" << endl;            explainStack();          cout << endl;
    cout << "--- TESTING QUEUE ---" << endl;            explainQueue();          cout << endl;
    cout << "--- TESTING DEQUE ---" << endl;            explainDeque();          cout << endl;
    cout << "--- TESTING PRIORITY QUEUE ---" << endl;   explainPriorityQueue();  cout << endl;
    cout << "--- TESTING MIN PRIORITY QUEUE ---" << endl;  explainMinPQ();          cout << endl;
    cout << "--- TESTING SET ---" << endl;              explainSet();            cout << endl;
    cout << "--- TESTING MULTISET ---" << endl;         explainMultiset();       cout << endl;
    cout << "--- TESTING UNORDERED SET ---" << endl;    explainUnorderedSet();   cout << endl;
    cout << "--- TESTING MAP ---" << endl;              explainMap();            cout << endl;
    cout << "--- TESTING MULTIMAP ---" << endl;         explainMultiMap();       cout << endl;
    cout << "--- TESTING UNORDERED MAP ---" << endl;    explainUnorderedMap();   cout << endl;
    cout << "--- TESTING SORT ---" << endl;             explainSort();           cout << endl;
    cout << "--- TESTING PERMUTATION ---" << endl;      explainPermutation();    cout << endl;
    cout << "--- TESTING MAX ELEMENT ---" << endl;      explainMaxElement();     cout << endl;

    return 0;
}
