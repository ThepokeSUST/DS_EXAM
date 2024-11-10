#include <iostream>

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

    void getvalue()
    {
        cout << this->data;
    }
};

class list
{
    node *root;
    int size;
    node *tail;

public:
    list()
    {
        root = NULL;
        size = 0;
        tail = NULL;
    }
    void display();
    void push_front(int);
    void push_back(int);
    void insert_At(int, int);
    void pop_front();
    void pop_back();
    void delete_Kth(int);
};

void list::delete_Kth(int k)
{
    // cout << "size " << size << endl;
    if (size <= k)
    {
        //  cout << "size>=" << endl;
        return;
    }
    if (root == NULL)
    {
        // cout << "NULL\n";
        return;
    }
    if (k == 0)
    {
        pop_front();
        return;
    }
    if (k == size - 1)
    {
        pop_back();
        //  cout << "ok";
        return;
    }
    node *temp = root;
    k--;
    //   cout << "out\n";
    while (k)
    {
        temp = temp->next;
        k--;
    }
    node *del = temp->next;
    temp->next = del->next;
    del->next->pre = temp;
    delete (del);
    return;
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
void list::insert_At(int ele, int k)
{

    if (k >= size)
        return;
    if (k == 0)
    {
        push_front(ele);
        return;
    }
    int mid = size / 2;
    if (k < mid)
    {
    }
    else
    {
    }
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
        temp->getvalue();
        cout << "-> ";

        temp = temp->next;
    }

    cout << endl;
}
int main()
{
}