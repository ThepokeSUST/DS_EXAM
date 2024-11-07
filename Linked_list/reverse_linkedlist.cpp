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
public:
    node *root;
    int size;

public:
    void print()
    {
        cout << root << "\n";
    }
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
    void reverse_list();
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

void list::reverse_list()
{

    if (root == NULL)
        return;

    node *pre = NULL;
    node *cur = root;
    node *next = cur->next;

    while (cur != NULL)
    {
        node *temp = cur;
        cur->next = pre;
        pre = cur;
        cur = next;
        if (cur != NULL)
            next = next->next;
    }
    root = pre;
    // cout <<  << endl;
}

int main()
{
    list l;
    l.push_front(3);
    l.push_back(8);
    l.push_back(34);
    l.push_front(23);
    l.display();
    l.reverse_list();
    cout << endl;
    l.display();
}