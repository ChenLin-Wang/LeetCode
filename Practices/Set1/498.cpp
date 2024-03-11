#include "../header.h"

vector<int> Solution::findDiagonalOrder(vector<vector<int>>& mat) {
    int m = mat.size(), n = mat[0].size();
    if (m == 1) return mat[0];
    vector<int> res(m * n);
    if (n == 1) {
        int i = 0;
        for (auto c : mat) {
            res[i] = mat[i][0];
            i ++;
        }
        return res;
    }
    res[0] = mat[0][0];
    int x = 0, y = 0;
    int i = 0;
    bool swi = false;
    while(x < m - 1 || y < n - 1) {
        bool ctn = false;
        if (!swi) {
            if (x == m - 1) { y ++; swi = true; }  // Bottom
            else if (y == n - 1) { x ++; swi = true; }  // Right
            else if (x == 0) { y ++; swi = true; }  // Top
            else if (y == 0) { x ++; swi = true; }  // Left
            else ctn = true;
        } else { ctn = true; swi = false; }

        if (ctn) {
            if ((x + y) % 2 == 1) { x++; y--; } 
            else { x--; y++; }
        }
        res[i + 1] = mat[x][y];
        i ++;
    }
    return res;
}



// vector<int> Solution::findDiagonalOrder(vector<vector<int>>& mat) {
//     int m = mat.size(), n = mat[0].size();
//     vector<int> res(m * n);
//     res[0] = mat[0][0];
//     int x = 0, y = 0;
//     int i = 0;
//     bool swi = false;
//     while(i < m * n - 1) {
//         if (x == m - 1 && swi == false) {
//             y++;
//             swi = true;
//         } else if (y == n - 1 && swi == false) {
//             x++;
//             swi = true;
//         } else {
//             swi = false;
//             if ((x + y) % 2 == 1) {
//                 x++; y--;
//             } else {
//                 x--; y++;
//             }

//             if (x < 0 || x > m - 1 || y < 0 || y > n - 1) swi = true; else swi = false;

//             x = (x < 0) ? 0 : x; y = (y < 0) ? 0 : y;
//             x = (x > m - 1) ? m - 1 : x; y = (y > n - 1) ? n - 1 : y;
//         }
        
//         // cout << x << "  " << y << endl;
//         res[i + 1] = mat[x][y];
//         i ++;
//     }

//     return res;
// }



void Test::test498() {
    vector<vector<int>> mat = {
        {1, 2, 3, 4},
        // {5, 6, 7, 8},
        // {9, 10, 11, 12},
        // {13, 14, 15, 16}
    };
    vector<int> res = Solution::findDiagonalOrder(mat);
    for (auto i : res) cout << i << endl;
}