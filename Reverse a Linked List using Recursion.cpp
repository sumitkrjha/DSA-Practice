/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        // Break point: If the next node is null then return the head
        if(head==nullptr || head->next==nullptr)
        {
            return head;
        }
        // Assign the next node of the current node as new head and call the function
        ListNode* newHead=reverseList(head->next);
        // After the above recursive call ends in the eg 1->2->3->4->5
        // When the node reaches 5 as new head and the break point applies as 5->next is nullptr
        // hence the head as of now would be 4 as the new head is head->next and 
        // head->next=5 so head is 4

        // 4->next->next=4, ie, 5->next=4
        head->next->next=head;
        // 4->next then is nullptr
        head->next=nullptr;

        return newHead;
    }
};