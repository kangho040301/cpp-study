#include <iostream>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    
    int ans = 0;
    for(int i = 0; i < 5; i++) {
        int x;
        cin >> x;
        ans += (x*x)%10;
    }
    cout << ans%10 << '\n';
    return 0;
}