#include <iostream>
#include <unordered_map>
#include <string>
#include <cctype>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    
    int n, m;
    cin >> n >> m;
    unordered_map<string, int> poketmon_num;
    unordered_map<int, string> poketmon_name;
    for(int i = 1; i <= n; i++) {
        string name;
        cin >> name;
        poketmon_num[name] = i;
        poketmon_name[i] = name;
    }
    for(int i = 0; i < m; i++) {
        string finding;
        cin >> finding;
        int num = 0;
        if(isdigit(finding[0])) {
            num = stoi(finding);
            cout << poketmon_name[num] << '\n';
        }
        else cout << poketmon_num[finding] << '\n';
    }
    return 0;
}