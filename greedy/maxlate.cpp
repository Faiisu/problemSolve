#include<iostream>
#include<map>
#include<list>
using namespace std;

int n, timecnt = 0;
map< int, list<int> > dlines;

int main(){
    cin >> n;
    int maximum = 0;
    for(int i = 0; i < n ; i++){
        int dl , t;
        cin >> dl >> t;
        dlines[dl].push_back(t);
    }
    int dayCnt = 0;
    int maxfee = 0;
    for(auto dl : dlines){
        for(int day : dl.second){
            dayCnt += day;

            int overtime = dayCnt - dl.first;
            if(overtime > 10){
                int fee = (overtime-10)*1e3;
                maxfee = fee>maxfee?fee:maxfee;
            }
        }
    }
    cout << maxfee;
    // cout << maximum;
    return 0;
}