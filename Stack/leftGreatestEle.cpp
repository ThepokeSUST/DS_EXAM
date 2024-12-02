#include <iostream>
#include <stack>
#include <vector>
using namespace std;

vector<int> firstWay(vector<int> &vec)
{

    int n = vec.size();
    vector<int> res(n, -1);
    stack<int> st;
    for (int i = n - 1; i >= 0; i--)
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
    vector<int> vec = {4, 3, 2, 1, 5};
    vector<int> res = firstWay(vec);

    for (auto ele : res)
        cout << ele << " ";
}