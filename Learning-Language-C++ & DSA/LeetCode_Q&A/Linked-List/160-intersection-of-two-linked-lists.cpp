/*
LeetCode 160 – Intersection of Two Linked Lists
----------------------------------

Problem:
Given two singly linked lists,
return the node where they intersect.

Intersection means:
same memory address (same node),
not same value.

If no intersection → return NULL.

--------------------------------------------------
CORE IDEA
--------------------------------------------------

If two lists intersect,
they share a common tail.

All optimal solutions enforce:

"equal remaining distance to tail"

Once aligned, walking together
forces meeting at intersection.

Let:
length A = n
length B = m

==================================================
APPROACH 1: Brute Force
==================================================

Idea:
Compare every node of A with every node of B.

Time:  O(n·m)
Space: O(1)

Only baseline thinking.

--------------------------------------------------
CODE
--------------------------------------------------
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *A, ListNode *B) {
        for (ListNode* a = A; a; a = a->next) {
            for (ListNode* b = B; b; b = b->next) {
                if (a == b) return a;
            }
        }
        return NULL;
    }
};

==================================================
APPROACH 2: Hash Set
==================================================

Idea:
Store all nodes of A in a set.
Scan B and check membership.

Time:  O(n + m)
Space: O(n)

Simple and safe.

--------------------------------------------------
CODE
--------------------------------------------------
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *A, ListNode *B) {
        unordered_set<ListNode*> seen;

        while (A) {
            seen.insert(A);
            A = A->next;
        }

        while (B) {
            if (seen.count(B)) return B;
            B = B->next;
        }

        return NULL;
    }
};

==================================================
APPROACH 3: Length Difference Alignment
==================================================

Idea:
1. Count lengths n and m
2. Advance longer list by |n-m|
3. Walk together

Time:  O(n + m)
Space: O(1)

Explicit alignment.

--------------------------------------------------
CODE
--------------------------------------------------
class Solution {
public:
    int len(ListNode* h) {
        int c = 0;
        while (h) { c++; h = h->next; }
        return c;
    }

    ListNode *getIntersectionNode(ListNode *A, ListNode *B) {
        int n = len(A), m = len(B);

        while (n > m) { A = A->next; n--; }
        while (m > n) { B = B->next; m--; }

        while (A && B) {
            if (A == B) return A;
            A = A->next;
            B = B->next;
        }

        return NULL;
    }
};

==================================================
APPROACH 4: Two-Pointer Switching (Optimal)
==================================================

Idea:
Traverse:

A → B
B → A

Both pointers travel equal distance.

If intersection exists → meet there
Else → both reach NULL

Time:  O(n + m)
Space: O(1)

Elegant implicit alignment.

--------------------------------------------------
CODE
--------------------------------------------------
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *A, ListNode *B) {
        ListNode* pA = A;
        ListNode* pB = B;

        while (pA != pB) {
            pA = (pA == NULL) ? B : pA->next;
            pB = (pB == NULL) ? A : pB->next;
        }

        return pA;
    }
};

==================================================
APPROACH 5: Cycle Reduction Trick
==================================================

Idea:
Temporarily connect tail of A to B.
If intersection exists → cycle forms.
Detect cycle start using Floyd's algorithm.

Then restore list.

Time:  O(n + m)
Space: O(1)

Advanced trick.

--------------------------------------------------
CODE
--------------------------------------------------
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *A, ListNode *B) {
        if (!A || !B) return NULL;

        // connect tail of A to B
        ListNode* tail = A;
        while (tail->next) tail = tail->next;
        tail->next = B;

        // Floyd cycle detection
        ListNode *slow = A, *fast = A;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast) break;
        }

        if (!fast || !fast->next) {
            tail->next = NULL;
            return NULL;
        }

        slow = A;
        while (slow != fast) {
            slow = slow->next;
            fast = fast->next;
        }

        tail->next = NULL;
        return slow;
    }
};

==================================================
INTERVIEW NOTES
==================================================

Best answer in interview:

Two-pointer switching (Approach 4)

Reason:
- O(1) space
- no length calculation
- elegant alignment

If asked alternatives:
mention hashing or length alignment.

Key principle:
All optimal solutions equalize
remaining distance to tail.

--------------------------------------------------
PERFORMANCE + CORRECTNESS NOTES (IMPORTANT)
--------------------------------------------------

1. Same Big-O ≠ Same Runtime
----------------------------

Even when multiple approaches are O(n),
their real runtime differs due to:

- constant factors
- memory access pattern
- CPU cache locality
- branching behavior

Observed ranking:

length alignment  < switching  < hash set  << brute force

Why?

Pointer-only methods:
- sequential traversal
- no extra allocations
- cache-friendly
- fewer CPU instructions

Hashing methods:
- hash computation
- bucket lookup
- memory indirection
- cache misses

Brute force:
O(n*m) → quadratic explosion.


Interview line:

"Algorithms with the same asymptotic complexity
can behave differently due to constant factors
and cache locality."

--------------------------------------------------

2. Intersection Definition (CRITICAL)
--------------------------------------

Intersection is based on:

    node identity (address)

NOT:

    node value

Two nodes may have equal values
but still be different memory nodes.

Correct comparison:

    if (A == B)

WRONG comparison:

    if (A->val == B->val)

Duplicates in values do NOT affect correctness.

All correct solutions compare pointers,
not values.

--------------------------------------------------

3. Structural Property of Intersection
---------------------------------------

If two lists intersect:

they share the entire suffix.

Once merged, they cannot split again
because singly linked lists cannot fork.

So intersection implies:

    common tail structure

This is why pointer alignment
and switching techniques work.

--------------------------------------------------

4. Why pointer methods are preferred
--------------------------------------

Approaches using only pointers:

- O(1) extra space
- cache-friendly
- fewer instructions
- deterministic behavior

They are both:

algorithmically optimal
AND
hardware efficient.

Hashing is valid but heavier.

--------------------------------------------------

5. Interview Summary Statement
------------------------------

"Intersection detection must compare node addresses,
not values. Pointer alignment methods are optimal
because they run in O(n) time, O(1) space, and have
better cache locality than hash-based solutions."

--------------------------------------------------

New Approach
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if (headA == NULL || headB == NULL) {
            return NULL;
        }

        ListNode* p1 = headA;
        ListNode* p2 = headB;

        while (p1 != p2) {

            if (p1 == NULL) {
                p1 = headB;
            } else {
                p1 = p1->next;
            }

            if (p2 == NULL) {
                p2 = headA;
            } else {
                p2 = p2->next;
            }
        }

        return p1;   // intersection node or NULL
    }
};
*/
