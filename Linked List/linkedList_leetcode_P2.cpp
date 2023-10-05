//
// Created by hamza on 05/10/2023.
//


// Algorithm

// 1. first create a new list with node   (0,nullptr);=> this can be used for listHead;
// 2. create a current node which points to the list;
// 3. also create a carry which will store the carry if the number is above 9;
// 4. as both the list may or may not be same so run the while loop till if one of it is true (l1 , l2 , carry);
// 5. also create checks because if one of them get null so there will be no val and next for val put 0 and for next do nothing;
// 6. add the values l1, l2 and carry;
// 7. store the carry as = sum/10 , and digit which we will insert in the node as digit = sum%10;
// 8. create a newNode as (digit);
// 9. store its address in current->next;
// 10. store the current->next address or newNode address in current;


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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* newListHead = new ListNode();
        ListNode* current = newListHead;

        int carry = 0;
        while(l1 != nullptr || l2!= nullptr || carry !=0){
            int sum = (l1 ? l1->val : 0) + (l2 ? l2->val : 0) + carry;
            carry = sum/10;
            int digit = sum%10;
            current->next = new ListNode(digit , nullptr);
            current = current->next;


            if(l1) l1 = l1->next;
            if(l2) l2 = l2->next;
        }

        return newListHead->next;

    }
};
