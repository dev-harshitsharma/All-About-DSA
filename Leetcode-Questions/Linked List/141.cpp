/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        //empty list check 
        if(head == NULL) return false;

        //NULL phnch jao to circular nhi h agar phnch jao to circluar h
        //logic 1 is used 
    //     ListNode* temp = head->next;

    //     while (temp != NULL && temp!= head){
    //         temp = temp->next;
    //     }

    //    bool result = (temp == head) ? true : false;

    //     return result;

        //Logic 2 -> Use map ,key=Node && value: boolean 

        ListNode *slow = head, *fast = head;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast) return true;
        }
        
        return false;
    }
};
