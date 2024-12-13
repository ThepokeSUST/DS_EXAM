#include <iostream>
#include <queue>
#include <stack>
#include <vector>
using namespace std;

class node
{

public:
    int data;
    node *left;
    node *right;

    node(int val)
    {

        this->data = val;
        this->left = NULL;
        this->right = NULL;
    }
};

node *build_tree()
{

    int ele;
    cin >> ele;
    if (ele == -1)
        return NULL;

    node *newnode = new node(ele);
    newnode->left = build_tree();
    newnode->right = build_tree();

    return newnode;
}

void display(node *root)
{
    if (root == NULL)
        return;

    display(root->left);
    cout << root->data << " ";
    display(root->right);
}

vector<int> spiralTraverse(node *head)
{

    queue<node *> q;
    int n = 1;

    q.push(head);
    vector<int> vec;
    int size = 1;
    while (!q.empty())
    {
        int s = size;
        size = 0;
        while (s--)
        {
            node *ele = q.front();
            q.pop();
            vec.push_back(ele->data);
            if (ele->left)
            {
                q.push(ele->left);
                size++;
            }
            if (ele->right)
            {
                q.push(ele->right);
                size++;
            }
        }
        if (!q.empty() && n % 2 == 0)
        {
            stack<node *> st;
            while (!q.empty())
            {
                st.push(q.front());
                q.pop();
            }
            while (!st.empty())
            {
                q.push(st.top());
                st.pop();
            }
        }
        n++;
    }
    return vec;
}

int main()
{
    node *root = build_tree();
    display(root);
    cout << endl;
    vector<int> vec = spiralTraverse(root);
    for (auto ele : vec)
        cout << ele << " ";
}   