
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if (head == nullptr) return nullptr; 
        ListNode *lastodd = head; 
        ListNode *firsteven;
        ListNode *lasteven = firsteven = head->next; 
        
        // scorro due alla volta:
        // il primo lo appendo ai dispari, il secondo ai pari
        while (lasteven != nullptr and lasteven->next != nullptr) {
            ListNode *currodd = lasteven->next;
            lastodd->next = currodd; 
            lasteven->next = currodd->next;
            currodd->next = firsteven;
            lastodd = currodd;
            lasteven = lasteven->next;
        }
        return head; 
    }
};