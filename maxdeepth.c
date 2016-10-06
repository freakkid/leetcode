/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
 // c sulotion by nx(WA)
static int depth = 0;
void maxDepthHelp(struct TreeNode *root, int d) {
    if (!root)
        return;
    if (d > depth)
        depth = d;
    maxDepthHelp(root->left, d + 1);
    maxDepthHelp(root->right, d + 1);
}
int maxDepth(struct TreeNode* root) {
    maxDepthHelp(root, 1);
    return depth;
}
// c++ sulotion1 
class Solution {
public:
    int maxDepth(TreeNode* root) {
        maxDepthHelp(root, 1);
        return depth;
    }
private:
    int depth = 0;
    void maxDepthHelp(struct TreeNode *root, int d) {
        if (!root)
            return;
        if (d > depth)
            depth = d;
        maxDepthHelp(root->left, d + 1);
        maxDepthHelp(root->right, d + 1);
    }
};

// c++ solution2
class Solution {
public:
    int maxDepth (TreeNode *root) {
        if (!root)
            return 0;
        return max(maxDepth(root->left), maxDepth(root->right)) + 1;
    }
}

// c sulotion1 by nx(AC)
int max_depth (int a, int b){
    return a > b ? a : b;
}
int maxDepth (struct TreeNode* root) {
    if (!root)
        return;
    return max_depth(maxDepth(root->left), maxDepth(root->right)) + 1;   
}

// c sulotion2 by nx
int maxDepth (struct TreeNode* root) {
    if (!root)
        return 0;
    int leftdepth = maxDepth(root->left);
    int rightdepth = maxDepth(root->right);
    return (leftdepth > rightdepth ? leftdepth : rightdepth) + 1;   
}
// c solution3 ?
int maxDepth (struct TreeNode* root) {
    if (!root) return 0;
    queue <TreeNode*> que;
    int nCount = 1;
    int nDepth = 0;

    que.push(root);
    while (!que.empty()) {
        TreeNode *pTemp = que.front();
        que.pop();
        --nCount;

        if (pTemp->left)
            que.push(pTemp->left);
        if (pTemp->right)
            que.push(pTemp->right);
        if (nCount == 0) {
            ++nDepth;
            nCount = que.size();
        }
    }
    return nDepth;
}

// c++ sulotion4 by nx(AC)
int maxDepth (TreeNode *root) {
    if (!root)
        return 0;
    int depth = 0;
    queue<TreeNode *> Q;
    Q.push(root);
    Q.push(NULL);// at the end of every row 
    while (!Q.empty()) {
        TreeNode *p = Q.front();
        Q.pop();
        if (p) {
            if (p->left)
                Q.push(p->left);
            if (p->right)
                Q.push(p->right);
        }
        else {
            ++depth;
            if (!Q.empty())
                Q.push(NULL);
        }
    }
    return depth;
}

// c++ sulotion5 
int maxDepth(TreeNode *root) {
    if (!root)
        return 0;
    int depth = 0;
    stack S;
    S.push(root);
    TreeNode *prev = NULL;
    while (!S.empty()) {
        TreeNode *curr = S.top();

        if (prev == NULL || prev->left == curr || prev->right == curr) {
            if (curr->left)
                S.push(curr->left);
            else if (curr->right)
                S.push(curr->right);
        } else if (curr->left == prev) {
            if (curr->right)
                S.push(curr->right);
        } else {
            S.pop();
        }
        pre = curr;
        if (S.size() > depth)
            depth = S.size();
    }
    return depth;
}