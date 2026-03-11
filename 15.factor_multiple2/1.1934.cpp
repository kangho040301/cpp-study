#include <iostream>
#include <algorithm>
using namespace std;
int get_gcd(int a, int b) {
    int r = 1;
    while(b != 0) {
        r = a % b;
        a = b;
        b = r;
        }
    return a;
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    int n;
    cin >> n;
    for(int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        
        cout << a * b / get_gcd(a, b) << '\n';
    }
    return 0;
}
/* 유클리드 호재법 (최대공약수 구하기)
gcd = greatest common divisor
lcm = least common multiple
int get_gcd(int a, int b) {
    while (b != 0) {
        int r = a % b;
        a = b;
        b = r;
    }
    return a;
}
LCM(a,b) = a * b / GCD(a,b);
*/