#include <climits>
#include <iostream>
#include <stack>
#include <vector>
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

void leftload(node *root, stack<node *> &st)
{

    while (root)
    {
        st.push(root);
        root = root->left;
    }
}
vector<int> CommonNode(node *root1, node *root2)
{

    vector<int> ans;

    if (!root1 || !root2)
        return ans;

    stack<node *> st1;
    stack<node *> st2;
    leftload(root1, st1);
    leftload(root2, st2);
    while (!st1.empty() && !st2.empty())
    {

        if (st1.top()->data == st2.top()->data)
        {
            node *one = st1.top();
            node *two = st2.top();
            st1.pop();
            st2.pop();
            // cout << one->data << " ok" << endl;
            ans.push_back(one->data);
            one = one->right;
            two = two->right;
            leftload(one, st1);
            leftload(two, st2);
        }
        else if (st1.top()->data < st2.top()->data)
        {
            node *one = st1.top();
            st1.pop();
            one = one->right;
            leftload(one, st1);
        }
        else
        {
            node *two = st2.top();
            st2.pop();
            two = two->right;
            leftload(two, st2);
        }
    }

    return ans;
}
int main()
{

    node *root1 = build();
    node *root2 = build();

    in(root1);
    cout << endl;
    in(root2);
    cout << endl;
    vector<int> ans = CommonNode(root1, root2);

    for (auto ele : ans)
        cout << ele << " ";
}