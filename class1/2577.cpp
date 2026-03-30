#include <iostream>
#include <vector>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    
    int a, b, c; cin >> a >> b >> c;
    int num = a * b * c;
    int n[10]{};
    while(num) {
        int i = num%10;
        n[i] += 1;
        num /= 10;
    }
    for(int x : n) {
        cout << x << '\n';
    }
    return 0;
}