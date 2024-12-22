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

int position(vector<int> &in, int st, int en, int ele)
{

    for (int i = st; i <= en; i++)
    {
        if (in[i] == ele)
            return i;
    }
    return -1;
}
node *build(vector<int> &pre, vector<int> &in, int st, int en)
{
    if (st > en)
        return NULL;
    static int idx = 0;
    node *temp = new node(pre[idx]);
    int pos = position(in, st, en, pre[idx++]);

    temp->left = build(pre, in, st, pos - 1);
    temp->right = build(pre, in, pos + 1, en);

    return temp;
}

void preOr(node *root)
{
    if (!root)
        return;

    cout << root->data << " ";
    preOr(root->left);
    preOr(root->right);
}
int main()
{
    vector<int> pre, in;
    int n;
    cin >> n;
    pre.resize(n);
    in.resize(n);
    for (int i = 0; i < n; i++)
        cin >> pre[i];
    for (int i = 0; i < n; i++)
        cin >> in[i];

    node *root = build(pre, in, 0, n - 1);
    preOr(root);
}