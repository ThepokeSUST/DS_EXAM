#include <iostream>
#include <stack>
#include <vector>

using namespace std;

vector<int> prev_smallest(vector<int> &vec)
{

    int n = vec.size();
    vector<int> ans(n, -1);
    stack<int> st;

    for (int i = n - 1; i >= 0; i--)
    {

        while (!st.empty())
        {
            if (vec[st.top()] > vec[i])
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
    vector<int> vec = {1, 234, 4, 5445, 3, 23, 5};

    vector<int> ans = prev_smallest(vec);

    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
}