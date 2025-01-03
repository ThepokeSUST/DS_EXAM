#include <iostream>

using namespace std;

class node
{

public:
    int data;
    node *left;
    node *right;
    node(int data)
    {
        this->data = data;
        left = right = NULL;
    }
};

node *build()
{
    int ele;
    cin >> ele;
    if (ele == -1)
        return NULL;

    node *root = new node(ele);
    root->left = build();
    root->right = build();
    return root;
}
int countNode(node *root)
{
    if (root == NULL)
        return 0;
    return 1 + countNode(root->left) + countNode(root->right);
}
bool checkindex(node *root, int idx, int size)
{
    if (root == NULL)
        return true;

    if (idx >= size)
        return false;

    if (root->left)
    {
        if (!checkindex(root->left, idx * 2 + 1, size))
            return false;
    }
    if (root->right)
    {
        if (!checkindex(root->right, idx * 2 + 2, size))
            return false;
    }
    return true;
}
bool checkNode(node *root)
{
    if (root == NULL)
        return true;

    if (root->left)
    {
        if (root->data < root->left->data)
            return false;

        if (!checkNode(root->left))
            return false;
    }
    if (root->right)
    {
        if (root->data < root->right->data)
            return false;

        return checkNode(root->right);
    }

    return true;
}

void solve()
{
    node *root = build();
    int cntnode = countNode(root);
    bool chkidx = checkindex(root, 0, cntnode);
    if (chkidx)
    {
        chkidx = checkNode(root);
    }

    cout << chkidx;
}
int main()
{
    solve();
}