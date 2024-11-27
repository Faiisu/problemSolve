#include<iostream>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, now, before, cnt = 0;
    bool beforeIsNest = false;
    cin >> n;

    before = -1;
    for(int i = 0; i < n ; i++){
        cin >> now;
        if(now > before){
            if(beforeIsNest==false){
                cnt++;
                beforeIsNest = true;
            }
        }
        else beforeIsNest = false;
        before = now;
    }
    cout << cnt;
    return 0;
}