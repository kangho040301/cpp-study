#include <iostream>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++) {
        int sum = i;
        int x = i;
        while(x != 0) {
            sum += x%10;
            x /= 10;
        }
        if(sum == n) {
            cout << i << '\n';
            return 0;
        }
    }
    cout << 0 << '\n';
    return 0;
}