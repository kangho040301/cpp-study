#include <iostream>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    int a;
    cin >> a;
    int max = a;
    int min = a; 
    
    for(int i = 1; i < n; i++) {
        cin >> a;
        if(a > max) max = a;
        if(a < min) min = a;
    }
    cout << min << " " << max << '\n';
    return 0;
}