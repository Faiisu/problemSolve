
#include <iostream>
#include<map>

using namespace std;

map<int,int> a;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    while(true){
        cin >> n;
        if( n == 0 ) break;
        a.clear();
        
        for(int i = 0 ; i < n ; i++){
            int inp;
            cin >> inp;
            a[inp]++;
        }
        for(map<int,int>::iterator ite = a.begin(); ite != a.end(); ite++){
            for(int j = 0 ; j < ite->second ; j++){
                cout << ite->first << " ";
            }
        }
        cout << "\n";
    }
}
