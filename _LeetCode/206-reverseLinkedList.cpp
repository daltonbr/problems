/**
 * 206 - Reverse Linked List
 * https://leetcode.com/problems/reverse-linked-list/description/
 * 
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
    ListNode* reverseList(ListNode* head)
    {
        // deal with empty lists
        if (head == nullptr) return head;
        
        ListNode* current = head;
        ListNode* next = current->next;
        ListNode* previous = nullptr;
                       
        while (next != nullptr)
        {            
            current->next = previous;
            previous = current;
            current = next;
            next = current->next;
        }
        current->next = previous;
        return current;
            
    }
};