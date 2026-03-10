#include <iostream>
#include <unordered_set>
#include <string>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    
    int n, m;
    cin >> n >> m;
    unordered_set<string> str_set;
    for(int i = 0; i < n; i++) {
        string s;
        cin >> s;
        str_set.insert(s);
    }
    int t = 0;
    for(int i = 0; i < m; i++) {
        string s;
        cin >> s;
        if(str_set.find(s) != str_set.end()) t++;
    }
    cout << t << '\n';
    return 0;
}