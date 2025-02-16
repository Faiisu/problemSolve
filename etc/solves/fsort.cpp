#include<iostream>
#include<list>
using namespace std;

int cnt[1000010];
int main(){
    int n, inp;
    list<int> mem_num;
    cin >> n;
    while(n--){
        cin >> inp;
        
    }
    for(int i = 1; i <= 100000 ; i++){
        if(cnt[i] != 0){
            cout << i << " " << cnt[i]<<endl;
        }
    }
    return 0;
}