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

void fillarray(node *root, vector<int> &tr)
{
    if (root == NULL)
        return;

    tr.push_back(root->data);
    fillarray(root->left, tr);
    fillarray(root->right, tr);
}

void heapify(vector<int> &tr, int node, int size)
{

    int left = node * 2 + 1;
    int right = node * 2 + 2;
    int large = node;

    if (left < size && tr[left] > tr[large])
        large = left;
    if (right < size && tr[right] > tr[large])
        large = right;

    if (large != node)
    {
        swap(tr[large], tr[node]);
        heapify(tr, large, size);
    }
}

node *cvrtTree(vector<int> &tr, int idx, int size)
{
    if (size == 0 || idx >= size)
        return NULL;

    node *newnode = new node(tr[idx]);
    newnode->left = cvrtTree(tr, idx * 2 + 1, size);
    newnode->right = cvrtTree(tr, idx * 2 + 2, size);
    return newnode;
}
void preOrder(node *root)
{
    if (root == NULL)
        return;
    cout << root->data << " ";
    preOrder(root->left);
    preOrder(root->right);
}
void solve()
{

    node *root1 = build();
    node *root2 = build();
    vector<int> tr;
    fillarray(root1, tr);
    fillarray(root2, tr);
    cout << tr.size() << endl;

    int n = tr.size();

    for (int i = (n / 2) - 1; i >= 0; i--)
    {
        heapify(tr, i, n);
    }

    for (auto ele : tr)
        cout << ele << " ";
    cout << endl;
    node *MaxBinaryHeap = cvrtTree(tr, 0, n);
    preOrder(MaxBinaryHeap);
}
int main()
{
    solve();
}