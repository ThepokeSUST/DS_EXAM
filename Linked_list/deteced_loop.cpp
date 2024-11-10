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
    int getvalue()
    {
        return this->data;
    }
};

// linked list
class list
{

public:
    node *root;
    int size;
    list()
    {
        this->root = NULL;
        this->size = 0;
    }
    void display();
    void push_front(int ele);
    void push_back(int ele);
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

bool deteced_loop(node *head)
{

    if (head == NULL)
        return 1;

    node *slow = NULL;
    node *fast = head;

    while (fast && fast->next)
    {

        if (fast == slow)
        {
            return 1;
        }

        if (slow == NULL)
            slow = fast->next;
        else
            slow = slow->next;

        fast = fast->next->next;
    }
    return false;
}
int main()
{
    list l;
    list ll;

    l.push_back(3);
    l.push_back(7);
    l.push_back(3);
    l.push_back(7);
    l.push_back(3);
    l.push_back(7);
    cout << deteced_loop(l.root);
}