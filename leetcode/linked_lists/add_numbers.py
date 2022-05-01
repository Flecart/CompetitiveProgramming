class ListNode:
     def _init_(self, val=0, next=None):
        self.val = val
        self.next = next

class Solution:
    def addTwoNumbers(self, l1: Optional[ListNode], l2: Optional[ListNode]) -> Optional[ListNode]:
        # gestisco a parte il primo caso perché mi dava dei problemi
        result = ListNode((l1.val + l2.val) % 10) 
        coda = result 
        carry = (l1.val + l2.val) // 10  # // prende la divisione intera
        l1 = l1.next 
        l2 = l2.next 
        while l1 != None or l2 != None:
            coda.next = ListNode() 
            coda = coda.next 
            if l1 != None and l2 != None:
                coda.val = (l1.val + l2.val + carry) % 10
                carry = int (( l1.val+l2.val + carry) // 10)
                                
            else :
                if l1 == None:
                    coda.val = (l2.val + carry) % 10
                    carry = (l2.val + carry) // 10 

                else :
                    coda.val = (l1.val + carry) % 10
                    carry = (l1.val + carry) // 10

            if l1: 
                l1 = l1.next 
            if l2:
                l2 = l2.next 

        if carry > 0:
            coda.next = ListNode() 
            coda = coda.next 
            coda.val = carry 
        return result