#include <iostream>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    int n;
    cin >> n;
    while(n > 1) {
        for(int i = 2; i <= n; i++) {
            if(n%i == 0) {
                n /= i;
                cout << i << '\n';
                break;
            }
        }
    }
    return 0;
}