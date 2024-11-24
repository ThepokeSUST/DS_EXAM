#include <iostream>

using namespace std;

class node
{

public:
    int data;
    node *next;

    node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};

class List
{

public:
    node *root;

public:
    List()
    {
        root = NULL;
    }

    void push(int ele)
    {

        if (root == NULL)
        {
            root = new node(ele);
            return;
        }

        node *temp = root;

        while (temp->next)
        {
            temp = temp->next;
        }

        temp->next = new node(ele);
        return;
    }

    node *reverse_(node *rot)
    {
        if (rot == NULL)
            return NULL;
        node *pre = NULL;
        node *cur = rot;
        while (cur)
        {
            node *nxt = cur->next;
            cur->next = pre;
            pre = cur;
            cur = nxt;
        }

        return pre;
    }

    void reverse()
    {
        this->root = reverse_(this->root);
    }

    void display()
    {

        if (root == NULL)
            return;

        node *temp = root;

        while (temp)
        {
            cout << temp->data << "->";
            temp = temp->next;
        }
        cout << "NULL\n";
    }
};

node *rves(node *head, int k, node *pre, node *cur)
{
    int count = 1;

    if (head == NULL)
        return NULL;

    while (cur && count <= k)
    {
        count++;
        node *next = cur->next;
        cur->next = pre;
        pre = cur;
        cur = next;
    }
    // count = 0;
    head->next = rves(cur, k, NULL, cur);
    cout << pre->data << endl;
    return pre;
}

int main()
{
    List li;
    li.push(1);
    li.push(2);
    li.push(3);
    li.push(4);
    li.push(5);
    li.display();
    // li.reverse();
    // li.display();
    li.root = rves(li.root, 3, NULL, li.root);
    li.display();
}
