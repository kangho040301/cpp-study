#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    
    while(true) {
        string s; cin >> s;
        if(s == "0") return 0;
        string ns = s;
        reverse(s.begin(),s.end());
        if(s == ns) {
            cout << "yes" << '\n';
        }
        else {
            cout << "no" << '\n';
        }
    }
}