#include<iostream>
#include<map>
using namespace std;

map<int,int> boats;
int main(){
    int n, m;
    cin >> n >> m;
    int cnt = 0;
    while(n--){
        int input;
        cin >> input;
        boats[input] += 1;
    }
    while(m--){
        int number;
        cin >> number;
        auto ite = boats.lower_bound(number);
        bool haveboat = false;
        while(!haveboat && ite != boats.end()){
            if(ite->second > 0){
                haveboat = true;
                boats[ite->first] -= 1;
            }
            ite++;
        }
        if(haveboat) cnt++;
        else break;
    }
    cout << cnt;
    return 0;
}