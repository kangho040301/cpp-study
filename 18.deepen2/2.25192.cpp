#include <iostream>
#include <unordered_set>
#include <string>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    
    int n;
    cin >> n;
    unordered_set<string> name;
    int ans = 0;
    while(n--) {
        string s;
        cin >> s;
        if(s == "ENTER") {
            ans += name.size();
            name.clear();
        }
        else {
            name.insert(s);
        }
    }
    ans += name.size();
    cout << ans << '\n';
    return 0;
}