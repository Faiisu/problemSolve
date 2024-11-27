#include<iostream>
#include<climits>
using namespace std;

int main(){
    int price[4];
    int price_sum[] = {0,0,0,0};
    int type, _min = INT_MAX;
    int n;

    for(int i = 1 ; i < 4 ; i++) cin >> price[i];
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> type;
        price_sum[type] += price[type];
    }
    for(int i = 1; i < 4; i++){
        if(price_sum[i] < _min) _min = price_sum[i];
    }
    cout << _min;
    return 0;
}