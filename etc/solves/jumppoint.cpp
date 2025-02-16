#include<iostream>
#include<vector>
#include<cmath>
using namespace std;
int n, jDist;
int inputs[1010][2];
vector<int> layers[1010];
bool discoverd[1010];

void init(){
    int number = n;
    inputs[0][1] = 0;
    inputs[0][2] = 0;
    inputs[n+1][0] = 100;
    inputs[n+1][1] = 100;
    for(int i = 1 ; i <= n ; i++) cin >> inputs[i][0] >> inputs[i][1];
    for(int i = 0; i <= n ; i++) discoverd[i] = false;
}

int pathing(){
    int i;
    layers[0].push_back(0);
    for(i = 0; !layers[i].empty() ; i++){
        // cout << "layer: " << i << endl;
        for(auto j: layers[i]){
            int x1 = inputs[j][0], y1 = inputs[j][1];
            // cout<<"-----------\n" <<"x1,y1: "<< x1 << " " << y1 << "\n-----------\n";
            for(int k = 1; k<=n+1;k++){
                if(discoverd[k] == true) continue;
                int x2 = inputs[k][0], y2 = inputs[k][1];
                float distance = sqrt((x1-x2)*(x1-x2) + (y1-y2)*(y1-y2));
                if(jDist >= distance){
                    // cout << x2 << " " << y2 << "\n";
                    if(k == n+1) return i+1;
                    layers[i+1].push_back(k);
                    discoverd[k] = true;
                }
            }
        }
    }
    return -1;
}

int main(){
    cin >> n >> jDist;
    init();
    int ans = pathing();
    cout << ans;
    return 0;
}