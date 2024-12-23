#include <iostream>

using namespace std;

class node
{
public:
    int data;
    node *left;
    node *right;
    int height;
    node(int ele)
    {
        data = ele;
        left = right = NULL;
        height = 1;
    }
};

int getheight(node *root)
{
    if (!root)
        return 0;

    return root->height;
}

node *leftrote(node *root)
{
    node *temp = root->right;
    root->right = temp->left;
    temp->left = root;
    root->height = 1 + max(getheight(root->left), getheight(root->right));
    temp->height = 1 + max(getheight(temp->left), getheight(temp->right));
    return temp;
}
node *rightrote(node *root)
{

    node *temp = root->left;
    root->left = temp->right;
    temp->right = root;
    root->height = 1 + max(getheight(root->left), getheight(root->right));
    temp->height = 1 + max(getheight(temp->left), getheight(temp->right));
    return temp;
}
class AVL
{
    node *root;

public:
    AVL()
    {
        root = NULL;
    }

private:
    node *isrt(node *rt, int ele)
    {
        if (rt == NULL)
        {
            return new node(ele);
        }

        if (rt->data < ele)
            rt->right = isrt(rt->right, ele);
        else
            rt->left = isrt(rt->left, ele);

        rt->height = 1 + max(getheight(rt->left), getheight(rt->right));

        int balance = getheight(rt->left) - getheight(rt->right);
        // right
        if (balance < -1)
        {
            // right right
            if (rt->data < ele)
            {
                return leftrote(rt);
            }
            // right left
            else
            {
                rt->right = rightrote(rt->right);
                return leftrote(rt);
            }
        }
        // left
        else if (balance > 1)
        {
            // left left
            if (rt->data > ele)
            {
                return rightrote(rt);
            }
            // left right
            else
            {
                rt->left = leftrote(rt->left);
                return rightrote(rt);
            }
        }

        return rt;
    }

    node *dlet(node *rt, int ele)
    {
        if (rt == NULL)
            return NULL;

        if (rt->data > ele)
            rt->left = dlet(rt->left, ele);
        else if (rt->data < ele)
            rt->right = dlet(rt->right, ele);
        else
        {

            // leaf node
            if (!rt->left && !rt->right)
            {
                delete (rt);
                return NULL;
            }
            // left exist
            else if (rt->left && !rt->right)
            {
                node *temp = rt->left;
                delete (rt);
                return temp;
            }
            // right exist
            else if (root->right && !rt->left)
            {
                node *temp = rt->right;
                delete (rt);
                return temp;
            }
            else
            {
                node *child = rt->right;
                node *par = rt;

                while (child->left)
                {
                    par = child;
                    child = child->left;
                }

                // node* temp= child->right;
                if (par == rt)
                {
                    child->left = rt->left;
                    delete (rt);
                    return child;
                }
                par->left = child->right;
                child->right = rt->right;
                child->left = rt->left;
                delete (rt);
                return child;
            }
        }

        return rt;
    }

public:
    void insert(int ele)
    {
        root = isrt(root, ele);
    }
    void deletion(int ele)
    {
        root = dlet(root, ele);
    }

private:
    void dis(node *rt)
    {
        if (!rt)
            return;

        dis(rt->left);
        cout << rt->data << " ";
        dis(rt->right);
    }

public:
    void display()
    {
        dis(root);
    }
};
int main()
{
    AVL at;
    at.insert(3);
    at.insert(9);
    at.insert(10);
    at.insert(35);
    at.display();
    cout << endl;
    at.insert(0);
    at.display();
    cout << endl;
    // at.deletion(0);
    at.deletion(10);
    // at.deletion(35);
    at.deletion(3);
    // at.deletion(9);
    at.display();
}