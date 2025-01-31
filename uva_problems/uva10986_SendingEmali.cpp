#include<iostream>
#include<vector>
#include<set>
#include<climits>
using namespace std;

int n, m, s, t;
vector<int> adj[20010],weights[20010];
int deg[20010];


void read_input(){
    cin >> n >> m >> s >> t;
    for(int i = 0 ; i < m ; i++){
        int st, end, lat;
        cin >> st >> end >> lat;
        adj[st].push_back(end);
        adj[end].push_back(st);
        weights[st].push_back(lat);
        weights[end].push_back(lat);
        deg[st]++;
        deg[end]++;
    }
}

bool tb[20010];
int dis[20010];
set< pair<int,int> > q;
void dijkstra(int st){
    for(int i = 0 ; i <= n ; i++){
        dis[i] = INT_MAX;
        tb[i] = false;
    }
    dis[st] = 0;
    q.insert(make_pair(0,st));

    while(!q.empty()){
        auto ad_now = *q.begin();
        q.erase(q.begin());
        int now = ad_now.second;
        if(tb[now]) continue;
        tb[now] = true;

        for(int i = 0 ; i < deg[now] ; i++){
            int next = adj[now][i];
            int new_dis = dis[now] + weights[now][i];
            if(dis[next] > new_dis){
                dis[next] = new_dis;
                q.insert(make_pair(dis[next],next));
            }

        }

    }
}

int main(){
    int testcase;
    cin >> testcase;
    for(int i = 1; i <= testcase ;i++){
        read_input();
        dijkstra(s);

        cout << "Case #" << i << ": ";
        if(dis[t] != INT_MAX) cout << dis[t];
        else cout << "unreachable";
        cout << "\n";
        for(int i = 0 ; i < n; i++){
            adj[i].clear();
            deg[i] = 0;
        }
    }

    return 0;
}
