#include <climits>
#include <iostream>
#include <stack>
#include <vector>
using namespace std;

class node
{
public:
    int data;
    node *left;
    node *right;
    node(int data)
    {
        this->data = data;
        left = right = NULL;
    }
};

node *build()
{

    int ele;
    cin >> ele;
    if (ele == -1)
        return NULL;

    node *temp = new node(ele);
    temp->left = build();
    temp->right = build();
    return temp;
}
bool chk(vector<int> &pre)
{
    int n = pre.size();

    stack<pair<int, int>> st;
    int idx = 0;
    st.push({INT_MIN, INT_MAX});
    while (!st.empty())
    {
        if (st.top().first > pre[idx])
            return false;
        // when ele in its range
        if (pre[idx] > st.top().first && pre[idx] < st.top().second)
        {
            idx++;
            int low = st.top().first;
            int high = st.top().second;
            st.pop();
            st.push({pre[idx - 1], high});
            st.push({low, pre[idx - 1]});
        }
        else
            while (!st.empty() && st.top().second > pre[idx])
            {
                st.pop();
            }
    }

    return idx == n;
}
int main()
{
    int n;
    cin >> n;
    vector<int> vec(n);

    for (int i = 0; i < n; i++)
        cin >> vec[i];

    cout << chk(vec);
}