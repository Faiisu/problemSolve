#include<iostream>
using namespace std;

int main(){
    int N ,L, l = 0, cnt = 0;
    cin >> N >> L;
    while(N--){
        int x, y;
        cin >> x >> y;
        if(l >= y) continue;
        l = x+L;
        cnt++;
    }
    cout << cnt;
    return 0;
}