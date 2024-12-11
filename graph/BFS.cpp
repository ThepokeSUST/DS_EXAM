#include <iostream>
#include <map>
#include <queue>
#include <vector>
using namespace std;

map<char, int> mp;
map<int, char> rmp;

vector<int> BFS(vector<vector<int>> &adj, vector<int> &visit, vector<int> &ans, int node)
{

    queue<int> q;
    q.push(node);
    visit[node] = 1;
    //  vector<int> ans;
    while (!q.empty())
    {
        int cur = q.front();
        q.pop();
        ans.push_back(cur);
        for (int i = 0; i < adj[cur].size(); i++)
        {
            if (!visit[adj[cur][i]])
            {
                q.push(adj[cur][i]);
                visit[adj[cur][i]] = 1;
            }
        }
    }

    return ans;
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
            BFS(adj, visit, ans, i);

    for (auto ele : ans)
        cout << rmp[ele] << " ";
}