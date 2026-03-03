#include <iostream>
#include <string>
using namespace std;
double is_plus(char c, double n) {
    if(c == '+') return n + 0.5;
    else return n;
}
void do_sum(double &a, double &b, double credit, double gpa) {
    a += credit * gpa;
    b += credit;
} 
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    double sum_cg = 0.0;
    double sum_c = 0.0;

    for(int i = 0; i < 20; i++) {
        string subject;
        double credit;
        string grade;
        cin >> subject >> credit >> grade;
        double gpa = 0.0;
        switch (grade[0]) {
            case 'P' :
                break;
            case 'A' :
                gpa = is_plus(grade[1],4.0);
                do_sum(sum_cg, sum_c, credit, gpa);
                break;
            case 'B' :
                gpa = is_plus(grade[1],3.0);
                do_sum(sum_cg, sum_c, credit, gpa);
                break;
            case 'C' :
                gpa = is_plus(grade[1],2.0);
                do_sum(sum_cg, sum_c, credit, gpa);
                break;
            case 'D' :
                gpa = is_plus(grade[1],1.0);
                do_sum(sum_cg, sum_c, credit, gpa);
                break;
            case 'F' :
                gpa = 0.0;
                do_sum(sum_cg, sum_c, credit, gpa);
                break;
        }
    }
    cout << sum_cg/sum_c << '\n';
    return 0;
}