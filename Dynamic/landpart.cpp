

#include<iostream>
using namespace std;

int maxs[1010], mems[1010];
int main(){
    int n;
    cin >> n;
    maxs[0] = 0;
    for(int i = 1 ; i <= n ; i++){
        int inp;
        cin >> inp;
        if(inp > maxs[i-1]){
            maxs[i] = inp;
        }
        else maxs[i] = maxs[i-1];
    }
    for(int i = 1; i <= n ; i++) cout << maxs[i] << " ";
    return 0;
}