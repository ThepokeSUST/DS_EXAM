#include <iostream>
#include <map>
#include <queue>
#include <vector>
using namespace std;

map<char, int> mp;
map<int, char> rmp;
vector<int> findDeg(vector<vector<int>> &adj, int n)
{
    vector<int> ans(n, 0);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < adj[i].size(); j++)
        {
            ans[adj[i][j]]++;
        }
    }
    return ans;
}
vector<int> khansAlgo(vector<vector<int>> &adj, int n)
{

    vector<int> inDeg = findDeg(adj, n);
    vector<int> ans;
    queue<int> q;
    for (int i = 0; i < n; i++)
    {
        if (inDeg[i] == 0)
            q.push(i);
    }

    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        ans.push_back(node);
        for (int i = 0; i < adj[node].size(); i++)
        {
            inDeg[adj[node][i]]--;
            if (inDeg[adj[node][i]] == 0)
                q.push(adj[node][i]);
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

    vector<int> vec = khansAlgo(adj, v);

    for (int i = 0; i < v; i++)
    {
        cout << rmp[vec[i]] << " ";
    }
}