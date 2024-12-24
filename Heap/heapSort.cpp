#include <iostream>
#include <vector>
using namespace std;

void heapify(vector<int> &vec, int st, int size)
{
    int left = st * 2 + 1;
    int right = st * 2 + 2;
    int large = st;

    if (left < size && vec[left] > vec[large])
        large = left;
    if (right < size && vec[right] > vec[large])
        large = right;

    if (large != st)
    {
        swap(vec[large], vec[st]);
        heapify(vec, large, size);
    }
}
void build(vector<int> &vec, int size)
{

    int idx = size / 2 - 1;

    for (int i = idx; i >= 0; i--)
    {
        heapify(vec, i, size);
    }
}

void heapSort(vector<int> &vec, int size)
{

    int idx = size;

    while (idx > 0)
    {
        idx--;
        swap(vec[idx], vec[0]);
        heapify(vec, 0, idx);
    }
}

int main()
{
    int n;
    cin >> n;
    vector<int> vec(n);

    for (int i = 0; i < n; i++)
        cin >> vec[i];
    build(vec, n);
    for (auto ele : vec)
        cout << ele << " ";
    cout << endl;
    heapSort(vec, n);
    for (auto ele : vec)
        cout << ele << " ";
}