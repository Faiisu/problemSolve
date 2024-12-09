#include<iostream>
using namespace std;

int encode_y2x(int y_i,int y_bf){
    if(y_i == y_bf-1) return 0;
    if(y_i == y_bf+1) return 1;
}

int encode_z2y(int z_i, int z_bf, int y_bf){
    if(z_i-y_bf < y_bf) return y_bf-1;
    if(z_i-(2*y_bf) > y_bf) return y_bf+1;
}

int main(){
    int n, t;
    int y, z, output;
    cin >> n >> t;
    int y_bf = n, z_bf = n;
    for(int i = 0 ; i < n; i++){
        if(t == 1){
            cin >> y;
            output = encode_y2x(y, y_bf);
            cout << output << endl;
            if(output == 1) y_bf+=1;
            else y_bf-=1;
        }
        else{
            cin >> z;
            if(i == 0) y = z;
            else y = encode_z2y(z, z_bf, y_bf);
            if(y < y_bf){
                output = 0;
            }
            else output = 1;
            y_bf = y;
            z_bf = z;
            cout << output << endl;
        }
    }
    return 0;
}