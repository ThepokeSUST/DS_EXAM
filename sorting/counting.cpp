#include <iostream>
#include <vector>

using namespace std;

int getMax(vector<int> &vec, int n)
{
    int max = vec[0];

    for (int i = 0; i < n; i++)
    {
        if (vec[i] > max)
            max = vec[i];
    }
    return max;
}
vector<int> getfrq(vector<int> &vec, int n, int max)
{

    vector<int> frq(max, 0);
    for (int i = 0; i < n; i++)
        frq[vec[i]]++;

    return frq;
}
vector<int> counting(vector<int> &vec, int n)
{
    int max = getMax(vec, n);
    //  cout << max << endl;
    max++;
    vector<int> frq = getfrq(vec, n, max);
    for (int i = 1; i < max; i++)
    {
        frq[i] += frq[i - 1];
    }

    vector<int> ans(n);

    for (int i = n - 1; i >= 0; i--)
    {

        ans[--frq[vec[i]]] = vec[i];
    }
    return ans;
}
int main()
{

    int n;
    cin >> n;

    vector<int> vec(n);

    for (int i = 0; i < n; i++)
        cin >> vec[i];

    vector<int> ans = counting(vec, n);

    for (auto ele : ans)
        cout << ele << " ";
}