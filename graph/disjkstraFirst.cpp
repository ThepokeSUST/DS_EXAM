#include <climits>
#include <iostream>
#include <map>
#include <queue>
#include <vector>
using namespace std;

map<char, int> mp;
map<int, char> rmp;

// disjkstra does work on negative waight......
void disjkstra(vector<vector<pair<int, int>>> &adj, int node, int v)
{

    vector<bool> visit(v, 0);
    vector<int> parent(v, -1);
    vector<int> dis(v, INT_MAX);
    dis[node] = 0;
    int n = v;
    int cnt = 0;
    while (v--)
    {

        int idx = -1;
        int large = INT_MAX;

        cnt++;
        for (int i = 0; i < n; i++)
        {
            if (!visit[i] && large > dis[i])
            {
                idx = i;
                large = dis[i];
            }
        }
        if (idx == -1)
            break;
        visit[idx] = 1;
        for (int i = 0; i < adj[idx].size(); i++)
        {
            int newnode = adj[idx][i].first;
            int cost = adj[idx][i].second;
            if (!visit[newnode] && dis[newnode] > dis[idx] + cost)
            {
                parent[newnode] = idx;
                dis[newnode] = dis[idx] + cost;
            }
        }
    }

    for (auto ele : dis)
        cout << ele << " ";

    // cout << endl
    //<< cnt << endl;
}

int main()
{

    int v, e;
    cin >> v >> e;
    vector<vector<pair<int, int>>> adj(v);
    int idx = 0;
    for (int i = 0; i < e; i++)
    {

        string str;
        cin >> str;
        int cost;
        cin >> cost;
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

        adj[mp[str[0]]].push_back({mp[str[1]], cost});
        // adj[mp[str[1]]].push_back(mp[str[0]]);
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
    disjkstra(adj, 0, v);
}