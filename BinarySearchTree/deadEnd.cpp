#include <climits>
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

void in(node *root)
{
    if (!root)
        return;

    in(root->left);
    cout << root->data << " ";
    in(root->right);
}

bool DeadEnd(node *root, int left, int right)
{

    // base case
    if (!root)
        return false;
    // leaf node for checking
    if (!root->left && !root->right)
    {
        return (root->data - left) == 1 && (right - root->data) == 1;
    }

    return DeadEnd(root->left, left, root->data) || DeadEnd(root->right, root->data, right);
}
int main()
{

    node *root = build();
    in(root);
    cout << endl;
    if (DeadEnd(root, 0, INT_MAX))
        cout << "Dead end\n";
    else
        cout << "Not Dead end\n";
}