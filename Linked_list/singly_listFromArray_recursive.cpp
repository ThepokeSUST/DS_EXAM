#include <iostream>
#include <vector>
using namespace std;

class node
{

public:
    int data;
    node *next;

    node(int ele)
    {
        this->data = ele;
        next = NULL;
    }
};

class list
{

public:
    node *head;

    list()
    {
        head = NULL;
    }
    void display();
    void push_front(int);
    void push_back(int);
    void pop_front();
    void pop_back();
};
void list::display()
{
    if (head == NULL)
        return;

    node *temp = head;

    while (temp != NULL)
    {
        cout << temp->data << "->";
        temp = temp->next;
    }
    cout << "NULL\n";
    return;
}
void list::push_front(int ele)
{

    if (head == NULL)
    {
        node *newnode = new node(ele);
        head = newnode;
        return;
    }
    node *newnode = new node(ele);
    newnode->next = head;
    head = newnode;
    return;
}
void list::push_back(int ele)
{
    if (head == NULL)
    {
        node *newnode = new node(ele);
        head = newnode;
        return;
    }
    node *newnode = new node(ele);

    node *temp = head;

    while (temp->next != NULL)
    {
        temp = temp->next;
    }

    temp->next = newnode;
    return;
}
void list::pop_front()
{

    if (head == NULL)
        return;

    node *del = head;
    head = del->next;
    delete (del);
    return;
}

void list::pop_back()
{
    if (head == NULL)
        return;

    node *pre = NULL;
    node *cur = head;

    while (cur->next != NULL)
    {
        pre = cur;
        cur = cur->next;
    }

    pre->next = NULL;
    delete (cur);
    return;
}

node *build(vector<int> &vec, int idx, int size)
{

    if (idx == size)
    {
        return NULL;
    }

    node *newnode = new node(vec[idx]);
    newnode->next = build(vec, idx + 1, size);

    return newnode;
}

node *by_array(vector<int> &vec, node *&head)
{
    if (head == NULL)
    {

        head = build(vec, 0, vec.size());
    }
    else
    {
        node *temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }

        temp->next = build(vec, 0, vec.size());
    }
}

int main()
{
    list l;
    l.push_back(7);
    l.push_front(8);
    l.display();

    vector<int> vec(5);
    for (int i = 0; i < 5; i++)
    {
        cin >> vec[i];
    }
    by_array(vec, l.head);
    l.display();
}