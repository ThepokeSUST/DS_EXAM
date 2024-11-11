#include <iostream>
#include <stack>
#include <vector>
using namespace std;

vector<int> prev_greatest(vector<int> &vec)
{
    int n = vec.size();
    stack<int> st;
    vector<int> ans(n, -1);
    for (int i = n - 1; i >= 0; i--)
    {

        while (!st.empty())
        {
            if (vec[st.top()] < vec[i])
            {
                ans[st.top()] = vec[i];
                st.pop();
            }
            else
                break;
        }
        st.push(i);
    }

    return ans;
}

int main()
{

    vector<int> vec = {1, 3, 454, 23, 5, 6};
    vector<int> ans = prev_greatest(vec);

    for (int i = 0; i < ans.size(); i++)
        cout << ans[i] << " ";
}