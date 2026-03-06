#include <iostream>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    
    int a,b,c;
    cin >> a >> b >> c;
    if(a + b + c == 180) {
        if( a == b && b == c) cout << "Equilateral" << '\n';
        else if(a == b || a == c || b == c) cout << "Isosceles" << '\n';
        else cout << "Scalene" << '\n';
    }
    else cout << "Error" << '\n';
    return 0;
}