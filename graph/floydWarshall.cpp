#include <climits>
#include <iostream>
#include <map>
#include <queue>
#include <vector>
using namespace std;

map<char, int> mp;
map<int, char> rmp;

void floydWarshall(vector<vector<int>> &adj, int v)
{

    for (int i = 0; i < v; i++)
    {
        for (int j = 0; j < v; j++)
        {
            for (int k = 0; k < v; k++)
            {
                if (adj[i][k] != INT_MAX && adj[k][j] != INT_MAX && adj[i][j] > adj[i][k] + adj[k][j])
                    adj[i][j] = adj[i][k] + adj[k][j];
            }
        }
    }
}

int main()
{

    int v, e;
    cin >> v >> e;
    vector<vector<int>> adj(v, vector<int>(v, INT_MAX));
    for (int i = 0; i < v; i++)
    {
        adj[i][i] = 0;
    }
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

        adj[mp[str[0]]][mp[str[1]]] = cost;
    }

    floydWarshall(adj, v);

    for (auto ele : adj)
    {
        for (auto elele : ele)
        {
            cout << elele << " ";
        }
        cout << endl;
    }
}