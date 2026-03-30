#include <iostream>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    
    int n[8]{};
    for(int i = 0; i < 8; i++) {
        cin >> n[i];
    }

    if(n[0] != 1 && n[0] != 8) {
        cout << "mixed" << '\n';
        return 0;
    }
    for(int i = 1; i < 8; i++) {
        if(n[i] != n[i-1] + 1 && n[i] != n[i-1] - 1) {
            cout << "mixed" << '\n';
            return 0;
        }
    }
    if(n[0] == 1) cout << "ascending" << '\n';
    else cout << "descending" << '\n';
    return 0;
}