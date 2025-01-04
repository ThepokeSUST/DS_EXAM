#include <climits>
#include <iostream>
#include <map>
#include <queue>
#include <vector>
using namespace std;

map<char, int> mp;
map<int, char> rmp;

void bellman(vector<vector<pair<int, int>>> &adj, int v)
{
    vector<int> dis(v, INT_MAX);
    dis[0] = 0;
    for (int i = 0; i < v - 1; i++)
    {
        int chk2 = 0;
        for (int j = 0; j < v; j++)
        {
            int chk = 1;
            for (int k = 0; k < adj[j].size(); k++)
            {
                int node = adj[j][k].first;
                int cost = adj[j][k].second;

                if (dis[j] != INT_MAX && dis[j] + cost < dis[node])
                {
                    chk = 0;
                    dis[node] = dis[j] + cost;
                }
            }
            if (chk)
            {
                chk2 = 1;
                break;
            }
        }
        if (chk2)
            break;
    }

    for (int i = 0; i < v; i++)
    {
        for (int j = 0; j < adj[i].size(); j++)
        {
            int node = adj[i][j].first;
            int cost = adj[i][j].second;
            if (dis[i] != INT_MAX && dis[i] + cost < dis[node])
            {
                cout << "nagetive cycle present\n";
                return;
            }
        }
    }
    for (auto ele : dis)
        cout << ele << " ";
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
        //  adj[mp[str[1]]].push_back(mp[str[0]]);
    }

    bellman(adj, v);
}