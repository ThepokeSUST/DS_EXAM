#include <iostream>
#include <vector>

using namespace std;

void merge(vector<int> &vec, int ast, int mid, int en)
{
    int bst = mid + 1;
    vector<int> A(mid - ast + 1);
    vector<int> B(en - mid);
    int idx = 0;
    for (int i = ast; i <= mid; i++)
        A[idx++] = vec[i];
    idx = 0;
    for (int i = mid + 1; i <= en; i++)
        B[idx++] = vec[i];

    idx = ast;
    ast = 0;
    bst = 0;
    mid = A.size();
    en = B.size();

    while (ast < mid && bst < en)
    {
        if (A[ast] < B[bst])
        {
            vec[idx++] = A[ast++];
        }
        else
        {
            vec[idx++] = B[bst++];
        }
    }
    if (ast < mid)
    {
        while (ast < mid)
        {
            vec[idx++] = A[ast++];
        }
    }
    if (bst < en)
    {
        while (bst < en)
        {
            vec[idx++] = B[bst++];
        }
    }
}
void divide(vector<int> &vec, int st, int en)
{
    if (st == en)
        return;

    int mid = st + (en - st) / 2;

    divide(vec, st, mid);
    divide(vec, mid + 1, en);

    merge(vec, st, mid, en);
}
int main()
{
    int n;
    cin >> n;
    vector<int> vec(n);

    for (int i = 0; i < n; i++)
        cin >> vec[i];

    divide(vec, 0, n - 1);

    for (auto ele : vec)
        cout << ele << " ";
}