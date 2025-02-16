#include<iostream>
using namespace std;

// O(n^2)
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int w,h,m,n;
    int arr_w[10010], arr_h[10010];
    int areas[] = {0,0}, area;

    cin >> w >> h >> m >> n;
    
    for(int i = 1 ; i <= m; i++) cin >> arr_w[i];
    for(int i = 1; i <= n ; i++) cin >> arr_h[i];
    arr_w[0] = 0;
    arr_h[0] = 0;
    arr_w[m+1] = w;
    arr_h[n+1] = h;
    
    for(int i = 1; i <= m+1; i++){
        for(int ii = 1; ii <= n+1 ; ii++){
            area = (arr_w[i]-arr_w[i-1]) * (arr_h[ii]-arr_h[ii-1]);
            // cout << area << "\n";
            if(area >= areas[0]){
                areas[1] = areas[0];
                areas[0] = area;
            }
            else if(area >= areas[1]) areas[1] = area;
        }
    }
    // cout << second_w_diff << " " << second_h_diff << endl;
    // cout << max_w_diff << " " << max_h_diff << endl;

    cout << areas[0] << " " << areas[1];
    return 0;
}