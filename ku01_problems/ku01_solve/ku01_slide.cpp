#include<iostream>
using namespace std;

int main(){
    int n, arr[310], cnt=0;
    cin >> n;
    for(int i = 0 ; i < n ; i++){
        cin >> arr[i];
        for(int j = i; j >= 0; j--){
            if(arr[j] < arr[i]) cnt++;
        }
    }

    cout << cnt;
    return 0;
}