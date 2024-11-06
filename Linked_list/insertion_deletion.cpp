#include <iostream>

using namespace std;

class node
{
    int data;

public:
    node *next;
    node(int ele)
    {
        this->data = ele;
        this->next = NULL;
    }
    void getvalue()
    {
        cout << this->data;
    }
};

// linked list
class list
{
    node *root;
    int size;

public:
    list()
    {
        this->root = NULL;
        this->size = 0;
    }
    void display();
    void push_front(int ele);
    void push_back(int ele);
    void insert_At(int ele, int k);
    void pop_back();
    void pop_front();
};

void list::pop_front()
{
    if (size == 0)
        return;

    node *temp = root;
    root = temp->next;
    delete (temp);
    size--;
    return;
}
void list::pop_back()
{
    if (size == 0)
        return;

    node *temp = root;

    while (temp->next->next != NULL)
    {
        temp = temp->next;
    }
    node *del = temp->next;
    temp->next = NULL;
    delete (del);
    return;
}
void list::display()
{
    if (root == NULL)
        return;

    node *temp = root;

    while (temp != NULL)
    {
        temp->getvalue();
        cout << "-> ";
        temp = temp->next;
    }
}
void list::push_front(int ele)
{

    if (this->root == NULL)
    {
        size++;
        node *newnode = new node(ele);
        this->root = newnode;
        return;
    }
    size++;
    node *newnode = new node(ele);
    newnode->next = root;
    root = newnode;
    return;
}

void list::push_back(int ele)
{

    if (root == NULL)
    {
        size++;
        node *newnode = new node(ele);

        root = newnode;
        return;
    }

    node *newnode = new node(ele);

    node *temp = root;

    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = newnode;
    size++;
    return;
}
void list::insert_At(int ele, int k)
{
    if (k == 0)
    {
        size++;
        push_front(ele);
        return;
    }
    if (k >= size)
    {
        return;
    }
    k--;
    node *temp = root;
    while (k)
    {
        temp = temp->next;
        k--;
    }
    size++;
    node *tp = temp->next;
    node *newnode = new node(ele);
    temp->next = newnode;
    newnode->next = tp;
}
int main()
{
    list l;
    l.push_back(8);
    l.push_back(10);
    l.push_front(5);
    l.push_front(2);
    l.display();
    l.insert_At(0, 0);
    cout << endl;
    l.display();

    l.pop_back();
    cout << endl;
    l.display();
}