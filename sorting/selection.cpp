#include <iostream>
#include <vector>

using namespace std;

int findidx(vector<int> &vec, int st, int en)
{
    int min = st;
    for (int i = st; i < en; i++)
    {
        if (vec[min] > vec[i])
            min = i;
    }
    return min;
}
void selection(vector<int> &vec, int n)
{

    for (int i = 0; i < n - 1; i++)
    {
        int sml = findidx(vec, i + 1, n);
        // cout << sml << endl;
        if (vec[i] > vec[sml])
        {
            swap(vec[i], vec[sml]);
        }
    }
}
int main()
{

    int n;
    cin >> n;
    vector<int> vec(n);
    for (int i = 0; i < n; i++)
        cin >> vec[i];
    selection(vec, n);

    for (auto ele : vec)
        cout << ele << " ";
}