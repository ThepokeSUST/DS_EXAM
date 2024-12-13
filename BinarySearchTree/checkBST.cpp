#include <climits>
#include <iostream>
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

class binaryTree
{

public:
    node *root;
    node *tail;
    binaryTree()
    {
        root = NULL;
        tail = NULL;
    }

    node *insrt(node *head)
    {

        int ele;
        cin >> ele;
        if (ele == -1)
            node *h = new node(ele);
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

bool chkBst(node *head, int prv)
{
    if (head == NULL)
        return true;
    bool l = chkBst(head->left, prv);
    if (l == false)
        return false;
    if (prv != INT_MIN)
        if (prv > head->data)
            return false;
    prv = head->data;

    return chkBst(head->right, prv);
}

int main()
{

    BST bt;
    bt.insert(9);
    bt.insert(6);
    bt.insert(23);
    bt.insert(1);
    bt.inorder();
    cout << endl;
    cout << chkBst(bt.root, INT_MIN);

    node *root = new node(9);

    root->left = new node(10);
    root->right = new node(11);

    root->left->left = new node(5);
    root->left->right = new node(8);
    cout << endl;
    cout << chkBst(root, INT_MIN);
}