/*
Poisoned Barrel Problem
-----------------------

Given:
- N barrels
- Exactly 1 poisoned
- Poison acts in 24 hours
- One round of testing

Goal:
Find poisoned barrel using minimum waiters.

Key Idea:
If K waiters are used:
    2^K >= N

Minimum waiters:
    K = ceil(log2(N))

Each waiter represents one bit.
Dead = 1
Alive = 0
*/

#include <iostream>
#include <vector>
#include <cmath>
#include <bitset>
using namespace std;

// --------------------------------------------------
// Helper: Compute minimum waiters required
// --------------------------------------------------
int minimumWaiters(int barrels)
{
    return ceil(log2(barrels));
}

// --------------------------------------------------
// APPROACH 1: Brute Force (Store + Search)
// --------------------------------------------------
int bruteForceSolution(int N, int K, vector<int> waiterState)
{

    vector<string> patterns;

    // Store binary patterns for each barrel
    for (int i = 0; i < N; i++)
    {
        bitset<32> b(i); // supports up to 32 bits
        string binary = b.to_string();
        patterns.push_back(binary.substr(32 - K)); // take last K bits
    }

    // Build observed pattern
    string observed = "";
    for (int i = 0; i < K; i++)
        observed += to_string(waiterState[i]);

    // Search
    for (int i = 0; i < N; i++)
    {
        if (patterns[i] == observed)
            return i;
    }

    return -1;
}

// --------------------------------------------------
// APPROACH 2: Optimized Bit Decoding (O(1))
// --------------------------------------------------
int optimizedSolution(int K, vector<int> waiterState)
{

    int poisoned_barrel = 0;

    for (int i = 0; i < K; i++)
    {
        poisoned_barrel |= (waiterState[i] << (K - 1 - i));
    }
    /*
    The optimized loop: poisoned_barrel |= (waiterState[i] << (K - 1 - i)); is literally building a binary number bit by bit. 
    It’s equivalent to: ∑waiterState[i]×2^position, This is how CPUs assemble integers internally.
    */
    return poisoned_barrel;
}

// --------------------------------------------------
// MAIN
// --------------------------------------------------
int main()
{

    int N;
    cout << "Enter number of barrels: ";
    cin >> N;

    int K = minimumWaiters(N);

    cout << "Minimum waiters required: " << K << endl;

    cout << "\nEnter waiter states (0 = alive, 1 = dead)\n";
    cout << "Enter " << K << " values separated by space:\n";

    vector<int> waiterState(K);

    for (int i = 0; i < K; i++)
        cin >> waiterState[i];

    // Brute Force
    int result1 = bruteForceSolution(N, K, waiterState);
    cout << "\nBrute Force Result: " << result1 << endl;

    // Optimized
    int result2 = optimizedSolution(K, waiterState);
    cout << "Optimized Result: " << result2 << endl;

    return 0;
}
