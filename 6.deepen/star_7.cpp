#include <iostream>
#include <string>
using namespace std;
int main() {
    int n;
    cin >> n;
    for(int i = 0; i < n; i++) {
        cout << string(n-i-1,' ') << string(2*i+1,'*') << '\n';
    }
    for(int i = 1; i < n; i++) {
        cout << string(i,' ') << string(2*n-2*i-1,'*') << '\n';
    }
    return 0;
}