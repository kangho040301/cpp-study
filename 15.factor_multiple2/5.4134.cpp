#include <iostream>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    
    int t;
    cin >> t;
    while(t--) {
        long long n;
        cin >> n;
        if(n == 0 || n == 1 || n == 2) {
            cout << 2 << '\n';
            continue;
        }
        for(long long i = n;;i++) {
            long long a = 2;
            for(; a * a <= i; a++) {
                if(i%a == 0) break;
            }
            if(a*a > i) {
                cout << i << '\n';
                break;
            }
        }
    }
    return 0;
}