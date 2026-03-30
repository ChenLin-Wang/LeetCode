#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    string str = "abcd";
    
    transform(str.begin(), str.end(), str.begin(), ::toupper);
    
    // transform(str.begin(), str.end(), str.begin(), [] (char c1) {
    //     return toupper(c1);
    // });
    
    cout << str << endl;
    
    return 0;
}