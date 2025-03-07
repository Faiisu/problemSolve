#include<iostream>
#include<map>
#include<vector>
using namespace std;

map<int,int> sizes;
vector<int> inputs, sums;
int sum = 0;
int main(){
    int N, Q; 
    cin >> N >> Q;
    int total = 0;
    sums.push_back(0);
    inputs.push_back(0);
    while(N--){
        int input;
        cin >> input;
        inputs.push_back(input);
        sizes[input] = 1;
        total += input;
        sums.push_back(total);
    }

    int size = inputs.size();
    for(int i = 1 ; i < size ; i++){
        int range = size - i;
        int sum = 0;
        // cout << range << ":range \n";
        for(int j = 0 ; j < size-range ; j++){
            // cout << "h: " << sums[j+range] << " l: " << sums[j] << endl;
            sum = sums[j+range] - sums[j];
            sizes[sum] = 1;
        }
        // cout << "\n";
    }


    while(Q--){
        int input;
        cin >> input;
        if(sizes[input]) cout << "Y";
        else cout << "N";
    }
    
    return 0;
}