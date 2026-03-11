#include <iostream>
#include <vector>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    const int MAX = 250000;
    vector<bool> isPrime(MAX,true);
    isPrime[0] = isPrime[1] = false;
    for(int p = 2; p * p < MAX; p++) {
        if(isPrime[p]) {
            for(int a = p * p; a < MAX; a += p) {
                isPrime[a] = false;
            }
        }
    }
    while(true) {
        int n;
        cin >> n;
        if(n == 0) return 0;
        int p = 0;
        for(int i = n + 1; i <= 2*n; i++) {
            if(isPrime[i]) p++;
        }
        cout << p << '\n';
    }
    return 0;
}