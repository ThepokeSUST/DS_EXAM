#include <iostream>
#include <list>
using namespace std;

class Bstnode
{
public:
    int data;
    Bstnode *left;
    Bstnode *right;

    Bstnode(int ele)
    {
        data = ele;
        left = right = NULL;
    }
};

class Listnode
{
public:
    int data;
    Listnode *next;

    Listnode(int ele)
    {
        data = ele;
        next = NULL;
    }
};

class List
{
public:
    Listnode *head;
    Listnode *tail;
    List()
    {
        tail = head = NULL;
    }

    void push_back(int ele)
    {
        if (!head)
        {
            head = tail = new Listnode(ele);
            return;
        }

        Listnode *temp = new Listnode(ele);
        tail->next = temp;
        tail = temp;
    }
    void display()
    {

        Listnode *temp = head;

        while (temp)
        {
            cout << temp->data << "->";
            temp = temp->next;
        }
        cout << "NULL";
    }
};
Listnode *findMid(Listnode *st, Listnode *en)
{

    Listnode *fast = st;
    Listnode *slow = st;

    while (fast->next != en && fast->next->next != en)
    {
        fast = fast->next->next;
        slow = slow->next;
    }
    return slow;
}
Bstnode *BuildBst(Listnode *st, Listnode *en)
{
    if (st == en)
    {
        //  cout << st->data << "ok " << endl;
        return NULL;
    }
    Listnode *mid = findMid(st, en);
    //  cout << mid->data << "mid " << endl;
    Bstnode *temp = new Bstnode(mid->data);

    temp->left = BuildBst(st, mid);
    temp->right = BuildBst(mid->next, en);

    return temp;
}

void inorder(Bstnode *root)
{
    if (root == NULL)
        return;

    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}
int main()
{
    List l;
    l.push_back(9);
    l.push_back(10);
    l.push_back(11);
    l.push_back(30);
    l.push_back(150);

    l.display();
    cout << endl;
    // cout << findMid(l.head, l.tail->next)->data;
    cout << endl;
    Bstnode *root = BuildBst(l.head, l.tail->next);
    inorder(root);
}