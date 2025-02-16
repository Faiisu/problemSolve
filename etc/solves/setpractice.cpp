#include<iostream>
#include<map>
using namespace std;

map<int,int> inputs;
int main(){
    int n, m, input;
    cin >> n >> m;
    while(n--){
        cin >> input;
        inputs[input]=1;
    }
    while(m--){
        cin >> input;
        auto ite = inputs.upper_bound(input);
        int more = ite->first;
        ite--;
        int less = ite->first;
        if(abs(input-more) < abs(input-less)) cout << more;
        else cout << less;
        cout << "\n";
    }
    return 0;
}