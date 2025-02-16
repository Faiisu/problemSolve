#include<iostream>
#include<vector>
#include<set>

const int MAX_N = 100010;

using namespace std;
int n, m;
vector<int> adj[MAX_N];
vector<int> weights[MAX_N];
int deg[MAX_N];

void read_input(){
    cin >> n >> m;
    for(int i = 1 ; i <= n ; i++) deg[i] = 0;
    for(int i = 1; i<= m; i++){
        int a,b,w;
        cin >> a >> b >> w;
        adj[a].push_back(b);
        adj[b].push_back(a);
        weights[a].push_back(w);
        weights[b].push_back(w);
        deg[a]++;
        deg[b]++;
    }
}

const int inf = 1e9;
bool tb[MAX_N];
set< pair<int,int> > q;
int dis[MAX_N];

void dijkstra(int st){
    for(int i = 1; i<= n ; i++){
        dis[i] = inf;
        tb[i] = false;
    }
    dis[st] = 0;
    q.insert(make_pair(0,st));

    while(!q.empty()){
        auto ite_now = *q.begin();
        q.erase(q.begin());
        int now = ite_now.second;
        if(tb[now]) continue;
        tb[now] = true;

        for(int i = 0 ; i < deg[now] ; i++){
            int next = adj[now][i];
            if(dis[next] > dis[now] + weights[now][i]){
                dis[next] = dis[now] + weights[now][i];
                q.insert(make_pair(dis[next],next));
            }
        }
    }
}

int main(){
    read_input();
    dijkstra(1);
    cout << dis[n] << endl;
    return 0;
}