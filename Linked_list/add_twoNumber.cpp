#include <iostream>

using namespace std;

class Node
{

public:
    int data;
    Node *next;
    //   Node *pre;

    Node(int ele)
    {
        this->data = ele;
        this->next = NULL;
    }
};

class List
{

    Node *head;
    //  Node *tail;

public:
    Node *gethead()
    {
        return head;
    }

    void sethead(Node *h)
    {
        head = h;
    }
    // void settail(Node *t)
    //{
    //    tail = t;
    //}
    List()
    {
        head = NULL;
    }

    void push_back(int ele)
    {
        if (head == NULL)
        {
            head = new Node(ele);
            return;
        }
        Node *temp = head;

        while (temp->next)
        {
            temp = temp->next;
        }
        temp->next = new Node(ele);

        // head = temp->next;
        return;
    }
    void push_front(int ele)
    {
        if (head == NULL)
        {
            head = new Node(ele);
            return;
        }
        Node *temp = new Node(ele);
        temp->next = head;
        head = temp;
        return;
    }
    void display()
    {
        if (head == NULL)
            return;

        Node *temp = head;
        while (temp)
        {
            cout << temp->data << "->";
            temp = temp->next;
        }
        cout << "NULL\n";
    }

    void pop_back()
    {
        if (head == NULL)
            return;

        Node *temp = head;
        if (temp->next == NULL)
        {
            delete (head);
            head = NULL;
            return;
        }
        while (temp->next->next)
        {
            temp = temp->next;
        }
        Node *del = temp->next;
        temp->next = NULL;
        delete (del);
        return;
    }

    void pop_front()
    {
        if (head == NULL)
            return;
        Node *del = head;
        head = head->next;
        delete (del);
        return;
    }
};

Node *reverse(Node *head, Node *pre)
{

    if (head == NULL)
    {

        return pre;
    }
    Node *next = head->next;
    head->next = pre;

    return reverse(next, head);
}

List *ADD(List &l1, List &l2)
{

    if (l1.gethead() == NULL && l2.gethead() == NULL)
        return NULL;
    else if (l1.gethead() == NULL)
    {
        return &l2;
    }
    else if (l2.gethead() == NULL)
        return &l1;

    // reverse both linked list
    Node *h = reverse(l1.gethead(), NULL);
    l1.sethead(h);
    h = reverse(l2.gethead(), NULL);
    l2.sethead(h);
    Node *head1 = l1.gethead();
    Node *head2 = l2.gethead();
    List *ans = new List();

    int carry = 0;
    while (head1 && head2)
    {
        int cur = head1->data + head2->data + carry;
        int nd = cur % 10;
        carry = cur / 10;
        // Node* temp= new node(nd);
        ans->push_back(nd);
        head1 = head1->next;
        head2 = head2->next;
    }

    while (head1)
    {

        int cur = head1->data + carry;
        int nd = cur % 10;
        carry = cur / 10;
        // Node* temp= new node(nd);
        ans->push_back(nd);
        head1 = head1->next;
    }

    while (head2)
    {

        int cur = head2->data + carry;
        int nd = cur % 10;
        carry = cur / 10;
        // Node* temp= new node(nd);
        ans->push_back(nd);
        head2 = head2->next;
    }
    if (carry)
    {
        ans->push_back(carry);
    }

    return ans;
}

int main()
{
    List l;
    List ll;

    l.push_back(9);
    l.push_back(9);
    l.push_back(9);
    l.push_back(9);
    l.push_back(9);
    l.push_back(9);

    ll.push_back(9);
    ll.push_back(9);
    ll.push_back(2);

    l.display();
    ll.display();

    // List lll;

    //  Node *h = reverse(ll.gethead(), NULL);
    // ll.sethead(h);
    List *ans = ADD(l, ll);
    cout << "ok\n";

    ans->sethead(reverse(ans->gethead(), NULL));
    ans->display();
}