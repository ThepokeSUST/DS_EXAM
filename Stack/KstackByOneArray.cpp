#include <iostream>
#include <list>
#include <queue>
#include <vector>
using namespace std;

class Stack
{

public:
    int size;
    vector<int> vec;
    queue<int> idx;
    vector<list<int>> ano;

    Stack(int n)
    {
        vec.resize(n);
        size = n;
        for (int i = 0; i < n; i++)
            idx.push(i);
    }
};
int main()
{
}