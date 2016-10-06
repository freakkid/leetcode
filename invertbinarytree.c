/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
 // ac solution by nx
void invertTree(struct TreeNode *root) {
    if (!root)
        return;
    struct TreeNode *p = root->left;
    root->left = root->right;
    root->right = p;
    invertTree(root->left);
    invertTree(root->right);
}

struct TreeNode* invertTree(struct TreeNode* root) {
    struct TreeNode *p = root;
    invertTree(p);
    return p;
}

// solution1
struct TreeNode* invertTree(struct TreeNode* root) {
    if (!root)
        return NULL;
    struct TreeNode *P = root->left;
    root->left = invertTree(root->right);
    root->right = invertTree(P);
    return root; 
}

// solution2
TreeNode* invertTree (TreeNode* root) {
    if (!root)
        return NULL;
    queue<TreeNode*> Q;
    Q.push(root);
    while (!Q.empty()) {
        TreeNode* p = Q.front();
        Q.pop();
        if (!p)   // different
            continue;
        TreeNode* t = p->left;
        p->left = p->right;
        p->right = t;
        Q.push(p->left);
        Q.push(p->right);
    }
    return root;
}
// or
TreeNode* invertTree (TreeNode *root) {
    if (!root) return NULL;
    queue<TreeNode*> q;
    q.push(root);
    while (!q.empty()) {
        TreeNode *p = q.front();
        q.pop();
        TreeNode *t = p->left;
        p->left = p->right;
        p->right = t;
        if (p->left)  // here
            q.push(p->left);
        if (p->right)
            q.push(p->right);
    }
    return root;
}
