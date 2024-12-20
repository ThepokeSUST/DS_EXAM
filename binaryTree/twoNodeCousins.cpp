#include <iostream>
#include <queue>
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

    node *head = new node(ele);

    head->left = build();
    head->right = build();

    return head;
}
void pre(node *root)
{
    if (!root)
        return;

    cout << root->data << " ";
    pre(root->left);
    pre(root->right);
}
bool findpar(node *root, int ele1, int ele2)
{
    if (!root)
        return false;

    if (!root->left || !root->right)
        return false;

    if (root->left->data == ele1 && root->right->data == ele2 || root->left->data == ele2 && root->right->data == ele1)
        return true;

    return findpar(root->left, ele1, ele2) && findpar(root->right, ele1, ele2);
}
bool chkcousins(node *root, int ele1, int ele2)
{

    int idx1 = -1;
    int idx2 = -1;

    queue<node *> q;
    int size = 1;
    int level = -1;
    q.push(root);
    while (!q.empty())
    {
        size = q.size();
        level++;

        for (int i = 0; i < size; i++)
        {
            node *ele = q.front();
            q.pop();
            if (ele->data == ele1)
                idx1 = level;
            if (ele->data == ele2)
                idx2 = level;
        }
        if (idx1 != idx2)
            return false;

        if (idx1 != -1 && idx1 == idx2)
            break;
    }

    // same level founded......
    bool smpar = findpar(root, ele1, ele2);
    return smpar;
}
int main()
{
    node *root = build();
    pre(root);
    cout << endl;
    int l, r;
    cin >> l >> r;
    cout << chkcousins(root, l, r);
}