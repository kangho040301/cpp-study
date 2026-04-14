#include <iostream>
#include <vector>
using namespace std;
int const p = 1000000007;
using ll = long long;
ll power(int n, int x) {
    if(x == 1) {
        return n;
    }
    ll temp = power(n, x/2);
    temp = (temp*temp)%p;
    if(x%2 == 0) {
        return temp;
    }
    else {
        return (temp * n)%p;
    }
}
int reverse(int n, int s) {
    return (s * power(n, p - 2))%p;
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
     
    int m; cin >> m;
    ll ans = 0;
    for(int i = 0; i < m; i++) {
        int n, s; cin >> n >> s;
        ans = (ans + reverse(n, s))%p;
    }
    cout << ans << '\n';
    return 0;
}
