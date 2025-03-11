#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int l, n, g;
vector<int> weight;

int main(){
    int plate = 0;
    cin >> l >> n >> g;
    while(l--){
        weight.clear();
        int total = 0;
        for(int i = 0 ; i < n ; i++){
            int inp;
            cin >> inp;
            weight.push_back(inp);         
        }
        sort(weight.begin(), weight.end());
        for(auto w : weight){
            if(total + w > g) continue;
            total += w;
            plate++;
        }
    }
    cout << plate;

    return 0;
}