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
    void merge(ListNode* start, ListNode* mid, ListNode* end){
        //now from start to mid the list is sorted
        //now what well do is well create two linked lists from original
        //left and right, make two pointers, then add the same values to the original
        ListNode *leftHead = new ListNode(), *rightHead = new ListNode();
        ListNode *curr_main = start, *curr_left = leftHead, *curr_right = rightHead;
        curr_left->val = curr_main->val;
        curr_main = curr_main->next;
        while (curr_main != mid->next && curr_main != NULL){
            curr_left->next = new ListNode();
            curr_left = curr_left->next;
            curr_left->val = curr_main->val;
        }

        //now curr_main is at mid->next, and I have to add this to the rightHead
        curr_right->val = curr_main->val;
        curr_main = curr_main->next;
        while (curr_main != NULL && curr_main != end->next){
            curr_right->next = new ListNode();
            curr_right = curr_right->next;
            curr_right->val = curr_main->val;
        }
        //now I have the left and right linked lists
        //now I'll merge them
        curr_main = start;
        curr_left = leftHead;
        curr_right = rightHead;
        while (curr_left != NULL && curr_right != NULL){
            if (curr_left->val < curr_right->val){
                curr_main->val = curr_left->val;
                curr_left = curr_left->next;
            }
            else{
                curr_main->val = curr_right->val;
                curr_right = curr_right->next;
            }
            curr_main = curr_main->next;
        }
        //now if any of the linked lists are left, I'll add them to the main list
        while (curr_left != NULL){
            curr_main->val = curr_left->val;
            curr_left = curr_left->next;
            curr_main = curr_main->next;
        }
        while (curr_right != NULL){
            curr_main->val = curr_right->val;
            curr_right = curr_right->next;
            curr_main = curr_main->next;
        }
    }
    void mergeSort(ListNode* start, ListNode* mid, ListNode* end){
        //obviously the addresses can't be compared, so I'll find the length of the nodes from start to end
        int len = 1;
        ListNode* curr = start;
        if (start == NULL || mid == NULL || end == NULL || start == end){
            return;
        }
        while (curr != end && curr != NULL){
            curr = curr->next;
            len++;
        }
        //if curr is now null, means it never became equal to end, means end was behind start
        //means we gotta do nothing in that case
        if (curr == NULL){
            return;
        }
        curr = start;
        //now I want curr to move to its next n - 1 / 2 times to reach its mid
        for (int i = 1; i <= ((n - 1) / 2); i++){
            curr = curr->next;
        }
        mergeSort(start, curr);
        mergeSort(curr->next, end);
        merge(start, curr, end);
    }
    ListNode* sortList(ListNode* head) {
        //I can create an array from it then sort it then return it as a linked list but where's the fun in that

    }
};