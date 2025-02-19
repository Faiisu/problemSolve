#include<iostream>
#include<vector>
#include<set>
#include<map>
using namespace std;

int n, m;
int parents[100010], ranks[100010], mins[100010];
vector< pair<int, pair<int,int> > > brokens;
bool tb[100010];

int find(int N){
    if(parents[N] != N){
        return find(parents[N]);
    }
    return N;
}

void unite(int A, int B){
    int rA = find(A);
    int rB = find(B);

    if(rA != rB){
        if(ranks[rA] > ranks[rB]){
            parents[rB] = rA;
        } else if (ranks[rA] < ranks[rB]){
            parents[rA] = rB;
        }
        else{
            parents[rA] = rB;
            ranks[rB]++;
        }
    }
}

void init(){
    cin >> n >> m;
    for(int i = 1; i<=n;i++){
        parents[i] = i;
        tb[i] = false;
    }
    for(int i = 0 ; i < m ; i++){
        int A, B, C, D;
        cin >> A >> B >> C >> D;
        if(D){
            unite(A,B);
        }
        else{
            brokens.push_back(make_pair(C,make_pair(A,B)));
        }
    }
}

map<int, set<pair<int,int> > > adj;

int total = 0;

void totalCnt(int n){
    if(tb[n]) return;
    tb[n] = true;

    for(auto ite: adj[n]){
        if(tb[ite.second]) continue;
        total += ite.first;
        totalCnt(ite.second);
    }
}

int main(){
    init();
    for(auto ite: brokens){
        int w = ite.first;
        int pA = find(ite.second.first), pB = find(ite.second.second);

        adj[pA].insert(make_pair(w,pB));
        adj[pB].insert(make_pair(w,pA));
    }
    totalCnt(adj.begin()->first);
    cout << total;
    return 0;
}