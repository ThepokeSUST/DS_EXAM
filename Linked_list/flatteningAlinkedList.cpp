#include <iostream>

using namespace std;

class node
{

public:
    int data;
    node *next;
    node *bottom;

    node(int ele)
    {
        this->data = ele;
        this->bottom = NULL;
        this->next = NULL;
    }
};

class List
{
public:
    node *root;

public:
    List()
    {
        this->root = NULL;
    }

    void push_next(int ele, node *root)
    {

        if (root == NULL)
        {
            this->root = new node(ele);
            return;
        }

        node *temp = root;

        while (temp->next)
        {
            temp = temp->next;
        }

        temp->next = new node(ele);
        return;
    }

    void push_bottom(int ele, node *root)
    {

        if (root == NULL)
        {
            this->root = new node(ele);
            return;
        }

        node *temp = root;

        while (temp->bottom)
        {
            temp = temp->bottom;
        }
        temp->bottom = new node(ele);
        return;
    }

    /* node *rvs(node *cur, node *pre)
     {
         if (cur == NULL)
             return pre;
         node *next = cur->next;
         cur->next = pre;
         pre = cur;
         cur = next;
         return rvs(cur, pre);
     }

     void reverse()
     {
         if (root == NULL)
             return;

         this->root = rvs(root, NULL);
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
*/
    void insertAtkthbottom(int ele, int k)
    {

        if (root == NULL)
        {
            root = new node(ele);
            return;
        }

        node *temp = root;

        while (--k)
        {
            temp = temp->next;
        }
        if (temp == NULL)
            return;

        while (temp->bottom)
        {
            temp = temp->bottom;
        }
        temp->bottom = new node(ele);
        return;
    }

    node *sort(node *head1, node *head2)
    {

        node *head = NULL;
        node *tail = NULL;
        while (head1 && head2)
        {
            if (head1->data >= head2->data)
            {
                if (!head)
                {
                    head = head1;
                    tail = head1;
                }
                else
                {
                    tail->bottom = head1;
                    tail = tail->bottom;
                }
                head1 = head1->bottom;
            }
            else
            {

                if (!head)
                {
                    head = head2;
                    tail = head2;
                }
                else
                {
                    tail->bottom = head2;
                    tail = tail->bottom;
                }
                head2 = head2->bottom;
            }
        }

        if (head1)
            tail->bottom = head1;
        if (head2)
            tail->bottom = head2;

        return head;
    }
    void display()
    {
        if (root == NULL)
            return;

        node *temp = root;

        while (temp)
        {
            cout << temp->data;
            node *nich = temp->bottom;
            while (nich)
            {
                cout << "|" << nich->data << "|";
                nich = nich->bottom;
            }
            cout << "->";
            temp = temp->next;
        }
        cout << "NULL\n";
    }

    node *flat()
    {
        if (root == NULL)
            return NULL;

        node *first = root;
        node *second = root->next;
        root->next = NULL;

        while (second)
        {

            node *next = second->next;
            second->next = NULL;
            first = sort(first, second);
            second = next;
        }

        root = first;
    }
};
int main()
{
    List li;

    li.push_next(9, li.root);
    li.push_next(8, li.root);
    li.push_next(6, li.root);
    li.display();
    li.insertAtkthbottom(5, 2);
    li.display();

    li.flat();
    li.display();
}