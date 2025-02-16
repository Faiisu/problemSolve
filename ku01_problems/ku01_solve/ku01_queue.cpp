#include<iostream>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, l, adds[100010], input;
    int max = 0;
    cin >> n >> l;
    for(int i = 1 ; i <= n ; i++){
        cin >> input;
        if(input > max){
            adds[i] = 0;
            max = input;
        }
        else adds[i] = max-input+1;   
        // cout << "adds: " << adds[i];     
    }
    while(l--){
        cin >> input;
        cout << adds[input] << "\n";
    }
    return 0;
}