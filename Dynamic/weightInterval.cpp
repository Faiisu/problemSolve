// weight interval schedule

#include<iostream>
#include<map>
#include<vector>
using namespace std;
int n;

map<int, vector<pair<int,int> > > times;
map<int, int> bf, maxW, maxS;
int yOfMax;

int main(){
    cin >> n;
    for(int i = 0; i < n ; i++){
        int x, y, w;
    cin >> x >> y >> w;
        maxW[y] = w;
        maxS[y] = 1;
        times[y].push_back(make_pair(x,w));
    }

    for(auto ite: times){
        int y = ite.first;
        for(auto it: ite.second){
            int x = it.first;
            int w = it.second;

            for(auto iter : times){
                int ty = iter.first;
                if(ty > x) continue;
                // if(ty > y) break;
                for(auto itera : iter.second){
                    int tx = itera.first;
                    int tw = itera.second;

                    if(maxW[ty] + w > maxW[y]){
                        maxW[y] = maxW[ty] + w;
                        // maxS[y]++;
                        // cout << maxS[y] << " ";
                        yOfMax = y;
                        bf[y] = ty;
                    }
                }   
            }
        }
    }
    
    for(auto ite: maxW){
        cout << ite.first << " " << ite.second << "\n";
    }

    // cout << maxW[yOfMax] << " " << maxS[yOfMax];
    return 0;
}