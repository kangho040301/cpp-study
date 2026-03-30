#include <iostream>
#include <string>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    
    int t; cin >> t;
    while(t--) {
        string s; cin >> s;
        int ans = 0, score = 0;
        for(char a : s) {
            if(a == 'O') {
                score++;
                ans += score;
            }
            else {
                score = 0;
            }
        }
        cout << ans << '\n';
    }
    return 0;
}