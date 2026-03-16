/*
LeetCode 114 – Flatten Binary Tree to Linked List
--------------------------------------------------

Problem:
Flatten a binary tree to a linked list in-place.

The linked list must follow preorder traversal:

root → left → right

Constraints:
- Must modify tree in-place
- Use right pointers as next
- left pointers must become NULL

--------------------------------------------------
CORE IDEA
--------------------------------------------------

For every node:

1. Flatten left subtree
2. Flatten right subtree
3. Insert left subtree between root and right subtree

We are rewiring pointers to simulate preorder.

Final structure:
root → left chain → right chain

--------------------------------------------------
APPROACH 1: Recursive Rewiring (Sir’s Logic)
--------------------------------------------------

Idea:
Process children first,
then stitch subtrees into preorder shape.

Steps per node:
1. Flatten left subtree
2. Flatten right subtree
3. Save original right subtree
4. Move left subtree to right
5. Traverse to end of new right chain
6. Attach saved right subtree

Time:  O(n)
Space: O(h) recursion stack (h = height)

--------------------------------------------------
CODE (Recursive)
--------------------------------------------------
class Solution {
public:
    void flatten(TreeNode* root) {
        if (!root) return;

        // 1. Flatten subtrees
        flatten(root->left);
        flatten(root->right);

        // 2. Save right subtree
        TreeNode* rightSubtree = root->right;

        // 3. Move left subtree to right
        root->right = root->left;
        root->left = NULL;

        // 4. Go to tail of new right chain
        TreeNode* curr = root;
        while (curr->right)
            curr = curr->right;

        // 5. Attach original right subtree
        curr->right = rightSubtree;
    }
};

--------------------------------------------------
APPROACH 2: Morris Traversal (O(1) Space)
--------------------------------------------------

Idea:
Preorder-style pointer rewiring without recursion.

For each node:
If left subtree exists:
  - Find rightmost node of left subtree
  - Connect it to current right subtree
  - Move left subtree to right
  - Null left pointer

This mimics threaded traversal.

Time:  O(n)
Space: O(1)

No recursion.
No stack.

--------------------------------------------------
CODE (Morris Style)
--------------------------------------------------
class Solution {
public:
    void flatten(TreeNode* root) {
        TreeNode* curr = root;

        while (curr) {
            if (curr->left) {
                TreeNode* pred = curr->left;

                // find rightmost node of left subtree
                while (pred->right)
                    pred = pred->right;

                // rewire
                pred->right = curr->right;
                curr->right = curr->left;
                curr->left = NULL;
            }
            curr = curr->right;
        }
    }
};

--------------------------------------------------
WHY RESULT IS PREORDER
--------------------------------------------------

Even though recursion processes children first,
the final stitching guarantees:

root → left → right

Each subtree is already flattened in preorder.
We simply concatenate:

root + left + right

Final linked list = preorder traversal.

--------------------------------------------------
CORRECTNESS INVARIANT
--------------------------------------------------

At every node:

- left subtree already flattened
- right subtree already flattened
- no node is lost
- structure remains connected
- only pointer rewiring happens

This invariant prevents tree corruption.

--------------------------------------------------
EDGE CASES
--------------------------------------------------

- Empty tree → return immediately
- Single node → already flat
- Only left children → becomes straight chain
- Only right children → unchanged
- Skewed tree → still O(n)

--------------------------------------------------
COMPLEXITY REASONING
--------------------------------------------------

Each node is visited a constant number of times.

Even though we scan to the right tail,
total work across all nodes is linear.

Time  = O(n)
Space = O(h) recursion / O(1) Morris

--------------------------------------------------
INTERVIEW SUMMARY
--------------------------------------------------

“We flatten using preorder structure.
At each node we insert the left subtree
between root and right subtree.
Recursive version uses stack space,
Morris version achieves O(1) extra space
through pointer threading.”

--------------------------------------------------
PATTERN RECOGNITION
--------------------------------------------------

This problem teaches:

- pointer rewiring
- preorder simulation
- tree → linked list transformation
- in-place structure mutation
- Morris traversal technique

Same idea appears in:

- threaded binary trees
- tree serialization
- in-place traversal problems

--------------------------------------------------
INTERVIEW TAKEAWAY
--------------------------------------------------

Flatten is not traversal printing —
it’s structural transformation.

We are building preorder as a linked list
by preserving pointer identity.

Mastering this means strong control
over tree pointer manipulation.

--------------------------------------------------
*/
