#include<iostream>
#include<limits.h>
using namespace std;

int tb[100100];

int countPath(int num, int *arr,int cnt, int check){
    if(tb[num] == check) return INT_MAX;
    if(arr[num] == check) return cnt;
    tb[num] = 1;
    return countPath(arr[num], arr, cnt+1, check);
}

int main(){
    int n, cnt, _max = -1;
    int arr[100100];
    cin >> n;

    for(int i = 1 ; i<=n;i++) cin >> arr[i];
    for(int i = 1; i <= n ; i++){
        if(tb[i] == 1) continue;
        cnt = countPath(i, arr, 1, i);
        if(cnt > _max) _max = cnt;
    }
    cout << _max;

    return 0;
}
