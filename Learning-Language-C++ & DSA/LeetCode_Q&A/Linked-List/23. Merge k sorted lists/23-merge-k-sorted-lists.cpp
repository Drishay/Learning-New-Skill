/*
LeetCode 23 – Merge k Sorted Lists
----------------------------------

Problem:
Merge k sorted linked lists into one sorted linked list
and return its head.

Each list is sorted in ascending order.

--------------------------------------------------
CORE IDEA
--------------------------------------------------

This is a generalization of:
"Merge 2 sorted lists"

We must repeatedly choose the smallest
current node among k lists.

Key pattern:
k-way merge

Total nodes = N
Number of lists = k

==================================================
APPROACH 1: Dump into Array → Sort → Rebuild
==================================================

Idea:
Ignore list structure.
Collect values → sort → rebuild.

Steps:
1. Traverse all lists and collect values in array
2. Sort the array
3. Build new linked list from sorted values

Time:  O(N log N)
Space: O(N)

Simple baseline solution.
Not pointer-optimal but easy to implement.

--------------------------------------------------
CODE
--------------------------------------------------
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        vector<int> vals;

        // 1. Collect values
        for (auto list : lists) {
            while (list) {
                vals.push_back(list->val);
                list = list->next;
            }
        }

        if (vals.empty()) return nullptr;

        // 2. Sort
        sort(vals.begin(), vals.end());

        // 3. Rebuild list
        ListNode* head = new ListNode(vals[0]);
        ListNode* curr = head;

        for (int i = 1; i < vals.size(); i++) {
            curr->next = new ListNode(vals[i]);
            curr = curr->next;
        }

        return head;
    }
};

==================================================
APPROACH 2: Sequential Merge (Naive)
==================================================

Idea:
Merge lists one-by-one using mergeTwo()

result = merge(list1, list2)
result = merge(result, list3)
...

Time:  O(kN)
Space: O(1)

Weak when k is large because
result keeps growing each merge.

--------------------------------------------------
CODE
--------------------------------------------------
class Solution {
public:
    ListNode* mergeTwo(ListNode* a, ListNode* b) {
        ListNode dummy(0);
        ListNode* tail = &dummy;

        while (a && b) {
            if (a->val < b->val) {
                tail->next = a;
                a = a->next;
            } else {
                tail->next = b;
                b = b->next;
            }
            tail = tail->next;
        }

        tail->next = a ? a : b;
        return dummy.next;
    }

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode* result = NULL;

        for (auto list : lists)
            result = mergeTwo(result, list);

        return result;
    }
};

==================================================
APPROACH 3: Min Heap / Priority Queue (Optimal)
==================================================

Idea:
At any moment, the smallest node must be
among the k list heads.

Use a min heap to always pick the smallest.

Steps:
1. Push first node of each list into heap
2. Pop smallest node
3. Add to result
4. Push its next node
5. Repeat

Time:  O(N log k)
Space: O(k)

Most practical interview solution.

--------------------------------------------------
CODE
--------------------------------------------------
class Solution {
public:
    struct cmp {
        bool operator()(ListNode* a, ListNode* b) {
            return a->val > b->val; // min heap
        }
    };

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*, vector<ListNode*>, cmp> pq;

        for (auto node : lists)
            if (node) pq.push(node);

        ListNode dummy(0);
        ListNode* tail = &dummy;

        while (!pq.empty()) {
            ListNode* node = pq.top();
            pq.pop();

            tail->next = node;
            tail = tail->next;

            if (node->next)
                pq.push(node->next);
        }

        return dummy.next;
    }
};

==================================================
APPROACH 4: Divide & Conquer (Merge Sort Style)
==================================================

Idea:
Pair lists and merge recursively.

Same idea as merge sort.
Number of lists halves each level.

Time:  O(N log k)
Space: O(log k) recursion stack

Elegant alternative to heap.

--------------------------------------------------
CODE
--------------------------------------------------
class Solution {
public:
    ListNode* mergeTwo(ListNode* a, ListNode* b) {
        ListNode dummy(0);
        ListNode* tail = &dummy;

        while (a && b) {
            if (a->val < b->val) {
                tail->next = a;
                a = a->next;
            } else {
                tail->next = b;
                b = b->next;
            }
            tail = tail->next;
        }

        tail->next = a ? a : b;
        return dummy.next;
    }

    ListNode* divide(vector<ListNode*>& lists, int l, int r) {
        if (l > r) return NULL;
        if (l == r) return lists[l];

        int mid = (l + r) / 2;

        ListNode* left = divide(lists, l, mid);
        ListNode* right = divide(lists, mid + 1, r);

        return mergeTwo(left, right);
    }

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.empty()) return NULL;
        return divide(lists, 0, lists.size() - 1);
    }
};

==================================================
INTERVIEW NOTES
==================================================

If interviewer asks approaches:

1. Array + sort → O(N log N)
2. Sequential merge → O(kN)
3. Heap → O(N log k)
4. Divide & conquer → O(N log k)

Heap = most practical
Divide & conquer = elegant

Pattern reuse:
- Merge k arrays
- External sorting
- Stream merging
- Top k elements
- Dijkstra / priority queue problems

Key takeaway:
When choosing smallest among k candidates
→ think heap.

==================================================
PERFORMANCE INSIGHT (Important)
==================================================

Why sequential merge is slow:

Sequential merging repeatedly re-scans
a growing list.

Work pattern:

(((L1 + L2) + L3) + ... + Lk)

Each step merges a larger result,
leading to total work ≈ O(kN).

This is mathematically more work
than heap/divide & conquer.

--------------------------------------------------

Why heap and divide & conquer are fast:

Both balance the merging work.

Each node is processed log(k) times
instead of k times.

Time complexity:
O(N log k)

Divide & conquer often runs faster
in practice because:

- No heap maintenance overhead
- Fewer instructions
- Better constant factors

--------------------------------------------------

Asymptotics vs Cache Locality

Array sorting (idea 1) can still run fast
despite worse big-O:

- Arrays are cache-friendly
- Linked lists cause pointer chasing
- Modern CPUs favor contiguous memory

This is a real-world example where
hardware behavior affects performance.

--------------------------------------------------

INTERVIEW EXPLANATION

If asked:

"Why is sequential merge slower?"

Answer:

Sequential merge reprocesses large lists
repeatedly, leading to O(kN) work.
Heap and divide & conquer balance the merges,
achieving O(N log k). Divide & conquer
has better constant factors since it avoids
heap overhead.

This shows understanding of:

- asymptotic complexity
- constant factors
- memory/cache behavior

Senior-level reasoning.
==================================================


*/
