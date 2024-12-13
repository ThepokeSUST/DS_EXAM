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

void kthhMIN(node *head, int prv, int &k, int &ans)
{

    if (head == NULL)
        return;

    kthhMIN(head->left, prv, k, ans);
    // prv=head->data;
    // cout << head->data << " " << k << endl;

    k--;
    if (k == 0)
    {
        //  cout << "ok\n";
        ans = head->data;
        return;
    }
    else if (k < 0)
        return;

    kthhMIN(head->right, prv, k, ans);
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
    int ans = 0;
    int k = 4;
    kthhMIN(bt.root, INT_MIN, k, ans);
    cout << ans;
}