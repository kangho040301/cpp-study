#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;
struct Point {
    double x, y;
};
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    
    int n; cin >> n;
    vector<Point> point(n+1);
    double ans = 0;
    for(int i = 0; i < n; i++) {
        cin >> point[i].x >> point[i].y;
    }
    point[n].x = point[0].x;
    point[n].y = point[0].y;
    double sum1 = 0;
    double sum2 = 0;
    for(int i = 0; i < n; i++) {
        sum1 += point[i].x * point[i+1].y;
        sum2 += point[i].y * point[i+1].x;
    }
    ans = (abs(sum1 - sum2)) / 2.0;
    cout << fixed << setprecision(1) << ans << '\n';
    return 0;
}