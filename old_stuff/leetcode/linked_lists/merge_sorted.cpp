struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if (list1 == nullptr) return list2; 
        else if (list2 == nullptr) return list1; 
        ListNode *merged, *lastnode;
        // initialize the values
        if (list1->val < list2->val) {
            merged = lastnode = list1;
            list1 = list1->next;
        } else {
            merged = lastnode = list2;
            list2 = list2->next;
        }

        while (list1 != nullptr and list2 != nullptr) {
            if (list1->val < list2->val) {
                lastnode->next = list1;
                list1 = list1->next;
            } else {
                lastnode->next = list2;
                list2 = list2->next;
            }
            lastnode = lastnode->next;
        }    
        // one of them (or both) are not null, finish them
        if (list1 != nullptr) lastnode->next = list1; 
        if (list2 != nullptr) lastnode->next = list2; 
        return merged;     
    }
};