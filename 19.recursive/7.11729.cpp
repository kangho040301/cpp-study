#include <iostream>
using namespace std;
void hanoi_move(int n, int start, int to, int via) {
    if(n == 1) {
        cout << start << ' ' << to << '\n';
        return;
    }
    n--;
    hanoi_move(n, start, via, to);
    hanoi_move(1, start, to , via);
    hanoi_move(n, via, to , start);
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    
    int n;
    cin >> n;
    int len = (1<<n) -1;
    cout << len << '\n';
    hanoi_move(n, 1, 3, 2);
    return 0;
}