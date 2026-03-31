#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    
    int n, m; cin >> n >> m;
    unordered_map<string,string> site;
    for(int i = 0; i < n; i++) {
        string s1, s2; cin >> s1 >> s2;
        site[s1] = s2;
    }
    for(int i = 0; i < m; i++) {
        string s; cin >> s;
        cout << site[s] << '\n';
    }
    return 0;
}