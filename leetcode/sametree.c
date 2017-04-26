/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
bool isSameTree(struct TreeNode* p, struct TreeNode* q) {
    // if both are NULL 
    if ((!p && !q))
        return true;
    // if is different in structure or value
    if ((!p && q) || (p && !q) || (p->val != q->val))
        return false;
    return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
}