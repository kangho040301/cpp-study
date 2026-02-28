#include <iostream>
#include <vector>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int result = 0;
    int n;
    cin >> n;
    vector<int> v(n);

    for(int i = 0; i < n; i++) {
        cin >> v[i];
    }
    
    int w;
    cin >> w;
    for(int i = 0; i < n; i++) {
        if(v[i] == w) result++;
    }
    cout << result << '\n';
    return 0;
}