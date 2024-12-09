#include<iostream>
#include<list>
#include<sstream>
using namespace std;

void process(int n){
    int arr[1010];
    while(true){
        int N = n;
        list<int> station;
        for(int i = 1; i <= n ; i++){
            cin >> arr[i];
            if(arr[i] == 0){
                cout << "\n";
                return;
            }
        }
        for(int i = n; i >= 1 ; i--){
            station.push_front(arr[i]);
            while(station.front() == N && N > 0){
                station.pop_front();
                N--;
            }
        }
        if(station.size() == 0) cout << "Yes";
        else cout << "No";
        cout << "\n";
    }
}

int main(){
    int n;
    while(cin >> n){
        if(n == 0) break;
        process(n);
    }
    return 0;
}