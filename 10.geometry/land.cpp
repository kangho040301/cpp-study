#include <iostream>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    
    int n;
    cin >> n;
    int a, b;
    cin >> a >> b;
    if(n == 1) {
        cout << 0 << '\n';
        return 0;
    } 
    int min_a = a;
    int max_a = a;
    int min_b = b;
    int max_b = b;
    for(int i = 1; i < n; i++) {
        int a, b;
        cin >> a >> b;
        if(a < min_a) min_a = a;
        if(a > max_a) max_a = a;
        if(b < min_b) min_b = b;
        if(b > max_b) max_b = b;
    }
    cout << (max_a - min_a) * (max_b - min_b) << '\n';
    return 0;
}