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
    /*for(auto ele:nextsmall) cout<<ele<<" ";
    cout<<endl;
    for(auto ele: prevsmall) cout<<ele<<" ";
    cout<<endl;*/
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

int largestRectOn2DVector(vector<vector<int>> vec)
{
    // int n=vec.size():
    int n = vec.size();
    int m = vec[0].size();

    vector<int> V(m, 0);

    int ans = 0;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (vec[i][j] == 0)
                V[j] = 0;
            else
                V[j] = V[j] + vec[i][j];
        }
        /*for(auto ele:V){
        cout<<ele<<" ";
        }
        cout<<endl;*/
        ans = max(ans, largestRect(V));
    }

    return ans;
}

int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> vec(n, vector<int>(m));

    for (auto &ele : vec)
    {
        for (auto &eleele : ele)
        {
            cin >> eleele;
        }
    }

    for (auto ele : vec)
    {

        for (auto eleele : ele)
        {
            cout << eleele << " ";
        }
        cout << endl;
    }

    // cout<<vec.size();
    // cout<<vec[0].size();
    cout << largestRectOn2DVector(vec);
}