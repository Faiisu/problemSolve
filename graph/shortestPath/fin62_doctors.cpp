#include<iostream>
#include<vector>
#include<set>

using namespace std;

const int MAX_N = 100010;
const int inf = 1e10;

int p[MAX_N];
vector<int> adj[MAX_N], weights[MAX_N];
int n, m, l;
int deg[MAX_N];

void read_input(){
    cin >> n >> m >> l;
    for(int i = 0; i < n ; i++){
        cin >> p[i+1];
    }
    for(int i = 1 ; i <= m ; i++){
        int a,b,c;
        cin >> a >> b >> c;
        adj[a].push_back(b);
        adj[b].push_back(a);
        weights[a].push_back(c);
        weights[b].push_back(c);
        deg[a]++;
        deg[b]++;
    }
}

set< pair<int,int> > q;
int dis[MAX_N];
bool tb[MAX_N];

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

        for(int i = 0 ; i < deg[now]; i++){
            int next = adj[now][i];
            int w = weights[now][i];
            if(dis[next] > dis[now] + w){
                dis[next] = dis[now]+w;
                q.insert(make_pair(dis[next],next));
            }
        }
    }
}

int main(){
    read_input();
    dijkstra(1);

    int total = 0;
    for(int i = 2 ; i <= n ; i++){
        total += p[i] > l? l * dis[i]: p[i] * dis[i];
    }
    cout << total;
    return 0;
}