#include <iostream>
#include <string>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    
    int n; cin >> n;
    int m; cin >> m;
    string s; cin >> s;
    int ans = 0;
    for(int i = 0; i < m - 2; i++) {
        int count = 0;
        if(s[i] == 'I') {
            while(s[i+1] == 'O' && s[i+2] == 'I') {
                count++;
                i += 2;
                if(count >= n) ans++;
            }
        }
    }
    cout << ans << '\n';
    return 0;
}