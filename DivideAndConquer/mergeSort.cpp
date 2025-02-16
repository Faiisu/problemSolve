#include <iostream>
#include <vector>

using namespace std;

const int MAX_N = 100010;

int n;
int buffer[MAX_N];
int a[MAX_N];

void read_input()
{
    cin >> n;
    for(int i = 0; i < n; i++) {
    cin >> a[i];
    }
}


void merge(int arr[], int l, int mid, int r, int buffer[]) {
    int i = l, j = mid + 1, k = 0;
    
    while (i <= mid && j <= r) {
        if (arr[i] <= arr[j]) buffer[k++] = arr[i++];
        else buffer[k++] = arr[j++];
    }

    while (i <= mid) buffer[k++] = arr[i++];
    while (j <= r) buffer[k++] = arr[j++];

    for (i = 0; i < k; i++) arr[l + i] = buffer[i]; 
}


void mergesort(int arr[], int l, int r, int buffer[])
{
    if (l >= r) return;

    int mid = (l + r) / 2;
    mergesort(arr, l, mid, buffer);
    mergesort(arr, mid + 1, r, buffer);

    merge(arr, l, mid, r, buffer);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    read_input();

    mergesort(a,0,n-1, buffer);

    for(int i = 0; i < n; i++) {
        cout << a[i] << "\n";
    }
    return 0;
}