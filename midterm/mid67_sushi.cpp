#include<iostream>
#include<map>
using namespace std;

int n, l;
int cnt = 0;
bool can = true;
map<int, int> locate;
int main(){
    cin >> n >> l;
    bool check = false;
    while(n--){
        int soi, depth;
        cin >> soi >> depth;
        locate[soi] = depth;
    }
    l *= 2;
    int pivot = -1;
    int cnt =0;
    for(auto num : locate){
        if(pivot == -1){
            pivot = num.first;
        }
        else{
            int range = (num.first-pivot) + num.second + locate[pivot];
            if(num.second > l/2) can = false;
            if(range > l){
                cnt++;
                pivot = num.first;
                // cout << "pivot:" << pivot<<"| ";
            }
            else{
                if((num.first-pivot)+locate[pivot] < num.second ){
                    pivot = num.first;
                }
            }
            // cout << range << " ";
        }
    }
    if(can == false) cout << -1;
    else cout << cnt+1;
    return 0;
}