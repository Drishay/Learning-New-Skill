/*
LeetCode 25 – Reverse Nodes in k-Group
---------------------------------------

Problem:
Reverse nodes of a linked list k at a time.
If remaining nodes < k → leave them unchanged.

Constraints:
- Must modify nodes (not values)
- O(n) time
- O(1) extra space preferred


--------------------------------------------------
EDGE CASES CHECKLIST
--------------------------------------------------

- head == NULL
- k == 1 → no change
- list size < k → unchanged
- k == list size → full reverse
- last group < k → untouched

Always validate k-window before reversing.


--------------------------------------------------
CORE IDEA
--------------------------------------------------

Process the list in windows of size k:

prefix | k-group | suffix

For each k-group:
1. Verify k nodes exist
2. Reverse the group
3. Reconnect
4. Move prefix forward

Stop when fewer than k nodes remain.


--------------------------------------------------
APPROACH 1: Cut → Reverse → Join
--------------------------------------------------

Idea:
Isolate each k-group,
reverse using helper(),
then reconnect.

Steps per iteration:
1. Find kth node
2. Cut group
3. Reverse group
4. Reconnect to suffix
5. Move prefix

Time:  O(n)
Space: O(1)

Most intuitive approach.

--------------------------------------------------
CODE (Cut → Reverse → Join)
--------------------------------------------------
class Solution {
public:
    ListNode* reverse(ListNode* head) {
        ListNode* prev = NULL;
        while (head) {
            ListNode* next = head->next;
            head->next = prev;
            prev = head;
            head = next;
        }
        return prev;
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode dummy(0);
        dummy.next = head;
        ListNode* prev = &dummy;

        while (true) {
            // 1. Find kth node
            ListNode* kth = prev;
            for (int i = 0; i < k && kth; i++)
                kth = kth->next;

            if (!kth) break;

            // 2. Isolate group
            ListNode* groupHead = prev->next;
            ListNode* nextGroup = kth->next;
            kth->next = NULL;

            // 3. Reverse
            ListNode* newHead = reverse(groupHead);

            // 4. Reconnect
            prev->next = newHead;
            groupHead->next = nextGroup;

            // 5. Move prev
            prev = groupHead;
        }

        return dummy.next;
    }
};

--------------------------------------------------
APPROACH 2: In-place Head Insertion
--------------------------------------------------

Idea:
Reverse inside the window without cutting.

We repeatedly move the node after curr
to the front of the group.

Pointer trick:
prev -> a -> b -> c -> d

becomes:

prev -> b -> a -> c -> d
prev -> c -> b -> a -> d

Do k-1 insertions.

Time:  O(n)
Space: O(1)

More pointer-efficient.

--------------------------------------------------
CODE (Head Insertion)
--------------------------------------------------
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode dummy(0);
        dummy.next = head;
        ListNode* prev = &dummy;

        while (true) {
            // Check if k nodes exist
            ListNode* node = prev;
            for (int i = 0; i < k && node; i++)
                node = node->next;

            if (!node) break;

            ListNode* curr = prev->next;

            // Reverse k nodes
            for (int i = 1; i < k; i++) {
                ListNode* temp = curr->next;
                curr->next = temp->next;
                temp->next = prev->next;
                prev->next = temp;
            }

            prev = curr;
        }

        return dummy.next;
    }
};

--------------------------------------------------
APPROACH 3: Recursion
--------------------------------------------------

Idea:
Reverse first k nodes,
recursively process remainder.

Elegant divide-and-solve style.

Time:  O(n)
Space: O(n/k) recursion stack

--------------------------------------------------
CODE (Recursive)
--------------------------------------------------
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* node = head;

        // Check if k nodes exist
        for (int i = 0; i < k; i++) {
            if (!node) return head;
            node = node->next;
        }

        // Reverse first k
        ListNode* prev = reverseKGroup(node, k);
        ListNode* curr = head;

        for (int i = 0; i < k; i++) {
            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }

        return prev;
    }
};
--------------------------------------------------
POINTER SAFETY RULE (Universal Law)
--------------------------------------------------

Never overwrite a pointer
before saving the next reference.

Store next → mutate → reconnect.

This rule prevents pointer loss
in all linked list problems.

--------------------------------------------------
CORRECTNESS NOTES
--------------------------------------------------

- Remaining nodes < k stay unchanged
- Dummy node prevents head edge cases
- Only pointer identity matters
- No extra memory structures required

Invariant per iteration:

prefix is finalized
suffix is untouched
only k-group is mutated

--------------------------------------------------
INTERVIEW SUMMARY
--------------------------------------------------

"We process the list in k-sized windows.
For each window we verify k nodes exist,
reverse that block in-place,
reconnect it, and move forward.
This guarantees O(n) time and O(1) space."

--------------------------------------------------
PERFORMANCE INSIGHT
--------------------------------------------------

Pointer-only solutions are cache-friendly
and avoid allocation overhead.

Same asymptotic complexity,
but smaller constant factors
lead to faster real runtime.

--------------------------------------------------


--------------------------------------------------
PATTERN RECOGNITION NOTES
--------------------------------------------------

This problem is a template for:

"Process linked list in fixed-size windows"

Pattern appears in:

- reverse in k-group
- rotate list in blocks
- swap pairs (k = 2 special case)
- batch processing problems
- chunked stream processing

Whenever a problem says:

"group", "window", "batch", "k at a time"

→ think sliding window on linked list.

--------------------------------------------------

SPECIAL CASE INSIGHT
--------------------------------------------------

k = 2 reduces to:

LeetCode 24 – Swap Nodes in Pairs

So this problem is a strict generalization of pair swapping.

If you can solve 25,
you automatically understand 24.

--------------------------------------------------

INVARIANT THINKING (Advanced)
--------------------------------------------------

Each iteration preserves:

1. Processed prefix is correct
2. Remaining suffix is untouched
3. Only k-window is mutated
4. No node is lost
5. List remains connected

This invariant prevents pointer bugs.

Strong linked-list solutions are built
by maintaining invariants.

--------------------------------------------------

COMMON MISTAKES
--------------------------------------------------

- Forgetting to check k nodes exist
- Losing suffix pointer
- Not reconnecting tail properly
- Moving prev incorrectly
- Breaking head without dummy node
- Reversing last partial group

Most bugs come from pointer loss.

Rule:
Always store suffix before mutation.

--------------------------------------------------

COMPLEXITY REASONING
--------------------------------------------------

Each node is visited a constant number of times.

No nested re-traversal.

Therefore:

Time = O(n)
Space = O(1)

Even though we use loops inside loops,
total pointer moves are linear.

--------------------------------------------------

INTERVIEW LEVEL TAKEAWAY
--------------------------------------------------

This is not just a linked list problem.

It tests:

- pointer discipline
- invariant maintenance
- chunk processing
- in-place mutation
- edge case reasoning

Mastering this means you understand
advanced linked list manipulation.

--------------------------------------------------

*/
