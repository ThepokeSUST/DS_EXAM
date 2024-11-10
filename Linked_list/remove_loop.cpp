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

node *reverse_recursively(node *cur, node *pre)
{
    /*if (head == NULL)
        return NULL;

    node *pre = NULL;
    node *cur = head;
    node *next = head->next;

    while (cur)
    {
        cur->next = pre;
        pre = cur;
        cur = next;
        if (cur != NULL)
            next = next->next;
    }
    return pre; */
    if (cur == NULL)
        return pre;
    node *temp = cur->next;
    cur->next = pre;
    return reverse_recursively(temp, cur);
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

void removeLoop(node *head)
{

    if (head == NULL)
        return;

    node *slow = head;
    node *fast = head;

    while (fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;
        //  cout << "slow " << slow->getvalue() << " fast" << fast->getvalue() << endl;
        if (fast == slow)
            break;
    }
    //  cout << "slow at " << slow->getvalue() << endl;
    slow = head;
    node *pre = NULL;
    //   cout << "fast at " << fast->getvalue() << endl;
    while (slow != fast)
    {

        //   cout << "ldl" << fast->getvalue() << endl;
        slow = slow->next;
        pre = fast;
        fast = fast->next;
    }
    //  cout << "sdjsd " << pre->getvalue() << endl;
    pre->next = NULL;
}

int main()
{
    list l;
    l.push_back(8);
    l.push_back(7);

    l.push_back(3);
    l.push_back(9);
    l.display();
    cout << endl;
    l.root = reverse_recursively(l.root, NULL);
    l.display();

    cout << endl
         << endl;
    l.push_back(0);
    l.push_back(7);

    l.push_back(3);
    l.push_back(9);

    l.display();
    cout << endl;

    node *temp = l.root->next->next->next;
    /// cout << temp->getvalue() << endl;
    node *cur = l.root;
    while (cur->next != NULL)
    {
        cur = cur->next;
    }
    cur->next = temp;
    // cout << "loop at " << temp->getvalue() << " " << cur->getvalue() << endl;
    // cout << cur->getvalue() << endl;
    // l.display();
    cout
        << deteced_loop(l.root);
    cout << endl;
    removeLoop(l.root);
    cout << deteced_loop(l.root) << endl;
    l.display();
}