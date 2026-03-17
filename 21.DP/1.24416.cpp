#include <iostream>
#include <vector>
using namespace std;
int fibonacci(int n) {
    vector<int> v(n+1);
    v[1] = v[2] = 1;
    for(int i = 3; i <= n; i++) {
        v[i] = v[i-1] + v[i-2];
    }
    return v[n];
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    
    int n;
    cin >> n;
    int f = fibonacci(n);
    cout << f << ' ' << n - 2 << '\n';
    return 0;
}