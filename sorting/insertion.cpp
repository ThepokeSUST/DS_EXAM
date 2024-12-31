#include <iostream>
#include <vector>

using namespace std;

void insertion(vector<int> &vec, int n)
{

    for (int i = 1; i < n; i++)
    {

        int ele = vec[i];
        int j;
        for (j = i - 1; j >= 0; j--)
        {
            if (ele < vec[j])
            {
                vec[j + 1] = vec[j];
            }
            else
            {
                break;
            }
        }
        vec[j + 1] = ele;
    }
}
int main()
{

    int n;
    cin >> n;

    vector<int> vec(n);
    for (int i = 0; i < n; i++)
        cin >> vec[i];

    insertion(vec, n);
    for (auto ele : vec)
        cout << ele << " ";
}