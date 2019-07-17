/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */



struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2){
    int carry=0, node=0;
    struct ListNode *N = malloc(sizeof(struct ListNode));
    struct ListNode *current = N;
    while (l1!=NULL || l2!=NULL){
        node = carry;
        if (l1 != NULL){
            node += l1->val;
        }
        if (l2 != NULL){
            node += l2->val;
        }

        if (node >= 10){
            node -= 10;
            carry = 1;
        }
        else carry = 0;

        current->val = node;

        if (l1!=NULL) l1 = l1->next;
        if (l2!=NULL) l2 = l2->next;
        if (l1 || l2){
            current->next = malloc(sizeof(struct ListNode));
            current = current->next;
        }
        else if (carry){
            current->next = malloc(sizeof(struct ListNode));
            current = current->next;
            current->val = 1;
            break;
        }

    }
    current->next = NULL;
    return N;
}
