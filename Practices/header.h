#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

struct ListNode;

class Solution {
public:
    // ------ set 1
    static void rotate(vector<int>& nums, int k);
    static vector<int> plusOne(vector<int>& digits);
    static int pivotIndex(vector<int>& nums);
    static int findMaxConsecutiveOnes(vector<int>& nums);
    static vector<int> productExceptSelf(vector<int>& nums);
    static vector<int> findDiagonalOrder(vector<vector<int>>& mat);
    // -> 707
    static ListNode* deleteDuplicates(ListNode* head);
    static ListNode* deleteDuplicates2(ListNode* head);
    static ListNode* reverseList(ListNode* head);
    static ListNode* reverseBetween(ListNode* head, int left, int right);
    static ListNode* reverseKGroup(ListNode* head, int k);
    static ListNode* oddEvenList(ListNode* head);
    static ListNode* rotateRight(ListNode * head, int k);
    static bool isValid(string s);
    static int calculate(string s);
    static string removeDumplicates(string s);
    // ------ set 2
    // -> 155
    static vector<int> dailyTemperatures(vector<int>& temperatures);
    static int evalRPN(vector<string>& tokens);
};


class Test {

public:
    // ------ set 1
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
    static void test328();
    static void test61();
    static void test20();
    static void test227();
    static void test1047();
    // ------ set 2
    static void test155();
    static void test739();
    static void test150();
};