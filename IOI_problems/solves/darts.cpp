#include<iostream>
#include<math.h>
using namespace std;

int cal_score(int x, int y){
    int score;
    float distance;
    distance = sqrt(x*x + y*y);
    score = 0;
    for(int i = 0; i < 5 ; i++){
        if(distance <=  10-(2*i)) score = i+1;
    }
    return score;
}

int main(){
    int n, x,y;
    cin >> n;
    int sum = 0;
    for(int i = 1; i<=n;i++){
        cin >> x >> y;
        sum += cal_score(x,y);
    }
    cout << sum;
    return 0;
}