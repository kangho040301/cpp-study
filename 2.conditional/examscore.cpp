#include <iostream>
using namespace std;
int main() 
{
    int score;
    cin >> score;
    if (0 > score || score > 100) {
        cout << "점수는 0~100사이 입니다." << endl;
        return 0;
    }
    if (score >= 90) {
        cout << "A" << endl;
    }
    else if (score >= 80) {
        cout << "B" << endl;
    }
    else if (score >= 70) {
        cout << "C" << endl;
    }
    else if (score >= 60) {
        cout << "D" << endl;
    }
    else cout << "F" << endl;
    return 0;
}