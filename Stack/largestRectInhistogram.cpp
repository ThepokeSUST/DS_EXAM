#include <iostream>
#include <stack>
#include <vector>

using namespace std;
vector<int> nextSmallestEle(vector<int> &vec)
{
    int n = vec.size();
    vector<int> res(n, -1);
    stack<int> st;

    for (int i = 0; i < n; i++)
    {

        while (!st.empty() && vec[st.top()] > vec[i])
        {
            res[st.top()] = i;
            st.pop();
        }
        st.push(i);
    }

    while (!st.empty())
    {
        res[st.top()] = n;
        st.pop();
    }
    /*    for (auto ele : res)
            cout << ele << " ";
        cout << endl;
    */
    return res;
}

vector<int> prevSmallestEle(vector<int> &vec)
{

    int n = vec.size();
    vector<int> res(n, -1);
    stack<int> st;
    for (int i = 0; i < n; i++)
    {

        while (!st.empty() && vec[st.top()] > vec[i])
        {
            st.pop();
        }
        if (!st.empty())
            res[i] = st.top();

        st.push(i);
    }
    return res;
}
int largestRect(vector<int> &vec)
{
    vector<int> nextsmall = nextSmallestEle(vec);
    vector<int> prevsmall = prevSmallestEle(vec);

    int ans = 0;
    int n = vec.size();
    for (int i = 0; i < vec.size(); i++)
    {
        int a = prevsmall[i];
        int b = nextsmall[i];

        ans = max(ans, ((b - a - 1) * vec[i]));
    }
    return ans;
}

int main()
{
    vector<int> vec = {4, 3, 2, 1, 5};

    cout << largestRect(vec);
}