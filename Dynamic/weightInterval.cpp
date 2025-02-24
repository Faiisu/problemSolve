#include<iostream>
#include<map>
#include<set>
using namespace std;

int n;
map<int, pair<int, pair<int, int> > > times;

pair<int, int> main_range, sub_range;
set<int> main_set, sub_set;
int mainW = 0, subW = 0;

int main(){
    cin >> n;

    for(int i = 1; i <= n ; i++){
        int x, y , w;
        cin >> x >> y >> w;

        if(times[y].second.second < w){
            times[y].second.first = x;
            times[y].second.second = w;
            times[y].first = i;
        }
    }

    for(auto ite: times){
        int y = ite.first;
        int x = ite.second.second.first;
        int weight = ite.second.second.second;
        int i = ite.second.first;

        if(weight > mainW){
            sub_range = main_range;
            sub_set = main_set;
            subW = mainW;

            main_range.first = x;
            main_range.second = y;
            mainW = weight;
            main_set.clear();
            main_set.insert(i);
        }
        else if(subW + weight > mainW && x >= sub_range.first){
            subW += weight;
            sub_range.second = y;
            sub_set.insert(i);

            pair<int, int> tmp_range = main_range;
            set<int> tmp_set = main_set;
            int tmpW = mainW;

            main_range = sub_range;
            mainW = subW;
            main_set = sub_set;

            sub_set = tmp_set;
            subW = tmpW;
            sub_range = tmp_range;

        }

    }
    cout << mainW << "\n";
    cout << main_set.size() << "\n";
    // cout << main_range.first << " " << main_range.second <<"\n";
    for(auto i : main_set) cout << i << " ";
    return 0;
}