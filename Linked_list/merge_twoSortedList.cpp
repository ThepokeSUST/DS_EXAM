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

node *merge(node *head1, node *head2)
{
    node *head3 = NULL;
    node *tail = NULL;
    while (head1 && head2)
    {
        if (head1->getvalue() < head2->getvalue())
        {
            if (head3 == NULL)
            {
                head3 = head1;
                tail = head1;
                head1 = head1->next;
                head3->next = NULL;
            }
            else
            {
                tail->next = head1;
                tail = head1;
                head1 = head1->next;
                tail->next = NULL;
            }
        }
        else
        {
            if (head3 == NULL)
            {
                head3 = head2;
                tail = head2;
                head2 = head2->next;
                head3->next = NULL;
            }
            else
            {
                tail->next = head2;
                tail = head2;
                head2 = head2->next;
                tail->next = NULL;
            }
        }
    }
    if (head1)
    {
        tail->next = head1;
    }
    if (head2)
    {
        tail->next = head2;
    }
    return head3;
}

int main()
{
    list l;
    list ll;
    l.push_back(1);
    l.push_back(2);
    l.push_back(4);
    l.push_back(5);

    ll.push_back(4);
    ll.push_back(7);

    list lll;
    lll.root = merge(l.root, ll.root);
    lll.display();
}