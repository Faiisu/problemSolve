#include<iostream>
using namespace std;

int main(){
    int n, inp, sum=0;
    cin >> n;
    while(n--){
        cin >> inp;
        if(inp >= 0) sum+=inp;
    }
    cout << sum;
    return 0;
}