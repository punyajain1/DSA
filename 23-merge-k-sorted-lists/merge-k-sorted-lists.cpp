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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        vector<int>v;
        for(auto a: lists){
            while(a!=nullptr){
                v.push_back(a->val);
                a=a->next;
            }

        }
        sort(v.begin(),v.end());
        ListNode ans(0);
        ListNode* t = &ans;
        for(auto x:v){
            t->next=new ListNode(x);
            t=t->next;
        }
        return ans.next;
    }
};