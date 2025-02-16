//minimum spanding tree

#include<iostream>
#include<set>

using namespace std;
int n, m;
int s[100010];
int len[100010];
set<pair<int, pair<int,int> > > tree;



void read_input(){
    cin >> n >> m;
    for(int i = 0 ; i < m ; i++){
        int a, b, w;
        cin >> a >> b >> w;
        s[a] = a;
        s[b] = b;
        len[a] = 0;
        len[b] = 0;
        tree.insert(make_pair( w, make_pair(a,b) ));
    }
}

int find(int a){
    if(s[a] != a){
        return find(s[a]);
    }
    return a;
}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    read_input();
    int totalW = 0;
    for(auto seq : tree){
        int w = seq.first;
        int a = seq.second.first, b = seq.second.second;
        
        int rA = find(a), rB = find(b);
        if(rA != rB){
            totalW += w;
            if(len[rA] > len[rB]){
                s[rB] = rA;
                s[b] = rA;
            } else if(len[rA] < len[rB]){
                s[rA] = rB;
                s[a] = rB;
            }
            else{
                s[rA] = rB;
                len[rA]++;
            }
        }
    }
    cout << totalW;
    return 0;
}