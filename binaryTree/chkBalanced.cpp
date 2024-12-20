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

    node *temp = new node(ele);
    temp->left = build();
    temp->right = build();

    return temp;
}

void pre(node *root)
{
    if (!root)
        return;

    cout << root->data << " ";
    pre(root->left);
    pre(root->right);
}

int height(node *root, bool &chk)
{

    if (!root)
        return 0;

    int l = height(root->left, chk);
    if (chk)
    {
        int r = height(root->right, chk);

        if (abs(l - r) > 1 || abs(l - r) < 0)
        {
            chk = false;
        }

        return 1 + max(l, r);
    }
    return -1;
}

bool chkBalance(node *root)
{

    bool chk = true;
    height(root, chk);
    return chk;
}
int main()
{
    node *root = build();
    cout << chkBalance(root);
}