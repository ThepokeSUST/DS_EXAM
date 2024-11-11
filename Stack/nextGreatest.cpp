#include <iostream>
#include <stack>
#include <vector>

using namespace std;

vector<int> NextGreatest(vector<int> &vec)
{

    int n = vec.size();
    stack<int> st;
    vector<int> ans(n, -1);
    for (int i = 0; i < n; i++)
    {

        if (st.empty())
            st.push(i);

        else
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
    }

    return ans;
}
int main()
{

    vector<int> vec = {4, 23, 5, 67, 4, 4, 5, 6778, 67};

    vector<int> ans = NextGreatest(vec);

    for (int i = 0; i < ans.size(); i++)
        cout << ans[i] << " ";
}