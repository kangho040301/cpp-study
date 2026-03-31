#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    
    int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        unordered_map<string, int> cloth;
        for(int i = 0; i < n; i++) {
            string name, kind; cin >> name >> kind;
            cloth[kind]++;
        }
        int ans = 1;
        for(const auto& [key, value] : cloth) {
            ans *= (value + 1);
        }
        cout << ans - 1 << '\n';
    }
    return 0;
}