#include <iostream>
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
}

void preOr(node *root)
{
    if (!root)
        return;

    cout << root->data << " ";
    preOr(root->left);
    preOr(root->right);
}

vector<int> morris(node *root)
{

    vector<int> ans;

    while (root)
    {

        if (root->left)
        {
            node *temp = root->left;

            while (temp->right && temp->right != root)
            {
                temp = temp->right;
            }
            if (!temp->right)
            {
                temp->right = root;
                root = root->left;
            }
            else
            {
                ans.push_back(root->data);
                root = root->right;
                temp->right = NULL;
            }
        }
        else
        {
            ans.push_back(root->data);
            node *temp = root->right;
            root = temp;
        }
    }
    return ans;
}
int main()
{
    node *root = build();
    preOr(root);
    cout << endl;
    vector<int> ans = morris(root);
    for (auto ele : ans)
        cout << ele << " ";
}