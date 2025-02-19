#include<iostream>
#include<vector>
#include<map>
using namespace std;

int n, m;
int parents[100010], ranks[100010], mins[100010];
map<int, vector<pair<int,int> > > brokens; 

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
    }
    for(int i = 0 ; i < m ; i++){
        int A, B, C, D;
        cin >> A >> B >> C >> D;
        if(D){
            unite(A,B);
        }
        else{
            brokens[C].push_back(make_pair(A,B));
        }
    }
}

int total = 0;

int main(){
    init();
    for(auto ite: brokens){
        for(auto pair : ite.second){
            int pA = find(pair.first);
            int pB = find(pair.second);
            if(pA == pB) continue;

            unite(pA, pB);
            total += ite.first;
        }
    }
    cout << total;
    return 0;
}