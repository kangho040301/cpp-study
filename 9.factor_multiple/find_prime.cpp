#include <iostream>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    int m, n;
    cin >> m >> n;
    int sum = 0;
    int min = -1;
    for(int i = m; i <= n; i++) {
        if(i == 1) continue;
        if(i == 2) {
            sum += 2;
            min = 2;
            continue;
        }
        for(int a = 2; a <= i; a++) {
            if(i%a == 0) break;
            if(i <= a*a) {
                if(min == -1) min = i;
                sum += i;
                break;
            }
        }
    }
    if(sum != 0) {
        cout << sum << '\n' << min << '\n';
    }
    else cout << -1 << '\n';
    return 0;
}