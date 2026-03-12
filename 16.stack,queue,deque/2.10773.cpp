#include <iostream>
#include <stack>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    
    int k;
    cin >> k;
    stack<int> money;
    int sum = 0;
    while(k--) {
        int n;
        cin >> n;
        if(n != 0) {
            money.push(n);
            sum += n;
        }
        else {
            sum -= money.top();
            money.pop();
        }
    }
    cout << sum << '\n';
    return 0;
}