#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int findCeleb(vector<vector<int>> &vec, int n)
{

    stack<int> st;

    for (int i = 0; i < n; i++)
        st.push(i);

    while (st.size() > 1)
    {
        int f = st.top();
        st.pop();
        int s = st.top();

        // cout << f << " " << s << endl;
        st.pop();

        if (vec[f][s] && !vec[s][f])
            st.push(s);
        else if (!vec[f][s] && vec[s][f])
            st.push(f);
    }
    if (st.empty())
        return -1;

    int ele = st.top();
    for (int i = 0; i < n; i++)
    {
        if (i != ele)
            if (vec[i][ele] != 1)
                return -1;
    }
    return ele;
}
int main()
{
    int n;
    cin >> n;
    vector<vector<int>> vec(n, vector<int>(n));

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> vec[i][j];

    cout << findCeleb(vec, n);
}