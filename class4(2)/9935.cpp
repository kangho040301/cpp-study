#include <iostream>
#include <string>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    
    string s; cin >> s;
    string bomb; cin >> bomb;
    string ans = "";
    int s_len = s.length();
    int b_len = bomb.length();
    for(int i = 0; i < s_len; i++) {
        ans.push_back(s[i]);

        //폭탄인지 검사
        if(ans.length() >= b_len && ans.back() == bomb.back()) {
            bool isbomb = true;
            for(int j = 1; j <= b_len; j++) {
                if(ans[ans.length() - j] != bomb[b_len - j]) {
                    isbomb = false;
                    break;
                }
            }
            if(isbomb) {
                for(int j = 1; j <= b_len; j++) {
                    ans.pop_back();
                }
            }
        }
    }
    if(ans == "") cout << "FRULA\n";
    else cout << ans << '\n';
    return 0;
}