#include <iostream>
using namespace std;
int main() {
    int x , y;
    cin >> x >> y;
    if (x == 0 || y == 0) {
        cout << "x,y는 0이 될 수 없음" << endl;
        return 0;
    }

    if (x > 0 && y > 0) cout << "1" << endl;
    else if ( x < 0 && y > 0) cout << "2" << endl;
    else if ( x < 0 && y < 0) cout << "3" << endl;
    else cout << "4" << endl;
    return 0;
} 