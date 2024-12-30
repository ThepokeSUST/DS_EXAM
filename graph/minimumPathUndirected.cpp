#include <climits>
#include <iostream>
#include <map>
#include <queue>
#include <vector>
using namespace std;

map<char, int> mp;
map<int, char> rmp;

void BFS(vector<vector<int>> &adj, vector<int> &visit, vector<int> &dis, int node)
{

    visit[node] = 1;

    queue<int> q;
    q.push(node);
    dis[node] = 0;
    while (!q.empty())
    {

        int par = q.front();
        q.pop();

        for (int i = 0; i < adj[par].size(); i++)
        {
            if (!visit[adj[par][i]])
            {
                visit[adj[par][i]] = 1;
                dis[adj[par][i]] = 1 + dis[par];
                q.push(adj[par][i]);
            }
        }
    }
}

vector<int> findpath(vector<vector<int>> &adj, int v)
{

    vector<int> visit(v, 0);
    vector<int> dis(v, INT_MAX);

    // from zero node
    BFS(adj, visit, dis, 0);

    for (auto ele : dis)
        cout << ele << " ";
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
    findpath(adj, v);
}