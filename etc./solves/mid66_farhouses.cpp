#include<iostream>
#include<vector>
#include<map>
using namespace std;

int n, k, l;
vector<int> house_diff_sum;
map<int,int> houses;
int main(){
    cin >> n >> k >> l;
    int range = k+l;
    for(int i = 1 ; i <= n ; i++){
        int input;
        cin >> input;
        houses[input] = 1;
    }

    int bf = -1;
    int total = 0;
    house_diff_sum.push_back(0);
    for(auto house: houses){
        int house_lo = house.first;
        int diff;
        if(bf == -1){
            bf = house_lo;
            continue;   
        }
        else diff = house_lo - bf;
        bf = house_lo;
        total += diff;
        house_diff_sum.push_back(total); 
    }

    int maxl = 0;
    for(int i = 1 ; i < house_diff_sum.size()-range+1 ;i++){
        int diff = house_diff_sum[i+range-1] - house_diff_sum[i-1];
        maxl = diff>maxl? diff:maxl;
    }
    cout << maxl;
    return 0;
}