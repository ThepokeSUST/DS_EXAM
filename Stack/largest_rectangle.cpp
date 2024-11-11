#include <iostream>
#include <stack>
#include <vector>

using namespace std;

vector<int> nextSmallest(vector<int> &vec)
{

    int n = vec.size();
    vector<int> ans(n, n);
    stack<int> st;

    for (int i = 0; i < n; i++)
    {

        while (!st.empty() && vec[st.top()] > vec[i])
        {
            ans[st.top()] = i;
            st.pop();
        }
        st.push(i);
    }

    return ans;
}

vector<int> prevSmallest(vector<int> &vec)
{

    int n = vec.size();
    vector<int> ans(n, -1);
    stack<int> st;

    for (int i = n - 1; i >= 0; i--)
    {

        while (!st.empty() && vec[st.top()] > vec[i])
        {
            ans[st.top()] = i;
            st.pop();
        }
        st.push(i);
    }

    return ans;
}

int main()
{

    vector<int> vec = {2, 3, 4, 2, 6, 5, 4, 5, 3};
    vector<int> next = nextSmallest(vec);
    vector<int> pre = prevSmallest(vec);

    for (auto ele : next)
    {
        cout << ele << " ";
    }
    cout << endl;
    for (auto ele : pre)
    {
        cout << ele << " ";
    }
    int k = 0;
    for (int i = 0; i < next.size(); i++)
    {

        int ok = next[i] - pre[i] - 1;
        if (ok > k)
        {
            k = ok;
        }
    }
    cout << endl;
    cout << "largest area " << 2 * k;
}