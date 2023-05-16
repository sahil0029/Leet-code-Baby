class Solution {
public:
ListNode* swapPairs(ListNode* head) {
ListNode* dnode = new ListNode(-1);
ListNode* prev = dnode;

ListNode* curr = head;
dnode->next = head;
while(curr != NULL && curr->next != NULL){
prev->next = curr->next;
curr->next = curr->next->next;
prev->next->next = curr;
curr = curr->next;
prev = prev->next->next;
}
return dnode->next;
}
};