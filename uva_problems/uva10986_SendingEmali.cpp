#include<iostream>
#include<set>
#include<vector>
#include<climits>
using namespace std;

vector<int> adj[20010], lat[20010];
int deg[20010];

int n,m,s,t;
void read_input(){
    cin >> n >> m >> s >> t;
    for(int i = 0 ; i < m ; i++){
        int a, b, c;
        cin >> a >> b >> c;
        adj[a].push_back(b);
        adj[b].push_back(a);
        lat[a].push_back(c);
        lat[b].push_back(c);
        deg[a]++;
        deg[b]++;
    }
}

set<pair<int,int> > q;
int dis[20010];
bool tb[20010];

void dijkstra(int st){
    for(int i = 0 ; i<=n;i++){
        tb[i] = false;
        dis[i] = INT_MAX;
    }
    q.insert(make_pair(0,st));
    dis[st] = 0;

    while(!q.empty()){
        auto p_now = *q.begin();
        int now = p_now.second;
        q.erase(q.begin());
        if(tb[now]) continue;
        tb[now] = true;

        for(int i = 0 ; i < deg[now] ; i++){
            int next = adj[now][i];
            int new_dis = dis[now] + lat[now][i];
            if(dis[next] > new_dis){
                dis[next] = new_dis;
                q.insert(make_pair(dis[next],next));
            }
        }
    }
}

int main(){
    int tc;
    cin >> tc;
    for(int i = 1 ; i<=tc;i++){
        read_input();
        dijkstra(s);

        for(int ii = 0 ; ii <= n ; ii++){
            deg[ii] = 0;
            adj[ii].clear();
            lat[ii].clear();
        }
        
        printf("Case #%d: ", i);
        if(dis[t] != INT_MAX) cout << dis[t] << "\n";
        else cout << "unreachable\n";
    }
    return 0;
}