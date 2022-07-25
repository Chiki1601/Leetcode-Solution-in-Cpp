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
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        vector<vector<int>> ans(m,vector<int>(n,-1));
        int k=0,l=0;
        while(k<m && l<n){
            // top row of boundary
            for(int i=l;i<n;i++){
                if(head==nullptr){
                    break;
                }
                ans[k][i]=head->val;
                head=head->next;
            }
            k++;

            for(int i=k;i<m;i++){
                if(head==nullptr){
                    break;
                }
                ans[i][n-1]=head->val;
                head=head->next;
            }
            n--;

            if(k<m){
                for(int i=n-1;i>=l;i--){
                    if(head==nullptr){
                        break;
                    }
                    ans[m-1][i]=head->val;
                    head=head->next;
                }
                m--;
            }
            if(l<n){
                for(int i=m-1;i>=k;i--){
                    if(head==nullptr){
                        break;
                    }
                    ans[i][l]=head->val;
                    head=head->next;
                }
                l++;
            }                
        }
        return ans;
    }
};

