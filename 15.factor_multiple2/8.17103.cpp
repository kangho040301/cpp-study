#include <iostream>
#include <vector>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    const int MAX = 1000001;
    vector<bool> isPrime(MAX,true);
    isPrime[0] = isPrime[1] = false;
    for(int p = 2; p * p < MAX; p++) {
        if(isPrime[p]) {
            for(int a = p * p; a < MAX; a += p) {
                isPrime[a] = false;
            }
        }
    }
    vector<int> prime;
    for(int i = 2; i < MAX; i++) {
        if(isPrime[i]) {
            prime.push_back(i);
        }
    }
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        int answer = 0;
        int len = prime.size();
        for(int a = 0; a < len; a++) {
            if(prime[a] > n/2) break;
            if(isPrime[n - prime[a]]) answer++;
        }   
        cout << answer << '\n';
    }
    return 0;
}