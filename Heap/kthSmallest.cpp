#include <iostream>
#include <queue>
#include <vector>

using namespace std;

// for merge sort
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
// for marge sort divide role
void divide(vector<int> &vec, int st, int en)
{
    if (st == en)
        return;

    int mid = st + (en - st) / 2;

    divide(vec, st, mid);
    divide(vec, mid + 1, en);

    merge(vec, st, mid, en);
}

void solve1(vector<int> &vec)
{
    int k;
    cin >> k;
    // sort array by merge sort......
    divide(vec, 0, vec.size() - 1);

    k--;
    cout << vec[k] << endl;
}

void solve2(vector<int> &vec)
{

    int k;
    cin >> k;

    priority_queue<int, vector<int>, greater<int>> q;

    for (int i = 0; i < vec.size(); i++)
        q.push(vec[i]);

    while (k--)
    {
        q.pop();
    }
    cout << q.top() << endl;
}

void heapify(vector<int> &heap, int node, int size)
{
    if (size == 1)
        return;

    int left = node * 2 + 1;
    int right = node * 2 + 2;
    int large = node;
    //   cout << "heapify\n";
    if (left < size && heap[left] > heap[large])
        large = left;
    if (right < size && heap[right] > heap[large])
        large = right;

    if (large != node)
    {
        swap(heap[large], heap[node]);
        heapify(heap, large, size);
    }
}

void buildheap(vector<int> &heap)
{
    int size = heap.size();

    int idx = size / 2 - 1;
    //   cout << "out\n";
    for (int i = idx; i >= 0; i--)
    {
        //      cout << "in\n";
        heapify(heap, i, size);
    }
}

void solve3(vector<int> &vec)
{
    int k;
    cin >> k;

    vector<int> heap;
    for (int i = 0; i < k; i++)
        heap.push_back(vec[i]);
    buildheap(heap);
    // for (auto ele : vec)
    //     cout << ele << " ";

    //  cout << "jj\n";
    for (int i = k; i < vec.size(); i++)
    {
        //   cout << "koko";
        if (heap[0] < vec[i])
            continue;

        heap[0] = vec[i];
        heapify(heap, 0, k);
    }
    //  cout << "ans\n";
    cout << heap[0] << endl;
}
int main()
{
    int n;
    cin >> n;

    vector<int> vec(n);

    for (int i = 0; i < n; i++)
        cin >> vec[i];

    // solve1(vec);
    // solve2(vec);
    solve3(vec);
}