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

    node *root = new node(ele);
    root->left = build();
    root->right = build();
}

vector<int> in(node *root)
{
    vector<int> ans;
    stack<node *> st;

    if (!root)
        return ans;
    // I N R

    while (root != NULL)
    {
        st.push(root);
        root = root->left;
    }

    while (!st.empty())
    {
        node *temp = st.top();
        st.pop();
        ans.push_back(temp->data);

        if (temp->right)
        {
            st.push(temp->right);
            temp = temp->right;

            while (temp->left)
            {
                st.push(temp->left);
                temp = temp->left;
            }
        }
    }
    return ans;
}
int main()
{

    node *root = build();

    vector<int> p = in(root);

    for (auto ele : p)
        cout << ele << " ";
}
