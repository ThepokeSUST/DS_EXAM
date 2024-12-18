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

vector<int> GreatestLevel(node *root)
{
    vector<int> ans;
    if (root == NULL)
        return ans;

    priority_queue<pair<int, node *>> q1;
    priority_queue<pair<int, node *>> q2;
    q1.push({root->data, root});

    while (!q1.empty() || !q2.empty())
    {
        node *temp = NULL;
        if (!q1.empty())
            while (!q1.empty())
            {
                //  cout << "one\n";
                if (temp == NULL)
                {
                    temp = q1.top().second;
                    q1.pop();
                    ans.push_back(temp->data);
                    if (temp->left)
                        q2.push({temp->left->data, temp->left});
                    if (temp->right)
                        q2.push({temp->right->data, temp->right});
                }
                else
                {
                    temp = q1.top().second;
                    q1.pop();
                    if (temp->left)
                        q2.push({temp->left->data, temp->left});
                    if (temp->right)
                        q2.push({temp->right->data, temp->right});
                }
            }
        else
            while (!q2.empty())
            {
                //   cout << "two\n";
                if (temp == NULL)
                {
                    temp = q2.top().second;
                    q2.pop();
                    ans.push_back(temp->data);
                    if (temp->left)
                        q1.push({temp->left->data, temp->left});
                    if (temp->right)
                        q1.push({temp->right->data, temp->right});
                }
                else
                {
                    temp = q2.top().second;
                    q2.pop();
                    if (temp->left)
                        q1.push({temp->left->data, temp->left});
                    if (temp->right)
                        q1.push({temp->right->data, temp->right});
                }
            }
    }

    return ans;
}
int main()
{
    node *root = build();
    pre(root);
    cout << endl;
    vector<int> ans = GreatestLevel(root);
    for (auto ele : ans)
        cout << ele << " ";
}