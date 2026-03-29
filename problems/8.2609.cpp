#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
int gcd(int x, int y) {
    if(y == 0) return x;
    return gcd(y, x%y);
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    
    int a, b; cin >> a >> b;
    int ans1 = gcd(a, b);
    int ans2 = a/ans1 * b;
    cout << ans1 << '\n' << ans2 << '\n';
    return 0;
}