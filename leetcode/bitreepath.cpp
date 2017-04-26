/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
// solution 
class Solution {
public:
    void bitreepath (TreeNode *root, vector<string> &result, string str_path) {
        str_path += to_string(root->val);
        if (!root->left && !root->right) {
             result.push_back(str_path);
             return;
        }
        if (root->left)
            bitreepath(root->left, result, str_path + "->");
        if (root->right)
            bitreepath(root->right, result, str_path + "->");
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> result;
        if (root)
            bitreepath(root, result, "");
        
        return result;
    }
};
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
// solution 
class Solution {
public:
    void bitreepath (TreeNode *root, vector<string> &result, string str_path) {
        if (!root->left && !root->right) {
             result.push_back(str_path);
             return;
        }
        if (root->left)
            bitreepath(root->left, result, str_path + "->" + to_string(root->left->val));
        if (root->right)
            bitreepath(root->right, result, str_path + "->" + to_string(root->right->val));
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> result;
        if (root)
            bitreepath(root, result, to_string(root->val));
        
        return result;
    }
};