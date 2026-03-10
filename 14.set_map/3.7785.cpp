#include <iostream>
#include <set>
#include <string>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    
    int n;
    cin >> n;
    set<string, greater<string>> names;
    for(int i = 0; i < n; i++) {
        string name;
        string state;
        cin >> name >> state;
        if(state == "enter") names.insert(name);
        else if(state == "leave") names.erase(name);
    }
    for(auto it = names.begin(); it != names.end(); it++) {
        cout << *it << '\n';
    }
    return 0;
}