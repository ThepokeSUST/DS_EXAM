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
int lengthOfLoop(node *head)
{

    node *slow = head;
    node *fast = head;

    while (fast != NULL && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;
        if (fast == slow)
            break;
    }
    if (fast != slow)
        return -1;

    int count = 1;
    slow = slow->next;
    while (slow != fast)
    {
        slow = slow->next;
        count++;
    }
    return count;
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
    node *temp = l.root;
    temp = temp->next->next;
    node *temp1 = l.root;
    while (temp1->next != NULL)
    {
        temp1 = temp1->next;
    }
    temp1->next = temp;

    cout << deteced_loop(l.root);
    cout << endl;
    cout << lengthOfLoop(l.root);
}