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

void kthMax(node *head, int &ans, int &k)
{

    if (head == NULL)
        return;

    kthMax(head->right, ans, k);
    k--;
    //  cout << k << endl;
    if (k == 0)
    {
        // cout << head->data << endl;
        ans = head->data;
        return;
    }
    else if (k < 0)
        return;

    kthMax(head->left, ans, k);
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
    int k = 2;
    kthMax(bt.root, ans, k);
    cout << ans;
}