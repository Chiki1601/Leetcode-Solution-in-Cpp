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
    int maxi = INT_MIN;
    ListNode* solve(ListNode* head){
        //base
        if(head->next==NULL){
            maxi = max(head->val, maxi);
            return head;
        }
        
        //hypo
        head->next = solve(head->next);
        //lets see if the head can make it to the final list or not
        if(head->val<maxi){
            // head->next = NULL;
            maxi = max(maxi, head->next->val);
            return head->next;
        }
        maxi = max(maxi, head->val);
        return head;
        
    }
    ListNode* removeNodes(ListNode* head) {
        return solve(head);
    }
};
