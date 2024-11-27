#include<iostream>
#include<climits>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    long long arr[100010], cnt = 0;
    int n, k, _min = INT_MAX, diff = 0;

    cin >> n >> k;
    for(int i = 1 ; i <= n ; i++){
        cin >> arr[i];
        if(arr[i] < _min) _min = arr[i];
    }
    for(int i = 1; i <= n ; i++){
        diff = arr[i]-_min;
        if(diff == 0) continue;
        if(diff * k >= arr[i]) cnt++;
    }
    cout << n-cnt;

    return 0;
}