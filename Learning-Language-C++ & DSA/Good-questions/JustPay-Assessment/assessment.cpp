/************************************************************
1. Parcel Delivery Optimization

Background:
Mike is a logistics manager at a parcel delivery company.
There are n delivery stops, each initially assigned a number
of parcels represented by an array p.

The company allows Mike to choose exactly one permutation
q1, q2, ..., qn of numbers from 1 to n.

He modifies parcels as:
    p[i] = p[i] + q[i]

After applying the permutation, Mike wants to maximize
the number of stops that have the same number of parcels.

Input:
- n : integer (number of delivery stops)
- p : array of n integers (initial parcel counts)

Output:
- Return an integer representing the maximum number of
  stops that can have equal parcel count after applying
  exactly one permutation.

Constraints:
- 1 ≤ n ≤ 2 × 10^5
- 1 ≤ p[i] ≤ 10^9
- q is a permutation of 1 to n
************************************************************/



/************************************************************
2. Internet Service Provider Cable Management

Background:
An Internet Service Provider (ISP) has built a network
of cables structured as a tree, with a central hub at root R.

Each cable has a bandwidth cost.

You must process two types of queries:

1) Bandwidth Cost Query:
   Calculate the total bandwidth cost between
   two customers A and B.

2) Cost Update Query:
   Update the bandwidth cost of a cable
   connecting U and V to a new value W.

Input:
- N : number of customers
- R : root node (central hub)
- M = N - 1
- Next M lines: U V W (edge with bandwidth cost W)
- Q : number of queries
- Next Q lines:
    1 A B 0  -> calculate cost between A and B
    2 U V W  -> update edge (U,V) to cost W

Output:
- Return the sum of all bandwidth cost query results.

Constraints:
- 1 ≤ N ≤ 10^5
- 1 ≤ Q ≤ 10^5
- 1 ≤ edge weights ≤ 10^5
- The given edges form a tree.
************************************************************/


/************************************************************
3. Network Technician's Mission

Background:
Sam is inspecting a communication network structured
as a tree rooted at node 1.

Each node (tower) is either:
    0 -> Safe
    1 -> Dangerous

The outermost towers (leaf nodes) need inspection.
However, Sam refuses to travel through more than M
consecutive dangerous nodes.

Task:
Count how many leaf nodes can be safely inspected,
such that the path from node 1 to that leaf contains
at most M consecutive dangerous nodes.

Input:
- N : number of nodes
- M : maximum allowed consecutive dangerous nodes
- Arr1 : array of size N (0 or 1 for each node)
- Arr2 : N-1 edges forming a tree

Output:
- Return the number of valid leaf nodes.

Constraints:
- 2 ≤ N ≤ 10^5
- 1 ≤ M ≤ N
- The edges form a valid tree structure.
************************************************************/