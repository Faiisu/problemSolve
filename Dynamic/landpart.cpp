#include <iostream>

using namespace std;
int n, maxValue[1010], inputs[1010];

int main(){
    cin >> n;
    for(int i = 0 ; i < n ; i++){
        cin >> inputs[i];
        if(i < 4) maxValue[i] = 0;
        else{
            int m = inputs[i];
            for(int j = i-4 ; j < i ; j++){
                if(inputs[j] > m) m = inputs[j];
            }
            
            if(maxValue[i-5] + m > maxValue[i-1]){
                maxValue[i] = maxValue[i-5]+m;
            }
            else maxValue[i] = maxValue[i-1];
        }
    }

    cout << maxValue[n-1];
    return 0;
}