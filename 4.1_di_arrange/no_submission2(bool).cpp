#include <iostream>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    bool sub[31] = {false};
    for(int i = 0; i < 28; i++) {
        int a;
        cin >> a;
        sub[a] = {true};
    }
    for(int i = 1; i <= 30; i++) {
        if(!sub[i]) cout << i << '\n';
    }
    return 0;
}