//union & join
#include<iostream>

using namespace std;

int n , q;
int s[100010];
int len[100010];

int find(int n){
    if(s[n] != n){
        return find(s[n]);
    }
    return n;
} 

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> q;

    for(int i = 1; i<= n ; i++){
        s[i] = i;
        len[i] = 0;
    }

    while(q--){
        char cmd;
        int a, b;
        cin >> cmd >> a >> b;
        int sA = find(a);
        int sB = find(b);
        if(cmd == 'c'){
            if(sA != sB){
                if(len[sA] > len[sB]){
                    s[sB] = sA;
                }
                else if(len[sA] < len[sB]){
                    s[sA] = sB;
                }
                else{
                    s[sB] = sA;
                    len[sA]++;
                }
            }
            // cout << find(s[a]) << " " <<find(s[b])<< "\n";
        }
        else{
            // cout << s[a] << " " << s[b] << "\n";
            if(sA == sB) cout << "yes\n";
            else cout << "no\n";
        }
    }
    return 0;
}
