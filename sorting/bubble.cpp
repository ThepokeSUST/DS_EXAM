#include <iostream>
#include <vector>

using namespace std;

void bubble(vector<int> &vec, int n)
{

    int idx = 0;

    while (idx < n - 1)
    {
        int cnt = 0;
        for (int i = 0; i < n - idx - 1; i++)
        {
            if (vec[i] > vec[i + 1])
            {
                swap(vec[i], vec[i + 1]);
                cnt++;
            }

            // cout << idx << " for loop\n";
        }
        if (cnt == 0)
            break;

        idx++;
    }
}

int main()
{
    int n;
    cin >> n;
    vector<int> vec(n);

    for (int i = 0; i < n; i++)
        cin >> vec[i];
    bubble(vec, n);

    for (auto ele : vec)
        cout << ele << " ";
}