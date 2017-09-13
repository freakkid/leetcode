#include <iostream>
using namespace std;

#define MAXSIZE 30
#define TREESNUM size - head_pos    // 队列的有效长度

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x): val(x), left(NULL), right(NULL){}
};

TreeNode *queue[MAXSIZE];   // 存放结点的队列
int size = 0;               // 队列已用长度
int head_pos = 0;           // 队头的位置

// 入队
void enqueue(TreeNode *tree) {
    queue[size++] = tree;
}
// 出队
TreeNode *outqueue() {
    return queue[head_pos++];
}

// 删除值为-1的结点
void deletenullTree() {
    for (int i = 0; i < size; i++) {
        if (queue[i]->left && queue[i]->left->val == -1) {
            delete queue[i]->left;
            queue[i]->left = NULL;
        }
        if (queue[i]->right && queue[i]->right->val == -1) {
            delete queue[i]->right;
            queue[i]->right = NULL;
        }
    }
}   

// 根据输入的数字构建二叉树--用广度搜索的队列来创建二叉树
void createtree(TreeNode **treenode, int *a, int num) {
    size = head_pos = 0;
    TreeNode *tmp = new TreeNode(-1);
    enqueue(tmp);
    for (int i = 0; i < num; i++) {
        if (TREESNUM) { // 判断队列是否为空
            if (a[i] != -1) {
                TreeNode *smp = outqueue();
                smp->val = a[i];
                cout << a[i] << endl;
                smp->left = new TreeNode(-1);
                enqueue(smp->left);
                smp->right = new TreeNode(-1);
                enqueue(smp->right);
            }
            else {
                outqueue();
            }
        }
    }
    *treenode = tmp;
    deletenullTree();
}

// 前序打印出二叉树
void preTree(TreeNode *treenode) {
    if (treenode && treenode->val != -1) {
        cout << treenode->val << endl;
        preTree(treenode->left);
        preTree(treenode->right);
    }
    else {
        cout << "null" << endl;
    }
    if (treenode) {
        delete treenode;
    }
}

void copyTrees(TreeNode** t1, TreeNode* t2) {
    if (t2 && t2->val != -1) {
        *t1 = new TreeNode(t2->val);
        copyTrees(&(*t1)->left, t2->left);
        copyTrees(&(*t1)->right, t2->right);
    }
}

TreeNode* recursive_mergeTrees(TreeNode **tmp, TreeNode *t2) {
    TreeNode *t1 = *tmp;
    if (t1 && t2 && t2->val != -1) {
        t1->val += t2->val;
        recursive_mergeTrees(&(t1->left), t2->left);
        recursive_mergeTrees(&(t1->right), t2->right);
    }
    else if (!t1 && t2) {
        copyTrees(tmp, t2);
        t1 = *tmp;
    }
}

TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
    TreeNode *tmp;
    copyTrees(&tmp, t1);    // 复制t1树
    recursive_mergeTrees(&tmp, t2);
    return tmp;
}

int main() {
    // 输入一串数字，-1表示该结点不存在（null）
    int num1 = 4;
    int a1[num1] = {1, 3, 2, 5};
    TreeNode *t1;
    createtree(&t1, a1, num1);
    
    int num2 = 7;
    int a2[num2] = {2, 1, 3, -1, 4, -1, 7};
    TreeNode *t2;
    createtree(&t2, a2, num2);

    TreeNode *t3 = mergeTrees(t1, t2);  // 合并结果

    preTree(t1);
    cout << "-----------" << endl;
    preTree(t2);
    cout << "-----------" << endl;
    preTree(t3);
}