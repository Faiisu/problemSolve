//longest increase subsequence 
#include<iostream>
#include<set>

using namespace std;
int numbers[1010][2];
set<int> ans;
int parent[1010];
int longest[2] = {0,0};

int main(){
    int n;
    cin >> n;
    for(int r = 0 ; r < n ; r++){
        int inp;
        cin >> inp;
        parent[r] = r;
        numbers[r][0] = inp;
        numbers[r][1] = 1;

        for(int i = 0; i < r; i++){
            int num = numbers[i][0];
            int s = numbers[i][1];
            if(num < inp && s+1 >= numbers[r][1]){
                numbers[r][1] = s+1;
                parent[r] = i;
            }
        }
        if(numbers[r][1] > longest[1]){
            longest[1] = numbers[r][1];
            longest[0] = r;
        }
    }

    int i = longest[0];
    while(parent[i] != i){
        ans.insert(numbers[i][0]);
        i = parent[i];
    }
    ans.insert(numbers[i][0]);

    cout << longest[1] << "\n";
    for(auto ite: ans) cout << ite << " ";
    return 0;
}