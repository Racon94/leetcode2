// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem142.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=142 lang=cpp
 *
 * [142] 环形链表 II
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution
{
public:
    ListNode *detectCycle(ListNode *head)
    {
        if (head == nullptr)
        {
            return nullptr;
        }
        ListNode *slow = head, *fast = head, *ptr = nullptr;

        while (true)
        {
            if (fast == nullptr || fast->next == nullptr)
            {
                return nullptr;
            }
            else
            {
                slow = slow->next;
                fast = fast->next->next;
                if (fast == slow)
                {
                    break;
                }
            }
        }
        ptr = head;
        while (slow != ptr)
        {
            slow = slow->next;
            ptr = ptr->next;
        }
        return ptr;
    }
};
// @lc code=end
