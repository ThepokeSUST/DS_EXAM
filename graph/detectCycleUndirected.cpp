#include <iostream>
#include <map>
#include <queue>
#include <vector>
using namespace std;

map<char, int> mp;
map<int, char> rmp;

bool BFS(vector<vector<int>> &adj, vector<int> &visit, int node)
{

    queue<pair<int, int>> q;
    q.push({node, -1});
    visit[node] = 1;
    while (!q.empty())
    {
        int cur = q.front().first;
        int par = q.front().second;
        q.pop();
        for (int i = 0; i < adj[cur].size(); i++)
        {
            if (!visit[adj[cur][i]])
            {
                q.push({adj[cur][i], cur});
                visit[adj[cur][i]] = 1;
            }
            else if (adj[cur][i] != par)
            {
                return true;
            }
        }
    }

    return false;
}

bool checkCycle(vector<vector<int>> adj)
{

    vector<int> visit(adj.size(), 0);

    for (int i = 0; i < adj.size(); i++)
    {
        if (!visit[i])
        {
            if (BFS(adj, visit, i))
                return true;
        }
    }
    return false;
}
int main()
{

    int v, e;
    cin >> v >> e;

    vector<vector<int>> adj(v);
    /*  vec[0].push_back(8);
      vec[1].push_back(2);
      vec[2].push_back(4);
      vec[3].push_back(1);
      vec[0].push_back(0);

      for (auto ele : vec)
      {
          for (auto elee : ele)
              cout << elee << " ";
          cout << endl;
      }
      */
    int idx = 0;
    for (int i = 0; i < e; i++)
    {

        string str;
        cin >> str;

        if (mp.find(str[0]) == mp.end())
        {
            mp[str[0]] = idx++;
            rmp[mp[str[0]]] = str[0];
        }
        if (mp.find(str[1]) == mp.end())
        {
            mp[str[1]] = idx++;
            rmp[mp[str[1]]] = str[1];
        }

        adj[mp[str[0]]].push_back(mp[str[1]]);
        adj[mp[str[1]]].push_back(mp[str[0]]);
    }

    /*for (int i = 0; i < adj.size(); i++)
    {
        cout << rmp[i] << "-> ";
        for (int j = 0; j < adj[i].size(); j++)
        {
            cout << rmp[adj[i][j]] << " ";
        }
        cout << endl;
    }*/
    cout << checkCycle(adj);
}