#include <vector>
#include <cmath>
#include <iostream>
using namespace std;

vector<int> findPrimesInRange(int i, int n) {
    if (n < 2) return vector<int>();

    vector<bool> isPrime(n + 1, true); 
    isPrime[0] = isPrime[1] = false;
    for (int p = 2; p * p <= n; ++p) {
        if (isPrime[p]) {
            for (int multiple = p * p; multiple <= n; multiple += p) {
                isPrime[multiple] = false;
            }
        }
    }
    vector<int> primes;
    for (int num = max(i, 2); num <= n; ++num) {
        if (isPrime[num]) {
            primes.push_back(num);
        }
    }

    return primes;
}
int main() {
    int a, b, cnt = 0;
    cin >> a >> b;
    vector<int> primes = findPrimesInRange(a, b);
    for(int i = 1 ; i < primes.size() ; i++){
        if(primes[i]-primes[i-1] == 2) cnt++;
    }
    cout << cnt;
    return 0;
}