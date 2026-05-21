#include <iostream>

using namespace std;

string findAndReplaceAll(string str, string keyword, string replacement) {
    string res = str;
    size_t index;
    while((index = res.find(keyword)) != string::npos) {
        res.replace(index, keyword.size(), replacement);
    }
    return res;
}

int main() {
    string keyword = "so wonderful";
    string str = "Hello, today is so wonderful, also the sky, is so wonderful too!";
    
    string result1 = str;
    size_t index = result1.find(keyword);
    result1.replace(index, keyword.size(), "terrible");
    cout << result1 << endl;
    
    string result2 = str;
    size_t index2 = result2.rfind(keyword);
    result2.replace(index2, keyword.size(), "terrible");
    cout << result2 << endl;
    
    string result3 = findAndReplaceAll(str, "so wonderful", "funny");
    cout << result3 << endl;
    
    return 0;
}