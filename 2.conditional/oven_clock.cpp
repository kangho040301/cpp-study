#include <iostream>
using namespace std;
int main()
{
    int a,b,t;
    int m;
    cin >> a >> b;
    cin >> t;
    m = b + t;
    if ( a + m/60 < 24 ) {
        cout << a + m/60 << " " << m%60 << endl;
    }
    else {
        cout << a + m/60 - 24 << " " << m%60 << endl;
    }
    return 0;
}