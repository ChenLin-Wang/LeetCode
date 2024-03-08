#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

struct ListNode;

class Solution {
public:
    static void rotate(vector<int>& nums, int k);
    static vector<int> plusOne(vector<int>& digits);
    static int pivotIndex(vector<int>& nums);
    static int findMaxConsecutiveOnes(vector<int>& nums);
    static vector<int> productExceptSelf(vector<int>& nums);
    static vector<int> findDiagonalOrder(vector<vector<int>>& mat);
    
    static ListNode* deleteDuplicates(ListNode* head);
    static ListNode* deleteDuplicates2(ListNode* head);
    static ListNode* reverseList(ListNode* head);
    static ListNode* reverseBetween(ListNode* head, int left, int right);
    static ListNode* reverseKGroup(ListNode* head, int k);
};


class Test {

public:
    static void test189();
    static void test66();
    static void test724();
    static void test485();
    static void test238();
    static void test498();
    static void test707();
    static void test83();
    static void test82();
    static void test206();
    static void test92();
    static void test25();
};