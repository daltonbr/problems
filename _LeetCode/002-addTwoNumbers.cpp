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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2)
    {   
        int carry = 0;
        
        int sum = l1->val + l2->val;
        
        ListNode* head = new ListNode(sum % 10 + carry);
        carry = (sum > 9) ? 1 : 0;
        ListNode* l3 = head;
        
        while (l1->next != nullptr && l2->next != nullptr)
        {
            l1 = l1->next;
            l2 = l2->next;
            
            int sum = l1->val + l2->val + carry;
            l3->next = new ListNode(sum % 10);
            carry = (sum > 9) ? 1 : 0;
            
            l3 = l3->next;
        }
        
        while (l1->next != nullptr)
        {
            l1 = l1->next;
            int sum = l1->val + carry;
            l3->next = new ListNode(sum % 10);
            carry = (sum > 9) ? 1 : 0;
            l3 = l3->next;
        }
        
        while (l2->next != nullptr)
        {
            l2 = l2->next;
            int sum = l2->val + carry;
            l3->next = new ListNode(sum % 10);
            carry = (sum > 9) ? 1 : 0;
            l3 = l3->next;
        }
        
        if (carry == 1) l3->next = new ListNode(carry);
        
        return head;
    }
};
