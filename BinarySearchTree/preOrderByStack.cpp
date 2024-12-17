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

void in(node *temp)
{
    if (!temp)
        return;

    in(temp->left);
    cout << temp->data << " ";
    in(temp->right);
}
vector<int> inStack(node *root)
{
    vector<int> ans;
    stack<node *> st;

    while (root != NULL)
    {
        st.push(root);
        root = root->left;
    }
    while (!st.empty())
    {
        node *temp = st.top();
        st.pop();
        //    cout << temp->data << endl;
        ans.push_back(temp->data);
        temp = temp->right;
        while (temp != NULL)
        {
            // cout << "gg\n";
            st.push(temp);
            temp = temp->left;
        }
    }
    return ans;
}
int main()
{

    node *root;
    root = build();
    //  in(root);
    vector<int> ans = inStack(root);
    cout << endl;
    in(root);
    cout << endl;
    for (auto ele : ans)
        cout << ele << " ";
}