#include <iostream>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    while(1) {
        int a,b;
        if(cin >> a >> b) cout << a+b << '\n';
        else break;
    }
}