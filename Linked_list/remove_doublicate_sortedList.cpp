#include <iostream>
#include <vector>
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
    int getvalue()
    {
        return this->data;
    }
};

// linked list
class list
{

    int size;

public:
    node *root;
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
        cout << temp->getvalue();
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

bool doublicate(node *head)
{

    if (head == NULL)
        return 1;

    vector<int> vec;
    vec.push_back(head->getvalue());
    node *temp = head->next;
    node *pre = head;
    while (temp)
    {
        if (temp->getvalue() == vec[vec.size() - 1])
        {
            node *del = temp;
            pre->next = del->next;
            temp = del->next;
            delete (del);
        }
        else
        {
            vec.push_back(temp->getvalue());
            pre = temp;
            temp = temp->next;
        }
    }
}
int main()
{
    list l;
    l.push_back(1);
    l.push_back(1);
    l.push_back(2);
    l.push_back(2);
    l.push_back(3);
    l.push_back(4);
    l.push_back(5);
    l.push_back(5);
    l.display();
    cout << endl;
    doublicate(l.root);
    l.display();
}