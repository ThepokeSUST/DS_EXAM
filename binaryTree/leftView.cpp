#include <iostream>
#include <queue>
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

    node *root = new node(ele);
    root->left = build();
    root->right = build();

    return root;
}
void pre(node *root)
{
    if (!root)
        return;

    cout << root->data << " ";
    pre(root->left);
    pre(root->right);
}

vector<int> leftView(node *root)
{

    vector<int> ans;
    if (!root)
        return ans;
    queue<node *> q;
    q.push(root);

    while (!q.empty())
    {
        int s = q.size();
        ans.push_back(q.front()->data);
        while (s--)
        {
            node *temp = q.front();
            q.pop();
            if (temp->left)
                q.push(temp->left);
            if (temp->right)
                q.push(temp->right);
        }
    }

    return ans;
}
int main()
{
    node *root = build();

    vector<int> ans = leftView(root);
    for (auto ele : ans)
        cout << ele << " ";
}