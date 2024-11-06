#include <iostream>

using namespace std;

class node
{

public:
    int a;
    node *next;

    node()
    {
        a = 90;
    }
};
int main()
{

    node *newnode = NULL;
    cout << newnode->a;
}