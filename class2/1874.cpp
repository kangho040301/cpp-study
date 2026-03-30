#include <iostream>
#include <stack>
#include <queue>
#include <vector>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    
    int n; cin >> n;
    stack<int> s;
    queue<char> ans;
    vector<int> v(n);
    int x = 1;
    for(int i = 0; i < n; i++) {
        cin >> v[i];
    }
    for(int a : v) {
        while(x - 1 < a) {
            s.push(x++);
            ans.push('+');
        }
        if(!s.empty() && s.top() == a) {
            s.pop();
            ans.push('-');
        }
        else {
            cout << "NO" << '\n';
            return 0;
        }
    }
    while(!ans.empty()) {
        cout << ans.front() << '\n';
        ans.pop();
    }
    return 0;
}