#include <climits>
#include <iostream>
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

node *Build(vector<int> &pre, int &idx, int n, int low, int high)
{

    if (idx >= n || pre[idx] > high || pre[idx] < low)
        return NULL;

    node *temp = new node(pre[idx++]);
    temp->left = Build(pre, idx, n, low, temp->data);
    temp->right = Build(pre, idx, n, temp->data, high);

    return temp;
}

void inorder(node *head)
{
    if (!head)
        return;

    inorder(head->left);
    cout << head->data << " ";
    inorder(head->right);
}
int main()
{

    int n;
    cin >> n;
    vector<int> vec(n);

    for (int i = 0; i < n; i++)
        cin >> vec[i];
    int idx = 0;
    node *head = Build(vec, idx, n, INT_MIN, INT_MAX);

    inorder(head);
}