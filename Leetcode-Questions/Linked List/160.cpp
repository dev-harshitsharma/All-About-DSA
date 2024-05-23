class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if(headA==NULL || headB==NULL){
            return NULL;
        }
        ListNode* dummy1=headA;
        ListNode* dummy2=headB;
        
        while(dummy1!=dummy2){
            if(dummy1==NULL){
                dummy1=headB;
            }
            else{
                dummy1=dummy1->next;
            }
            
            if(dummy2==NULL){
                dummy2=headA;
            }
            else{
                dummy2=dummy2->next;
            }
        }
        return dummy2;

    }
};

//Approach 1
//step1 => find the lenght of bnoth the linked list 
//step2 -> find the difference bwtween the lenghts 
//step3 -> Move the longer list with added difference and simultaneously move dummy 1 and dummy 2 
//step4 -> Movement duummy 1 and dummy 2 collides that is the intersection point 

/* Approach 2 

1. d1 = head1 , d2=head2 and start moving them 
2.when longer list dumy pointer reaches the head of the linkedlist assign the node to the head of the other linked list 
3.Move both the node untill it reaches the end 
4. Beforre next iteration the dummy nodes will be standing at same point , then when both the linked list collide then both the dummy1 and dummy 2 will be at intersection

*/