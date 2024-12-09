#include<iostream>
using namespace std;

int mem[10000010];
int main(){
    int n, cnt = 0, sum;
    int arr[110];
    cin >> n;
    for(int i = 0 ; i < n ; i++) cin >> arr[i];
    for(int i = 0 ; i < n ; i++){
        sum = 0;
        for(int j = i; j < n ; j++){
            if(mem[arr[j]] != 1){
                cnt++;
                mem[arr[j]] = 1;
            }
            sum += arr[j];
            if(mem[sum] != 1){
                cnt++;
                mem[sum] = 1;
            }
        }
    }
    cout << cnt;
    return 0;
}