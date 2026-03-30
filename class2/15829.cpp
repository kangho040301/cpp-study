#include <iostream>
#include <string>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    
    int l; cin >> l;
    string s; cin >> s;
    long long ans = 0;
    for(int i = l - 1; i >= 0; i--) {
        ans = (ans * 31 + (s[i] - 'a' + 1))%1234567891;
    }
    cout << ans << '\n';
    return 0;
}