#include <iostream>
#include <unordered_set>
#include <string>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    
    string s;
    cin >> s;
    int len = s.length();
    unordered_set<string> s_set;
    for(int i = 0; i < len; i++) {
        for(int j = 0; j < len - i; j++) {
            s_set.insert(s.substr(j,i+1));
        }
    }
    cout << s_set.size() << '\n';
}