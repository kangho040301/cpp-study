#include <iostream>
#include <vector>
using namespace std;
vector<long long> v(4000001);
const int p = 1000000007;
void factorial(int x) {
    v[0] = v[1] = 1;
    for(long long i = 2; i <= x; i++) {
        v[i] = (v[i-1]*i)%p;
    }
}
long long dc_power(int x, int m) {
    if(m == 1) {
        return x%p;
    }

    long long temp = dc_power(x, m/2);
    temp = (temp*temp)%p;
    if(m%2 == 0) {
        return temp;
    }
    else {
        return (temp*x)%p;
    }
}
long long rev_source(int x) {
    return dc_power(x, p - 2);
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    
    int n, k;
    cin >> n >> k;
    factorial(n);
    long long a = v[n];
    long long b = rev_source((v[k]*v[n-k])%p);

    cout << (a * b)%p << '\n';
    return 0;
}
//페르마의 소정리 a^(p-1) == 1 (mod p) (p는 소수)
//-> 어떤 수 i로 나누는 효과 == i의 역원을 곱하는 효과
//a * a^(p-2) == 1, a^(p-2)는 a의 역원