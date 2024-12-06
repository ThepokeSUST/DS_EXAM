#include <iostream>
#include <queue>
#include <vector>
using namespace std;

class node
{

public:
    int data;
    node *right;
    node *left;

    node(int ele)
    {
        this->data = ele;
        right = left = NULL;
    }
};

class BinaryTree
{

    node *root;

    node *insrt(node *head, int ele)
    {
        if (head == NULL)
            return new node(ele);

        if (head->data < ele)
            head->right = insrt(head->right, ele);
        else
            head->left = insrt(head->left, ele);

        return head;
    }

    void showIn(node *head)
    {
        if (head == NULL)
            return;
        showIn(head->left);
        cout << head->data << " ";
        showIn(head->right);
    }

public:
    BinaryTree()
    {
        this->root = NULL;
    }
    void insert(int ele)
    {
        this->root = insrt(root, ele);
    }

    void inorder()
    {
        showIn(root);
    }

    vector<int> levelOrder()
    {
        node *head = root;
        vector<int> vec;
        if (head == NULL)
            return vec;

        queue<node *> q;
        q.push(head);

        while (!q.empty())
        {
            node *ele = q.front();
            vec.push_back(ele->data);
            q.pop();
            if (ele->left)
                q.push(ele->left);
            if (ele->right)
                q.push(ele->right);
        }

        return vec;
    }
};

int main()
{
    BinaryTree bt;
    bt.insert(8);
    bt.insert(5);
    bt.insert(90);
    bt.insert(34);
    bt.inorder();
    cout << endl;
    vector<int> vec;
    vec = bt.levelOrder();

    for (auto ele : vec)
        cout << ele << " ";
}