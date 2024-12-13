#include <iostream>
#include <map>
#include <queue>
#include <vector>
using namespace std;

map<char, int> mp;
map<int, char> rmp;

void DFS(vector<vector<int>> &adj, vector<int> &visit, int node, vector<int> &ans)
{

    ans.push_back(node);
    visit[node] = 1;
    for (int i = 0; i < adj[node].size(); i++)
        if (!visit[adj[node][i]])
            DFS(adj, visit, adj[node][i], ans);
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
        adj[mp[str[1]]].push_back(mp[str[0]]);
    }

    // printing adj list......
    /*
     for (int i = 0; i < v; i++)
      {
          cout << i << "->";
          for (int j = 0; j < adj[i].size(); j++)
          {
              cout << adj[i][j] << " ";
          }
          cout << endl;
      }
    */
    vector<int> visit(v, 0);
    vector<int> ans;
    for (int i = 0; i < v; i++)
        if (!visit[i])
            DFS(adj, visit, i, ans);

    for (int i = 0; i < v; i++)
    {
        cout << ans[i] << " ";
    }
}