#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

int main() {
   vector<vector<string>> v;
   cout << "Enter:" << endl;
   
   string line;
   
   while(getline(cin, line) && !line.empty()) {
       vector<string> row;
       stringstream ss(line);
       string value;
       
       while(ss >> value) {
           row.push_back(value);
       }
       
       v.push_back(row);
   }
   
   for(auto row: v) {
       for (auto value: row) {
           cout << value << " ";
       }
       
       cout << endl;
   }
   
   return 0; 
}