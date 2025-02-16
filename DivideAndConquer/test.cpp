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

void merge(int arr[],
    int xl, int xr,
    int yl, int yr,
    int buffer[])
{
    if((xl > xr) && (yl > yr)){
        return;
    }

    if (xl > xr){
        buffer[0] = arr[yl];
        merge(arr, xl, xr, yl + 1, yr, buffer + 1);
        return;
    }
    if (yl > yr){
        buffer[0] = arr[xl];
        merge(arr, xl + 1, xr, yl, yr, buffer + 1);
        return;
    }

    if (arr[xl] <= arr[yl]){
        buffer[0] = arr[xl];
        merge(arr, xl + 1, xr, yl, yr, buffer + 1);
    }
    else{
        buffer[0] = arr[yl];
        merge(arr, xl, xr, yl + 1, yr, buffer + 1);
    }

}

void copyarray(int src[], int desc[], int n)
{
    // NOTES: you may see this as an example to implement merge
    if(n==0) return;
    desc[0] = src[0];
    copyarray(src + 1, desc + 1, n - 1);
}

void mergesort(int arr[], int l, int r)
{
    if(l >= r)
    return;

    int mid = (l + r) / 2;
    mergesort(arr, l, mid);
    mergesort(arr, mid + 1, r);

    merge(arr, l, mid, mid + 1, r, buffer);
    copyarray(buffer, &arr[l], r - l + 1);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    read_input();

    mergesort(a,0,n-1);

    for(int i = 0; i < n; i++) {
        cout << a[i] << "\n";
    }
}