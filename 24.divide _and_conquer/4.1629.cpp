//10 ^ 11 = 10 ^ 5 * 10 ^ 5 * 10 = 10 ^ 2 * 10 ^ 2 * 10 * 10 ^ 5 * 10
//10 * 10 * 10 ^ 2 * 10 * 10 ^ 5 * 10 총 5번만 하면됨
#include <iostream>
using namespace std;
long long ans = 0;
long long solve(long long a, long long b, long long c) {
    if(b == 1) {
        return a%c;
    }
    long long temp = solve(a, b/2, c);
    temp = ((temp%c)*(temp%c))%c;
    if(b%2 == 0) {
        return temp;
    }
    else {
        return (temp * a%c)%c;
    }
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    
    long long a, b, c;
    cin >> a >> b >> c;
    long long ans = solve(a, b, c);
    cout << ans << '\n';
    return 0;
}