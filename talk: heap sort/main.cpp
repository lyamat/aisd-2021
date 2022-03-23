#include <iostream>

using namespace std;

void printArray(int arr[], int n)
{
    for (int i=0; i<n; ++i)
        cout << arr[i] << " ";
    cout << "\n";
}

void heapify(int arr[], int n, int i)
{
    int largest = i;

    int l = 2*i + 1;
    int r = 2*i + 2;

    if (l < n && arr[l] > arr[largest])
        largest = l;

    if (r < n && arr[r] > arr[largest])
        largest = r;

    if (largest != i)
    {
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}

void heapSort(int arr[], int n)
{
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    for (int i=n-1, tmp = 1; i>=0; i--, tmp++)
    {
        swap(arr[0], arr[i]);

        cout << "sort ["<< tmp << "] : ";
        printArray(arr,n);
        cout << endl;

        heapify(arr, i, 0);

        cout << "balanced: ";
        printArray(arr,n);
        cout << endl;
    }
}

int main()
{
    int arr[] = {12,7, 2, 5, 6, 13};

    int n = sizeof(arr)/sizeof(arr[0]);

    cout << "Start arr:" << endl;

    printArray(arr, n);

    cout << endl;

    heapify(arr, n, 0);

    heapSort(arr, n);

    printArray(arr, n);
/*
    heapSort(arr, n);

    cout << "�fter sorting \n";
    printArray(arr, n);
*/
}
