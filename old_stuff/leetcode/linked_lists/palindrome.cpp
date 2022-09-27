struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

#include <stack>
class Solution {
public:
    // simple solution in O(n) time and space, but have to use a stack
    bool isPalindrome(ListNode* head) {
        ListNode *node = head; 
        std::stack<int> reversed;
        while (node != nullptr) {
            reversed.push(node->val);
            node = node->next;
        } 
        
        while (head != nullptr) {
            if (head->val != reversed.top()) {
                return false; 
            }
            head = head->next;
            reversed.pop();
        }
        return true; 
    }

    // the solution that used O(n) time and O(1) auxiliary space is like this:
    // revert the linked list until mid of the list (if len is odd leave the middle
    // buddy alone)
    // then trasverse both lists at the same time.
};