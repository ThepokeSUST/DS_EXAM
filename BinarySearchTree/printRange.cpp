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

void inrange(node *head, int left, int right, vector<int> &vec)
{

    if (!head)
        return;

    if (head->data >= right)
    {
        inrange(head->left, left, right, vec);
    }
    else if (head->data <= left)
        inrange(head->right, left, right, vec);
    else
    {
        inrange(head->left, left, right, vec);
        vec.push_back(head->data);
        inrange(head->right, left, right, vec);
    }
}
int main()
{
    // cout << "Hello World!" << endl;
    node *root = build();
    pre(root);
    cout << endl;
    vector<int> ans;
    inrange(root, 10, 50, ans);

    for (auto ele : ans)
        cout << ele << " ";

    return 0;
}