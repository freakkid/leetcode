/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
 // 09/18 sulotion by nx
bool isSymmetric1 (struct TreeNode *left_node, struct TreeNode *right_node) {
    if (!left_node && !right_node)
        return true;
    if ((left_node && !right_node) ||
    (!left_node && right_node) ||
    (left_node->val != right_node->val))
        return false;
    return isSymmetric1(left_node->left, right_node->right) &&
    isSymmetric1(left_node->right, right_node->left);
}
bool isSymmetric (struct TreeNode* root) {
    if (!root)
        return true;
    return isSymmetric1(root->left, root->right);
}