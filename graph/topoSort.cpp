#include <iostream>
#include <map>
#include <stack>
#include <vector>
using namespace std;
map<char, int> mp;
map<int, char> rmp;

void DFS(vector<vector<int>> &adj, vector<int> &visit, int node, stack<int> &st)
{

    visit[node] = 1;

    for (int i = 0; i < adj[node].size(); i++)
    {

        if (!visit[adj[node][i]])
            DFS(adj, visit, adj[node][i], st);
    }

    st.push(node);
}

void topoSort(vector<vector<int>> &adj, int v, stack<int> &st)
{

    vector<int> visit(v, 0);

    for (int i = 0; i < v; i++)
    {
        if (!visit[i])
            DFS(adj, visit, i, st);
    }
}
int main()
{
    int v, e;
    cin >> v >> e;
    vector<vector<int>> adj(v);
    int idx = 0;
    for (int i = 0; i < e; i++)
    {
        string str;
        cin >> str;

        if (mp.find(str[0]) == mp.end())
        {
            mp[str[0]] = idx;
            rmp[idx++] = str[0];
        }
        if (mp.find(str[1]) == mp.end())
        {
            mp[str[1]] = idx;
            rmp[idx++] = str[1];
        }

        adj[mp[str[0]]].push_back(mp[str[1]]);
    }

    stack<int> st;
    topoSort(adj, v, st);

    while (!st.empty())
    {
        cout << rmp[st.top()] << " ";
        st.pop();
    }
}