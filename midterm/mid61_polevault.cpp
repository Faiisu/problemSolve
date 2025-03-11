#include<iostream>
#include<map>
using namespace std;

int n, q;

map<int,int> sums, inputs;
int totals[100100], total = 0;

int main(){
    cin >> n >> q;
    for(int i = 1; i <= n ; i++){
        int input;
        cin >> input;
        inputs[i] = input;     
    }
    recur(1,0,0);
    for(int i = 0 ; i < q ; i++){
        int input;
        cin >> input;
        // cout << sums[input];
        if(sums[input] == 1) cout << "Y";
        else cout << "N";
    }
    return 0;
}