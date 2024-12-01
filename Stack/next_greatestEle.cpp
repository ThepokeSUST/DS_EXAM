#include <iostream>
#include <stack>
#include <vector>

using namespace std;

vector<int> nextGreatest(vector<int> &vec)
{
    int size = vec.size();
    vector<int> res(size, -1);
    stack<int> st;

    for (int i = 0; i < size; i++)
    {
        while (!st.empty() && vec[st.top()] < vec[i])
        {
            res[st.top()] = vec[i];
            st.pop();
        }
        st.push(i);
    }

    return res;
}

int main()
{
    vector<int> vec = {4, 3, 2, 1, 1};
    vector<int> res = nextGreatest(vec);

    for (int i = 0; i < res.size(); i++)
        cout << res[i] << " ";
}