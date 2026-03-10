#include <iostream>
#include <unordered_set>
#include <set>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    
    int n, m;
    cin >> n >> m;
    unordered_set<string> names;
    for(int i = 0; i < n; i++) {
        string name;
        cin >> name;
        names.insert(name);
    }
    set<string> answer;
    for(int i = 0; i < m; i++) {
        string name;
        cin >> name;
        if(names.find(name) != names.end()) answer.insert(name);
    }
    cout << answer.size() << '\n';
    for(const string &a : answer) {
        cout << a << '\n';      
    }
    return 0;
}