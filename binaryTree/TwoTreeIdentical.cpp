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

    if (root == NULL)
        return;

    cout << root->data << " ";
    pre(root->left);
    pre(root->right);
}

bool check(node *root1, node *root2)
{

    if (!root1 && !root2)
        return true;
    else if (!root1)
        return false;
    else if (!root2)
        return false;

    if (root1->data != root2->data)
        return false;

    return check(root1->left, root2->left) && check(root1->right, root2->right);
}

bool isIdentical(node *root1, node *root2)
{
    return check(root1, root2);
}
int main()
{
    cout << "build 1st tree\n";
    node *root1 = build();
    cout << "build 2nd tree\n";
    node *root2 = build();
    pre(root1);
    cout << endl;
    pre(root2);
    cout << endl;
    cout << isIdentical(root1, root2);
}