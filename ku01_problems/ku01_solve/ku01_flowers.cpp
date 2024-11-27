#include<iostream>
using namespace std;

int handle_one(int n){
    int cnt = 0, round = 0;
    while(cnt < n){
        round++;
        cnt += round;
    }
    return round;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int l, n, conner = 0, sum = 0, l_base;
    cin >> l >> n;
    if(l == 1){
        cout << handle_one(n);
        return 0;
    }
    for(int i = 1 ; i <= l ; i++) conner+=i;
    int round = 0; 
    while(sum < n){
        sum += (l*round) + sum + conner;
        round++;
    }
    cout << round;
    return 0;
}