#include <climits>
#include <iostream>
#include <map>
#include <stack>
#include <vector>
using namespace std;
class node
{

public:
    int data;
    node *left;
    node *right;

    node(int ele)
    {
        data = ele;
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

void pre(node *head)
{
    if (!head)
        return;

    cout << head->data << " ";
    pre(head->left);
    pre(head->right);
}

bool chkbst(node *head, int lowest, int highest)
{
    if (head == NULL)
        return true;

    if (head->data > highest || head->data < lowest)
        return false;

    // if(!chkbst(head->left,lowest,head->data)) return flase;
    return chkbst(head->left, lowest, head->data) && chkbst(head->right, head->data, highest);
}
int main()
{

    node *root = build();
    pre(root);
    cout << chkbst(root, INT_MIN, INT_MAX);
}