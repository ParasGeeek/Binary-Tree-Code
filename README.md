# Binary-TreeCode
***************************************************************************************
Lowest Common Ancestor in a Binary Tree | Set 1
Question Link:  https://practice.geeksforgeeks.org/problems/lowest-common-ancestor-in-a-binary-tree/1
***************************************************************************************
Last Updated: 22-07-2019
Given a binary tree (not a binary search tree) and two values say n1 and n2, write a program to find the least common ancestor.
Following is definition of LCA from Wikipedia:
Let T be a rooted tree. The lowest common ancestor between two nodes n1 and n2 is defined as the lowest node in T that has both n1 and n2 as descendants (where we allow a node to be a descendant of itself).

The LCA of n1 and n2 in T is the shared ancestor of n1 and n2 that is located farthest from the root. Computation of lowest common ancestors may be useful, for instance, as part of a procedure for determining the distance between pairs of nodes in a tree: the distance from n1 to n2 can be computed as the distance from the root to n1, plus the distance from the root to n2, minus twice the distance from the root to their lowest common ancestor. (Source Wiki)

lca
We have discussed an efficient solution to find LCA in Binary Search Tree. In Binary Search Tree, using BST properties, we can find LCA in O(h) time where h is height of tree. Such an implementation is not possible in Binary Tree as keys Binary Tree nodes don’t follow any order. Following are different approaches to find LCA in Binary Tree.

Method 1 (By Storing root to n1 and root to n2 paths):
Following is simple O(n) algorithm to find LCA of n1 and n2.
1) Find path from root to n1 and store it in a vector or array.
2) Find path from root to n2 and store it in another vector or array.
3) Traverse both paths till the values in arrays are same. Return the common element just before the mismatch.

Method 2 (Using Single Traversal)
The method 1 finds LCA in O(n) time, but requires three tree traversals plus extra spaces for path arrays. If we assume that the keys n1 and n2 are present in Binary Tree, we can find LCA using single traversal of Binary Tree and without extra storage for path arrays.
The idea is to traverse the tree starting from root. If any of the given keys (n1 and n2) matches with root, then root is LCA (assuming that both keys are present). If root doesn’t match with any of the keys, we recur for left and right subtree. The node which has one key present in its left subtree and the other key present in right subtree is the LCA. If both keys lie in left subtree, then left subtree has LCA also, otherwise LCA lies in right subtree.
**********************************************************************************************************





***************New Question and link of question, url: https://practice.geeksforgeeks.org/problems/lowest-common-ancestor-in-a-bst/1
Question2: Lowest Common Ancestor in a Binary Search Tree
Given a Binary Search Tree (with all values unique) and two node values. Find the Lowest Common Ancestors of the two nodes in the BST.
Input:
S = 5 4 6 3 N N 7 N N N 8
n1 = 7, n2 = 8
Output: 7
Explanation:The BST in above test case
will look like
              5
          /      \ 
        4         6
     /   \     /      \
   3      N    N       7
 /    \              /    \ 
N      N             N     8
Here, the LCA of 7 and 8 is 7.
Example 2:

Input:
S = 2 1 3
n1 = 1, n2 = 3
Output: 2
Explanation:For the given above test case
the BST will be
                    2
                 /    \
                1      3
Here, the LCA of 1 and 3 will be 2
Your Task:
You don't need to read input or print anything. Your task is to complete the function LCA() which takes the root Node of the BST and two integer values n1 and n2 as inputs and returns the Lowest Common Ancestor of the Nodes with values n1 and n2 in the given BST. 

Expected Time Complexity: O(Height of the BST).
Expected Auxiliary Space: O(Height of the BST).

Constraints:
1 <= N <= 104
** For More Input/Output Examples Use 'Expected Output' option **

