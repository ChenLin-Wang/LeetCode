#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    double decimal = 231.231872123;
    double d2 = 1.321927;
    cout << "The origin decimal: " << decimal << endl;
    cout << "no fixd decimals: " << setprecision(4) << decimal << " " << d2 << endl;
    cout << "The decimal: " << fixed << setprecision(4) << decimal << endl;
    cout << "The decimal2: " << d2 << endl;
    cout << "The decimal2: " << setprecision(2) << d2 << endl;
    return 0;
}