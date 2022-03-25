

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

static struct ListNode* Add_element(struct ListNode *last_el, int val_of_new);


struct ListNode* mergeNodes(struct ListNode* head)
{
    struct ListNode *el = head->next,
             *sums = (struct ListNode *) malloc(sizeof(struct ListNode)),
             *sums_head = sums;
    int tmp_sum = 0;

    while(el != NULL)
    {
        if(el->val != 0)
            tmp_sum += el->val;
        else
        {
            sums = Add_element(sums, tmp_sum);
            tmp_sum = 0;
        }
        el = el->next;
    }

    return sums_head->next;
}

static struct ListNode* Add_element(struct ListNode *last_el, int val_of_new)
{
    struct ListNode *new_el = (struct ListNode *) malloc(sizeof(struct ListNode));
    last_el->next = new_el;
    new_el->next = NULL;
    new_el->val = val_of_new;
    return new_el;
}
