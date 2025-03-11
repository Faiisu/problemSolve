#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

int main(){
    int n, m;
    cin >> n;
    vector<pair<int,int>> point;
    vector<pair<int,int>> output;
    vector<int> interval;
    for(int i = 0; i<n; i++){
        cin >> m;
        int a, b;
        while(cin >> a >> b && !(a == 0 && b == 0)){ 
            point.push_back({a,b});
        }
        sort(point.begin(), point.end(), [](const pair<int, int> &a, const pair<int, int> &b) {
            if (a.first != b.first)
                return a.first < b.first;
            return a.second > b.second; 
        });

        // for(auto& p : point){
        //     cout << p.first << " " << p.second << endl;
        // }

        int start = 0;
        int it = 0;
        while(it < point.size() && start < m){
            if (point[it].first > start){
                interval.clear();
                break;
            }

            int coverage = point[it].second;
            int index = it;
            for(int a = it+1; a<point.size(); a++){
                //cout << point[it+1].second << " " << coverage << endl;
                if(point[a].second > coverage && point[a].first <= start){
                    coverage = point[a].second;
                    index = a;
                }
            }
            interval.push_back(index);
            start = coverage;
            it++;
        }
        if(start < m){
            cout << "0" << endl;
        }
        else{
            cout << interval.size() << endl;
            for(int j: interval){
                cout << point[j].first << " " << point[j].second << endl;
            }
        }
        cout << endl;
        point.clear();
        interval.clear();
    }
}