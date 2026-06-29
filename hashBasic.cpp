#include<bits/stdc++.h>
using namespace std; 

int main()
{
  int n, lar;
  cout << "Enter size of array and max element\n";
  cin >> n;
  cin >> lar;
  
  int arr[n];
  cout << "Enter elements\n";
  for(int i = 0; i < n; i++)
  {
    cin >> arr[i];
  }
  
  // =====================================================================
  // 1. HASH ARRAY DECLARATION
  // =====================================================================
  // Why 'lar + 1'? 
  // Arrays in C++ are 0-indexed. If the largest number we want to store 
  // is 5, we need indices 0, 1, 2, 3, 4, and 5. That is a total of 6 
  // slots. Therefore, we need an array of size 'lar + 1'.
  //
  // Why '= {0}'? 
  // By default, C++ might fill an array with random "garbage" data from 
  // memory. Since we are counting, we MUST start at exactly 0. This 
  // initializes every single slot in the hash array to 0.
  
  int hash[lar+1] = {0}; 

  // =====================================================================
  // 2. FILLING THE HASH ARRAY (The "Adding +1" Logic)
  // =====================================================================
  // We loop through the original array exactly once.
  for(int i = 0; i < n; i++) 
  {
    // WHY DO WE ADD 1? (The Tally Counter Concept)
    // Think of the 'hash' array as a row of empty buckets. 
    // Every time we encounter a number in our input array 'arr', we walk 
    // over to the bucket labeled with that number and drop exactly 1 
    // token into it to keep count.
    //
    // hash[arr[i]]  --> Finds the specific bucket labeled with the number.
    // += 1          --> Drops 1 token into that bucket.
    //
    // STEP-BY-STEP EXAMPLE: 
    // Let's say your input array is: arr = {4, 2, 4}
    //
    // i = 0: arr[0] is 4. -> We do hash[4] += 1. (Bucket #4: 0 -> 1)
    // i = 1: arr[1] is 2. -> We do hash[2] += 1. (Bucket #2: 0 -> 1)
    // i = 2: arr[2] is 4. -> We do hash[4] += 1. (Bucket #4: 1 -> 2)
    //
    // By the end of this loop, the number sitting inside each bucket 
    // perfectly matches how many times that number appeared in the input.
    
    hash[arr[i]] += 1;
  }
  
  cout << "Enter no. of elements you want to search \n";
  int srch;
  cin >> srch;
  
  while(srch > 0)
  {
    srch--;
    cout << "Entry element to be searched\n";
    int num;
    cin >> num;
    cout << "Frequency is " << hash[num] << "\n";
  }
  
  return 0;
}

/*
=====================================================================
3. EXAMPLE RUN OF THE PROGRAM
=====================================================================

--- INPUT GIVEN IN TERMINAL ---
Enter size of array and max element
6 5
Enter elements
1 5 2 1 5 1
Enter no. of elements you want to search 
3
Entry element to be searched
1
Entry element to be searched
5
Entry element to be searched
3

--- EXPECTED OUTPUT IN TERMINAL ---
Frequency is 3
Frequency is 2
Frequency is 0

Explanation: 
The number '1' appeared 3 times.
The number '5' appeared 2 times.
The number '3' did not appear at all (bucket remained at 0).
=====================================================================
*/
