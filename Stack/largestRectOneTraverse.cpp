#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int rect(vector<int> &vec)
{
    int n = vec.size();
    stack<int> st;
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        while (!st.empty() && vec[st.top()] > vec[i])
        {
            int ele = st.top();
            st.pop();
            int next = i;
            int prev = -1;
            if (!st.empty())
            {
                prev = st.top();
            }
            ans = max(ans, (next - prev - 1) * vec[ele]);

            // cout << ans << endl;
        }
        st.push(i);
    }

    while (!st.empty())
    {
        int next = n;
        int ele = st.top();
        // cout << ele << "ele " << endl;
        st.pop();
        int prev = -1;
        if (!st.empty())
        {
            prev = st.top();
            ans = max(ans, (next - prev - 1) * vec[ele]);
        }
        else
        {
            ans = max(ans, n * vec[ele]);
        }
        //   cout << ans << " ";
    }

    return ans;
}

int main()
{
    vector<int> vec = {4, 1, 1, 1, 5};
    cout << rect(vec);
}