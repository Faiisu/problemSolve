#include<iostream>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int l, n, sum = 0;
    cin >> l >> n;
    
    int l_out = 1;
    while(1){
        sum += l_out*l_out;
        if(sum > n) break;
        l_out++;
    }
    if(sum != n) l_out--;
    cout << l-l_out;
    return 0;
}