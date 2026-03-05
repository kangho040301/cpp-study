//1, 1+2, 1+2+3, 1+2+3+4 ... / 2,3,4,5,6 ...
/*
1.1/1
2.1/2 2/1
3.3/1 2/2 1/3
4.1/4 2/3 3/2 4/1
5.5/1 4/2 3/3 2/4 1/5
.
.
.
*/
#include <iostream>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    int x;
    cin >> x;
    int row = 1;
    // x = 2, row = 2 -> x = 0
    // x = 3, row = 2 -> x = 1
    // x = 4, row = 2 -> x = 2, row = 3 -> x = -1   
    // x = 5, row = 2 -> x = 3, row = 3 -> x = 0
    // x = 6, row = 2 -> x = 4, row = 3 -> x = 1  
    while(x > 1) {
        row++;
        x -= row;
    }
    //row = 2 -> x = 0
    //row = 3 -> x = -1
    //row = 4 -> x = -2 ... row + x = 2

    //row = 2 / x = 0, 1 / row + x = 2, 3 -> 1, 2/ 2, 1
    //row = 4 / x = -2, -1, 0, 1 / row + x = 2, 3, 4, 5 -> 1, 2, 3, 4 / 4, 3, 2, 1
    //row = 3 / x = -1, 0, 1 
    //row + x = 2, 3 ,4 -> 3, 2, 1 / 1, 2, 3
    //row = 5 / x = -3, -2, -1, 0, 1 
    //row + x = 2, 3, 4, 5, 6 -> 5, 4, 3, 2, 1 / 1, 2, 3, 4, 5
    if(row%2 == 1) {
        cout << -1*x + 2 << '/' << row + x - 1 << '\n';
    }
    else {
        cout << row + x - 1 << '/' << -1*x + 2 << '\n';
    }
    return 0;
}