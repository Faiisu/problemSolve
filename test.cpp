#include<iostream>
#include<map>
using namespace std;

map<int,int> inputs;
int main(){
    int n, m, input;
    cin >> n >> m;
    for(int i = 0 ; i < n ; i++){
        cin >> input;
        inputs[input] = 1;
    }

    auto ite = inputs.upper_bound(10);
    if(ite != inputs.end()){
        ite--;
        cout << ite->first << " " << ite->second << endl;
    }

    return 0;
}