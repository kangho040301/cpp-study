#include <iostream>
#include <vector>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    
    int n; cin >> n;
    vector<bool> isprime(n+1,true);
    isprime[0] = isprime[1] = false;
    for(int i = 2; i*i <= n; i++) {
        if(isprime[i]) {
            for(int j = i*i; j <= n; j += i) {
                isprime[j] = false;
            }
        }
    }
    vector<int> prime;
    for(int i = 2; i <= n; i++) {
        if(isprime[i]) prime.push_back(i);
    }

    int left = 0, right = 0;
    int ans = 0, sum = 0;
    while(true) {
        if(sum == n) {
            ans++;
            sum -= prime[left++];
        }
        else if(sum > n) {
            sum -= prime[left++];
        }
        else if(right == prime.size()) break;
        else {
            sum += prime[right++];
        }
    }
    cout << ans << '\n';
    return 0;
}