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

void mirror(node *root)
{
    if (!root)
        return;

    node *temp = root->left;
    root->left = root->right;
    root->right = temp;
    mirror(root->left);
    mirror(root->right);
}
void pre(node *root)
{
    if (!root)
        return;

    cout << root->data << " ";
    pre(root->left);
    pre(root->right);
}
int main()
{
    node *root = build();
    pre(root);
    mirror(root);
    cout << endl;
    pre(root);
}