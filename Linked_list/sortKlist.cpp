#include <iostream>

using namespace std;

class node
{

public:
    int data;
    node *next;
    node(int ele)
    {
        this->data = ele;
        this->next = NULL;
    }
};

class List
{
public:
    node *root;

    List()
    {
        this->root = NULL;
    }

    void push_back(int ele)
    {
        if (root == NULL)
        {
            root = new node(ele);
            return;
        }

        node *temp = root;

        while (temp->next)
        {
            temp = temp->next;
        }

        temp->next = new node(ele);
    }
    void push_front(int ele)
    {

        if (root == NULL)
        {
            root = new node(ele);
            return;
        }

        node *temp = new node(ele);
        temp->next = root;
        root = temp;
    }
    void display()
    {
        if (root == NULL)
            return;

        node *temp = root;

        while (temp)
        {
            cout << temp->data << "->";
            temp = temp->next;
        }
        cout << "NULL\n";
    }
};

node *merge(node *head1, node *head2)
{

    if (!head1 && !head2)
        return NULL;
    if (!head1)
        return head2;
    if (!head2)
        return head1;

    node *head = new node(0);
    node *tail = head;
    while (head1 && head2)
    {

        if (head1->data >= head2->data)
        {
            tail->next = head1;
            head1 = head1->next;
            tail = tail->next;
        }
        else
        {
            tail->next = head2;
            head2 = head2->next;
            tail = tail->next;
        }
    }
    if (head1)
        tail->next = head1;
    else
        tail->next = head2;

    node *newhead = head->next;
    delete (head);
    return newhead;
}

node *mergeKthList(List arr[], int size)
{

    if (size == 0)
        return NULL;
    node *head = arr[0].root;
    arr[0].root = NULL;
    for (int i = 1; i < size; i++)
    {

        head = merge(head, arr[i].root);
        arr[i].root = NULL;
    }
    return head;
}
int main()
{
    List l;
    l.push_back(8);
    l.push_back(7);
    l.push_back(5);

    List ll;
    ll.push_back(10);
    ll.push_back(6);
    ll.push_back(4);
    ll.push_back(3);

    List lll;

    lll.root = merge(l.root, ll.root);

    lll.display();
    cout << "array merge\n";
    List arr[5];
    arr[0].push_back(7);
    arr[0].push_back(5);
    arr[0].push_back(4);
    arr[0].push_back(1);

    arr[1].push_back(10);
    arr[1].push_back(4);
    arr[1].push_back(2);
    arr[1].push_back(0);

    arr[2].push_back(67);
    arr[2].push_back(54);
    arr[2].push_back(34);
    arr[2].push_back(21);

    arr[3].push_back(78);
    arr[3].push_back(43);
    arr[3].push_back(32);
    arr[3].push_back(0);

    List ml;
    ml.root = mergeKthList(arr, 4);
    ml.display();
}