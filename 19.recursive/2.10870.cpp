#include <iostream>
using namespace std;
int fibo(int n) {
    if(n == 0) return 0;
    else return (n == 1 ? 1 : fibo(n-1) + fibo(n-2));
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    
    int n;
    cin >> n;
    cout << fibo(n) << '\n';
}