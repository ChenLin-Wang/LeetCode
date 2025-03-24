#include "../header.h"
#include <map>

int hashStr(string str) {
    int hash = 0;
    int i = 0;
    for (const char &c: str) {
        hash += c * i;
        i ++;
    }
    hash %= 2069;
    return hash;
}

int Solution::wordsFrequency(string word, vector<string>& book) {
    map<int, int> m;
    for (const auto &w: book) {
        m[hashStr(w)] += 1;
    }
    return m[hashStr(word)];
}

void Test::test16_02() {
    vector<string> book = {"i", "have", "an", "apple", "he", "have", "a", "pen"};
    cout << Solution::wordsFrequency("apple", book) << endl;
}