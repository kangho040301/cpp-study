#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    
    string s;
    cin >> s;
    vector<int> num;
    string temp = "";
    int idx_start = 0;
    int sum = 0;
    for(int i = 0; i < s.size(); i++) {
        if(s[i] == '+') {
            temp = s.substr(idx_start, i - idx_start);
            sum += stoi(temp);
            idx_start = i + 1;
        }
        else if(s[i] == '-') {
            temp = s.substr(idx_start, i - idx_start);
            sum += stoi(temp);
            num.push_back(sum);
            sum = 0;
            idx_start = i + 1;
        }
        else if(i == s.size() - 1) {
            temp = s.substr(idx_start, i - idx_start + 1);
            sum += stoi(temp);
            num.push_back(sum);
        }
    }
    int ans = num[0];
    for(int i = 1; i < num.size(); i++) {
        ans -= num[i];
    }
    cout << ans << '\n';
    return 0;
}