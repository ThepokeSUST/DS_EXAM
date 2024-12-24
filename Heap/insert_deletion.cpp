#include <iostream>
#include <vector>

using namespace std;

class Heap
{
public:
    int size;
    int idx;
    int *arr;

    Heap(int n)
    {
        size = n;
        idx = -1;
        arr = new int[size];
    }

    void insert(int ele)
    {
        idx++;
        if (idx == size)
            return;

        arr[idx] = ele;
        int child = idx;

        while (child > 0 && arr[(child - 1) / 2] < arr[child])
        {
            swap(arr[(child - 1) / 2], arr[child]);
            child = (child - 1) / 2;
        }
    }
    void display()
    {

        int i = 0;
        for (; i <= idx; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
    void heapify(int index)
    {

        int left = index * 2 + 1;
        int right = index * 2 + 2;
        int idx = index;
        // cout << left << endl
        //    << right << endl;
        if (left <= this->idx && arr[left] > arr[idx])
            idx = left;
        if (right <= this->idx && arr[right] > arr[idx])
            idx = right;

        //    cout << idx << endl;
        if (idx != index)
        {
            swap(arr[idx], arr[index]);
            heapify(idx);
        }
    }
    void deleteEle()
    {
        if (idx == -1)
            return;

        arr[0] = arr[idx];
        idx--;
        if (idx == 0)
            return;

        heapify(0);
    }
};
int main()
{
    int n;
    // cin>>n;
    n = 5;
    Heap h(n);
    h.insert(5);
    h.insert(7);
    h.insert(34);
    h.display();
    h.insert(20);
    h.display();

    h.deleteEle();
    h.display();
    h.deleteEle();
    h.display();
}
