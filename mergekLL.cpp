//MERGE K SORTED LISTS TIME TAKEN: 42 MS MEMORY TAKEN: 13.9 MB HARD LEVEL LEETCODE
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
    void insertathead(ListNode* &head, int data){
        ListNode* temp = new ListNode(data);
        if(head==NULL){
            head = temp;
        }
        else{
            temp->next = head;
            head = temp;
        }
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size()==0){
            return NULL;
        }
        if(lists.size()==1){
            return lists[0];
        }
        vector<int> vec;
        priority_queue<int> maxheap;
        for(int i=0;i<lists.size();i++){
            ListNode* temp = lists[i];
            while(temp != NULL){
                maxheap.push(temp->val);
                temp = temp->next;
            }
        }
        ListNode* head = NULL;
        while(!maxheap.empty()){
            insertathead(head, maxheap.top());
            maxheap.pop();
        }
        return head;
    }
};
