int minDepth (struct TreeNode* root) {
    if (!root)
        return 0;
    int l = minDepth(root->left);
    int r = minDepth(root->right);
    return 1 + (l < r ? l : r);
}
int minDepth (TreeNode *root) {
    if (!root)
        return 0;
    int depth = 1;
    Queue<TreeNode *> Q;
    Q.push(root);
    while (!Q.empty()) {
        TreeNode *cur = Q.front();
        int curdepth = depth;
        Q.pop();
        if (!cur->left && !cur->right)
            return curdepth;
        if (cur->left) {
            Q.push(cur);
            ++curdepth;
        }
        if (cur->right) {
            Q.push(cur);
            ++curdepth;
        }
        if (depth < curdepth)
            depth = curdepth;
    }
}
