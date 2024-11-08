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
        return data;
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
    if (temp->next == NULL)
    {
        size--;
        root = NULL;
        delete (temp);
        return;
    }
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

node *reverse(node *cur, node *pre)
{

    if (cur == NULL)
        return pre;

    node *next = cur->next;
    cur->next = pre;

    return reverse(next, cur);
}
void list::reverse_list()
{

    root = reverse(root, NULL);
}

bool palindrome(node *head)
{
    if (head == NULL)
        return true;
    // size......
    node *temp = head;
    int size = 0;
    while (temp != NULL)
    {
        size++;
        temp = temp->next;
    }
    int mid = size / 2;
    if (size == 1)
        return true;
    node *head1 = head;
    node *head2 = head;
    mid--;
    while (mid--)
    {
        head2 = head2->next;
    }
    temp = head2;
    head2 = head2->next;
    temp->next = NULL;
    head2 = reverse(head2, NULL);

    while (head1 != NULL)
    {
        if (head1->getvalue() != head2->getvalue())
        {
            return false;
        }
        head1 = head1->next;
        head2 = head2->next;
    }

    return true;
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
    cout << endl
         << endl;
    cout << palindrome(l.root);
    cout << endl;
    list ll;
    cout << palindrome(ll.root);
    cout << endl;
    ll.push_back(93);
    cout << palindrome(ll.root);
    // cout << "ds";
    ll.pop_back();

    ll.push_back(1);
    ll.push_back(2);
    ll.push_back(2);
    ll.push_back(1);
    cout << endl;
    // cout << "dddd\n";
    cout << palindrome(ll.root);
    // cout << "ok\n";
}