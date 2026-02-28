#include <iostream>
#include <string>
using namespace std;
int main() {
    int n;
    string l = "";
    cin >> n;
    if (n%4 != 0) {
        cout << "n은 4의 배수여야함" << endl;
        return 0;
    }
    n = n /4 ;
    for (int i = 0; i < n; i++) {
        l = l + "long ";
    }
    cout << l << "int" << endl;
    return 0;
}