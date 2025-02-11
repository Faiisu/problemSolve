#include<iostream>
#include<vector>
#include<set>
#include<climits>
using namespace std;
int c, v;
vector<int> adj[10010], toll[10010];
int deg[10010];

void read_input(){
    cin >> c >> v;
    for(int i = 0 ; i < v ; i++){
        int a, b, w;
        cin >> a >> b >> w;
        if(w%2 != 0) continue;
        adj[a].push_back(b);
        adj[b].push_back(a);
        toll[a].push_back(w);
        toll[b].push_back(w);
        deg[a]++;
        deg[b]++;
    }
}

set<pair<int,int> > q1,q2;
bool tb2[10010], tb1[10010];
int total1[10010],total2[10010];
void dijkstra(int st){
    for(int i = 0 ; i <= c ; i++){
        tb1[i] = false;
        tb2[i] = false;
        total1[i] = INT_MAX;
        total2[i] = INT_MAX;
    }
    q1.insert(make_pair(0,st));
    total1[st] = 0;


    while(!q2.empty()){
        auto pNow = *q2.begin();
        int now = pNow.second;
        q2.erase(q2.begin());

        if(tb2[now]) continue;
        tb2[now] = true;

        for(int i = 0 ; i < deg[now] ; i++){
        int next = adj[now][i];
        int new_total = total2[now] + toll[now][i];
            if(total1[next] > new_total){
                total1[next] = new_total;
                q1.insert(make_pair(total1[next], next));
            }
        }

        while(!q1.empty()){
            auto pNow = *q1.begin();
            int now = pNow.second;
            q1.erase(q1.begin());

            if(tb1[now]) continue;
            tb1[now] = true;

            for(int i = 0 ; i < deg[now] ; i++){
                int next = adj[now][i];
                int new_total = total1[now] + toll[now][i];
                if(total2[next] > new_total){
                    total2[next] = new_total;
                    q2.insert(make_pair(total2[next], next));
                }
            }
        }

    }
}


int main(){
    read_input();
    dijkstra(1);
    cout << total1[c];
    // if(total2[c] != INT_MAX){
    //     cout << total2[c];
    // }
    // else cout << "-1";
    return 0;
}