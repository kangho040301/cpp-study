#include <iostream>
#include <queue>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    
    int n, k;
    cin >> n >> k;
    queue<int> num;
    for(int i = 1; i <= n; i++) {
        num.push(i);
    }
    cout << "<";
    while(num.size() > 1) {
        for(int a = 1; a < k; a++) {
            num.push(num.front());
            num.pop();
        }
        cout << num.front() << ", ";
        num.pop();
    }
    cout << num.front() << ">\n";
    return 0;
}