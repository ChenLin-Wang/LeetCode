#include "../header.h"

double Solution::findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    size_t s = nums1.size() + nums2.size();
    int i = 0;
    int j = 0;
    int n1 = 0;
    while(true) {
        int v;
        if (i >= nums1.size()) v = nums2[j];
        else if (j >= nums2.size()) v = nums1[i];
        else {
            int v1 = nums1[i], v2 = nums2[j];
            v = v1 > v2 ? v2 : v1;
        }

        if (s % 2 == 0) {
            if (i + j == s / 2 - 1) n1 = v;
            else if (i + j == s / 2) return ((double)n1 + (double)v) / 2.0;
        } else {
            if (i + j == s / 2) return v;
        }

        if (i >= nums1.size()) j++;
        else if (j >= nums2.size()) i++;
        else {
            int v1 = nums1[i], v2 = nums2[j];
            if (v2 > v1) i++;
            else j++;
        }
    }
}

// double medianOfArray(vector<int> arr) {
//     size_t s = arr.size();
//     if (s % 2 == 0) {
//         return ((double)arr[s / 2] + (double)arr[s / 2 - 1]) / (double)2;
//     } else {
//         return arr[s / 2];
//     }
// }

// double Solution::findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
//     if (nums1.size() == 0 && nums2.size() == 0) return 0;
//     if (nums1.size() == 0) return medianOfArray(nums2);
//     if (nums2.size() == 0) return medianOfArray(nums1);

//     size_t s = nums1.size() + nums2.size();

//     int i = 0;
//     int j = 0;
//     int iOver = false;
//     int jOver = false;
//     int ready = 0;
//     while(true) {
//         int v1 = nums1[i], v2 = nums2[j];
//         int v;

//         bool addI;

//         if (iOver) { v = v2; addI = false;}
//         else if (jOver) { v = v1; addI = true; }
//         else { v = v1 > v2 ? v2 : v1; addI = v1 > v2 ? false : true; }

//         int t = j + i + (jOver || iOver ? 1 : 0); 

//         cout << t << " - " << i << ":" << j << " = " << v << endl;

//         if (s % 2 == 0) {
//             if (t == s / 2 - 1) ready = v;
//             else if (t == s / 2) return ((double)ready + (double)v) / 2.0;
//         } else {
//             if (t == s / 2) return v;
//         }

//         if (iOver) j++;
//         else if (jOver) i++;
//         else {
//             if (addI) {
//                 if (i == nums1.size() - 1) iOver = true;
//                 else i++;
//             } else {
//                 if (j == nums2.size() - 1) jOver = true;
//                 else j++;
//             }
//         }
//     }
// }

void Test::test4() {
    vector<int> v1 = {1, 2};
    vector<int> v2 = {3, 4};
    cout << Solution::findMedianSortedArrays(v1, v2) << endl;
}