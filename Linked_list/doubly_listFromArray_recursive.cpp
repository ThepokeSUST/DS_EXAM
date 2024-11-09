#include <iostream>
#include <vector>
using namespace std;

class node
{

    int data;

public:
    node *next;
    node *pre;

    node(int ele)
    {
        this->data = ele;
        this->next = NULL;
        this->pre = NULL;
    }

    int getvalue()
    {
        return this->data;
    }
};

class list
{

    int size;
    node *tail;

public:
    node *root;
    list()
    {
        root = NULL;
        size = 0;
        tail = NULL;
    }
    void display();
    void push_front(int);
    void push_back(int);
    void pop_front();
    void pop_back();
    void display_r();
};

void list::display_r()
{
    if (tail == NULL)
        return;

    node *temp = tail;

    while (temp != NULL)
    {
        cout << temp->getvalue() << "->";
        temp = temp->pre;
    }
    cout << "NULL\n";
}
void list::pop_front()
{
    if (root == NULL)
        return;
    size--;

    node *temp = root->next;

    if (temp == NULL)
    {
        delete (root);
        root = NULL;
        tail = NULL;
        return;
    }
    node *del = root;
    temp->pre = NULL;
    root = temp;
    delete (del);
    return;
}
void list::pop_back()
{
    if (tail == NULL)
    {
        return;
    }
    size--;
    node *temp = tail->pre;
    if (temp == NULL)
    {
        delete (tail);
        tail = NULL;
        root = NULL;
        return;
    }
    temp->next = NULL;
    delete (tail);
    tail = temp;
    return;
}
void list::push_front(int ele)
{
    node *newnode = new node(ele);
    if (root == NULL)
    {
        root = newnode;
        tail = newnode;
        size++;
        return;
    }
    newnode->next = root;
    root->pre = newnode;
    root = newnode;
    size++;
    return;
}

void list::push_back(int ele)
{

    node *newnode = new node(ele);
    if (root == NULL)
    {
        root = newnode;
        tail = newnode;
        size++;
        return;
    }

    newnode->pre = tail;
    tail->next = newnode;
    tail = newnode;
    size++;
}
void list::display()
{
    if (root == NULL)
    {
        cout << "empty\n";
        return;
    }

    node *temp = root;
    while (temp != NULL)
    {
        cout << temp->getvalue();
        cout << "-> ";

        temp = temp->next;
    }

    cout << "NULL" << endl;
}

node *build(vector<int> &vec, int idx, int size, node *head)
{
    if (idx == size)
        return NULL;

    node *newnode = new node(vec[idx]);
    newnode->pre = head;
    newnode->next = build(vec, idx + 1, size, newnode);
    return newnode;
}
void by_array(vector<int> &vec, node *&head)
{
    if (head == NULL)
    {
        cout << "o\n";
        head = build(vec, 0, vec.size(), head);
        cout << "k\n";
    }
}
int main()
{
    list l;
    vector<int> vec = {1, 2, 3, 4, 5};

    by_array(vec, l.root);
    l.display();
}