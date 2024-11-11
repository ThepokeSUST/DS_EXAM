#include <iostream>
#include <stack>
#include <vector>

using namespace std;
vector<int> span(vector<int> &vec)
{

    int n = vec.size();
    vector<int> ans(n, 1);
    stack<int> st;
    for (int i = n - 1; i >= 0; i--)
    {
        while (!st.empty())
        {
            if (vec[st.top()] < vec[i])
            {
                ans[st.top()] = st.top() - i;
                st.pop();
            }
            else
                break;
        }
        st.push(i);
    }

    while (!st.empty())
    {
        ans[st.top()] = st.top() + 1;
        st.pop();
    }
    return ans;
}
int main()
{

    vector<int> vec = {80, 100, 55, 70, 60, 75, 85};
    vector<int> ans = span(vec);

    for (int i = 0; i < ans.size(); i++)
        cout << ans[i] << " ";
}