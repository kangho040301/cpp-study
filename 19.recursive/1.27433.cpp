#include <iostream>
using namespace std;
long long factorial(int a) {
    if(a == 0) return 1;
    else return a * factorial(a-1);
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    
    int n;
    cin >> n;
    cout << factorial(n) << '\n';
}