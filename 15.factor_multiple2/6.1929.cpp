#include <iostream>
#include <vector>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    
    int n, m;
    cin >> n >> m;
    vector<bool> isPrime(m+1,true);
    isPrime[0] = isPrime[1] = false;
    for(int i = 2; i * i <= m; i++) {
        if(isPrime[i]) {
            for(int a = i * i; a <= m; a += i) {
                isPrime[a] = false;
            }
        }
    }
    for(int i = n; i <= m; i++) {
        if(isPrime[i]) cout << i << '\n';
    }
    return 0;
}
//에라토스테네스의 체 : 소수 구하는 최소 시간 알고리즘 (메모리 많이 먹음)
/*
void sieve(int n) {
    // 모든 수를 일단 소수(true)로 초기화
    vector<bool> is_prime(n + 1, true);
    is_prime[0] = is_prime[1] = false; // 0과 1은 제외

    for (int p = 2; p * p <= n; p++) {
        // p가 아직 소수라면 (지워지지 않았다면)
        if (is_prime[p]) {
            // p의 배수들을 모두 false로 마스킹!
            for (int i = p * p; i <= n; i += p)
                is_prime[i] = false;
        }
    }
}
*/