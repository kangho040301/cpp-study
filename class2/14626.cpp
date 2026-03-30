#include <iostream>
#include <string>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    
    string s; cin >> s;
    int sum = 0;
    int m = s.back() - '0';
    bool isodd = false;
    for(int i = 0; i < 12; i++) {
        if(i%2) {
            if(s[i] != '*') {
                sum += 3*(s[i] - '0') % 10;
                sum %= 10;
            }
            else {
                isodd = true;
            }
        }
        else {
            if(s[i] != '*') {
                sum += (s[i] - '0') % 10;
                sum %= 10;
            }
            else {
                isodd = false;
            }
        }
    }

    if(isodd) {
        for(int i = 0; i <= 9; i++) {
            if((sum+3*i+m)%10 == 0) cout << i << '\n';
        }
    }
    else {
        for(int i = 0; i <= 9; i++) {
            if((sum+i+m)%10 == 0) cout << i << '\n';
        }
    }
    return 0;
}
// m = 10 - (sum + 3ans) % 10;
// (sum + 3ans) % 10 = 10 - m;