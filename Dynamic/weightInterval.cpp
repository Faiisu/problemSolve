#include<iostream>
#include<map>
#include<set>

using namespace std;
int n;

map<int, set< pair<int, pair<int,int> > > > times;
//y, weight, x, i
set< pair<int, pair<int ,pair< int, int> > > > totals;
//weight, size, x, y
int main(){
    cin >> n;
    for(int i = 1 ; i <= n ; i++){
        int x, y, w;
        cin >> x >> y >> w;
        times[y].insert(make_pair(w, make_pair(x,i)));
    }

    for(auto ite : times){
        int y = ite.first;
        for(auto rit = ite.second.rbegin(); rit!= ite.second.rend(); ++rit){
            int w = rit->first;
            int x = rit->second.first;
            int i = rit->second.second;
            
            for(auto total = totals.rbegin(); total!=totals.rend(); ++total){
                int t_w = total->first;
                int t_size = total->second.first;
                int t_x = total->second.second.first;
                int t_y = total->second.second.second;

                if(x >= t_x){
                    
                }
            }
        }

    }
    return 0;
}