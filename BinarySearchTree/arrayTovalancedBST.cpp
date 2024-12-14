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

    node(int ele)
    {
        this->data = ele;
        left = right = NULL;
    }
};

class BST
{

public:
    node *root;
    BST()
    {
        root = NULL;
    }

private:
    node *insrt(int ele, node *head)
    {

        if (head == NULL)
            return new node(ele);

        if (head->data < ele)
            head->right = insrt(ele, head->right);
        else if (head->data > ele)
            head->left = insrt(ele, head->left);

        return head;
    }
    void inord(node *head)
    {
        if (head == NULL)
            return;

        inord(head->left);
        cout << head->data << " ";
        inord(head->right);
    }

public:
    void insert(int ele)
    {
        this->root = insrt(ele, root);
    }
    void inorder()
    {
        inord(this->root);
    }
};

node *arrayBST(vector<int> &vec, int st, int en)
{

    if (st > en)
        return NULL;
    cout << st << " " << en << endl;
    int mid = st + (en - st) / 2;
    node *temp = new node(vec[mid]);
    temp->left = arrayBST(vec, st, mid - 1);
    temp->right = arrayBST(vec, mid + 1, en);
    return temp;
}

int main()
{

    vector<int> vec;

    int n;
    cin >> n;
    vec.resize(n);
    cout << "ok\n";
    for (int i = 0; i < n; i++)
        cin >> vec[i];

    BST Bt;

    Bt.root = arrayBST(vec, 0, vec.size() - 1);
    cout << "inorder ";
    Bt.inorder();
}