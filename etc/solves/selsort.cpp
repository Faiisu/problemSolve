#include <iostream>
#include <vector>

using namespace std;

int n;
vector<int> x;

void read_input()
{
  cin >> n;
  for(int i = 0; i < n; i++) {
    int xx;
    cin >> xx;
    x.push_back(xx);
  }
}

int find_max_index(vector<int>& x, int n)
{
    // TODO: return the index of the maximum element in x[0], x[1],... x[n-1]
    //       don't use any loop control structures
    if(n == 0) return n;
    int m = find_max_index(x, n-1);
    if(x[m] >= x[n]){
        return m;
    }
    return n;
}

void swap(int& x, int& y)
{
  int t = x;
  x = y;
  y = t;
}

void selection_sort(vector<int>& x, int n)
{
    if(n == 0) return;
    // TODO: don't use any loop control structures
    int m = find_max_index(x, n);
    swap(x[n], x[m]);
    selection_sort(x, n-1);
}

int main()
{
  read_input();
  selection_sort(x, n-1);
  for(int i=0; i<n; i++) {
    cout << x[i] << endl;
  }
}