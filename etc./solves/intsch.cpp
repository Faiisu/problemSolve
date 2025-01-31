#include<iostream>
#include<map>
#include<list>
using namespace std;
int n;

map<int,list<int> > range;
int morethanPos = 0, cnt =0;
int main(){
    cin >> n;

    while(n--){
        int st, ed;
        cin >> st >> ed;
        range[ed].push_back(st);
    }
    for(auto ite : range){
        // cout << ite.first << "| ";
        for(int n : ite.second){
            if(n >= morethanPos){
                // cout << "cnt at" << ite.first << "|" << n;
                cnt++;
                morethanPos = ite.first;
                break;
            }
        }
        // cout << endl;
    }
    cout << cnt;

    return 0;
}