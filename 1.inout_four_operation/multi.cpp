#include <iostream>
using namespace std;
int main()
{
    int a, n;
    cin >> a;
    cin >> n;
    int b = n;
    while (n > 0)
    {
        int digit = n%10;
        cout << a * digit << endl;
        n /= 10;
    }
    cout << a * b << endl;
    return 0;
}