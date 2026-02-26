#include <iostream>
using namespace std;
int main() {
    int h, m;
    cin >> h >> m;
    if (h < 0 || h >= 24 || m < 0 || m >= 60) {
        cout << "24시로 나타내시오!!" << endl;
        return 0;
    }

    if ( m >= 45 ) {
        cout << h << " " << m - 45 << endl;
    }
    else {
        if ( h == 0 ) cout << 23 << " " << m+15 << endl;
        else cout << h - 1 << " " << m+15 << endl;
    }
    return 0;
}