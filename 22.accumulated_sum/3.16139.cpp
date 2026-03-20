#include <iostream>
#include <vector>
#include <string>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    
    string s;
    cin >> s;
    vector<vector<int>> alpha(26,vector<int>(s.size()));
    
    for(int i = 0; i < s.size(); i++) {
        if(i > 0) {
            for(int j = 0; j < 26; j++) {
                alpha[j][i] = alpha[j][i-1];
            }
        }
        alpha[s[i] - 'a'][i]++;
    }
    int q;
    cin >> q;
    while(q--) {
        char a;
        int l, r;
        cin >> a >> l >> r;
        if(l == 0) cout << alpha[a - 'a'][r] << '\n';
        else cout << alpha[a - 'a'][r] - alpha[a - 'a'][l - 1] << '\n';
    }
    return 0;
}