// longest increase subsequence
#include<iostream>
#include<vector>

using namespace std;
int n;

int arr[1010];
vector< vector<int> > mems;
int main(){
    cin >> n;
    for(int i = 0; i<n; i++){
        int inp;
        cin >> inp;
        arr[i] = inp;

        bool inst = false;
        
        for(auto& ite: mems){
            auto endp = ite.end();
            endp--;
            int h = *endp;
            // cout << "H: " << h << " ";
            if(inp > h){
                ite.push_back(inp);
                inst = true;
            }
        }
        vector<int> newL;
        newL.push_back(inp);
        mems.push_back(newL);
    }

    vector<int> ans;
    for(auto list: mems){
        if(list.size() > ans.size()) ans = list;
    }

    cout << ans.size()<<"\n";
    for(auto i : ans) cout << i << " ";

    return 0;
} 