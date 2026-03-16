/*
LeetCode 138 – Copy List with Random Pointer
----------------------------------

Problem:
Each node has:
- next pointer
- random pointer (can point anywhere or NULL)

Create a deep copy of the list:
- New nodes must be independent
- Preserve both next and random structure

Return head of copied list.

--------------------------------------------------
CORE CHALLENGE
--------------------------------------------------

Random pointer breaks simple cloning.

We cannot copy node-by-node in one pass because:
- random may point to a node not yet created

So we need a mapping from original → copy.

Two optimal approaches exist.

--------------------------------------------------
APPROACH 1: HashMap (Simple & Safe)
--------------------------------------------------

Idea:
Store mapping:
original node → copied node

Steps:

1. First pass:
   Create copy of each node
   store in hashmap

2. Second pass:
   Assign:
   copy->next
   copy->random
   using hashmap lookup

Why it works:
- Hashmap guarantees O(1) access
- Every original node maps to exactly one copy

Time:  O(n)
Space: O(n)

--------------------------------------------------
CODE (HashMap)
--------------------------------------------------
class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (!head) return NULL;

        unordered_map<Node*, Node*> mp;

        // 1. Create copy nodes
        Node* curr = head;
        while (curr) {
            mp[curr] = new Node(curr->val);
            curr = curr->next;
        }

        // 2. Assign pointers
        curr = head;
        while (curr) {
            mp[curr]->next = mp[curr->next];
            mp[curr]->random = mp[curr->random];
            curr = curr->next;
        }

        return mp[head];
    }
};

--------------------------------------------------
APPROACH 2: O(1) Space Interleaving (Interview Favorite)
--------------------------------------------------

Idea:
Insert copied nodes inside original list.

We weave original and copied nodes together.

Original:
A → B → C

Becomes:
A → A' → B → B' → C → C'

Now we can assign random pointers without hashmap.

Steps:

1. Clone each node and insert next to original
2. Assign random:
   A'.random = A.random->next
3. Separate the two lists

Why it works:
- A.random->next is the copy of A.random
- Structure guarantees access

Time:  O(n)
Space: O(1)

--------------------------------------------------
VISUAL
--------------------------------------------------

Before:
A -> B -> C
|    |    |
r    r    r

After weaving:
A A' B B' C C'

Random mapping becomes trivial.

--------------------------------------------------
CODE (O(1) Space)
--------------------------------------------------
class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (!head) return NULL;

        // 1. Insert cloned nodes
        Node* curr = head;
        while (curr) {
            Node* copy = new Node(curr->val);
            copy->next = curr->next;
            curr->next = copy;
            curr = copy->next;
        }

        // 2. Assign random pointers
        curr = head;
        while (curr) {
            if (curr->random)
                curr->next->random = curr->random->next;
            curr = curr->next->next;
        }

        // 3. Separate lists
        curr = head;
        Node* dummy = new Node(0);
        Node* copyCurr = dummy;

        while (curr) {
            copyCurr->next = curr->next;
            curr->next = curr->next->next;

            curr = curr->next;
            copyCurr = copyCurr->next;
        }

        return dummy->next;
    }
};

--------------------------------------------------
INTERVIEW NOTES
--------------------------------------------------
- HashMap version is easier to explain
- O(1) version is interview gold
- Key trick: weave nodes to reuse structure
- Must preserve original list at the end

Common mistakes:
- Forgetting NULL random checks
- Breaking original list
- Losing next pointer while separating

Pattern recognition:
- Deep copy with extra pointers
- Node interleaving trick
- Structural cloning

*/
