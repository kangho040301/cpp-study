#include <iostream>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    
    long long int a, b;
    cin >> a >> b;

    long long int r = 1;
    long long int x = a;
    long long int y = b;
    while(b != 0) {
        r = a % b;
        a = b;
        b = r;
    }
    cout << x * y / a << '\n';
    return 0;
}