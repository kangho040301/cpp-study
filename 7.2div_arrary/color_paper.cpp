#include <iostream>
#include <vector>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    int n;
    cin >> n;
    vector<vector<bool>> area(100, vector<bool>(100, false));
    int total_area = 0;
    for(int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        for(int r = x; r < x + 10; r++) {
            for(int c = y; c < y + 10; c++) {
                if(!(area[r][c])) {
                    area[r][c] = true;
                    total_area++;
                }
            }
        }
    }
    cout << total_area << '\n';
    return 0;
}