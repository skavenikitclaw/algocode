//题目主要来源于leetcode

/*反转链表
给你单链表的头指针head和两个整数left和right,其中left <= right。请你反转从位置left到位置right的链表节点,返回反转后的链表。 */


class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode *res = new ListNode(-1);
        res->next = head;
        ListNode *pre = res;
        for (int i = 0; i < left - 1; i++) {
            pre = pre->next;
        }
        ListNode *cur = pre->next;
        ListNode *next;
        for (int i = 0; i < right - left; i++) {
            next = cur->next;
            cur->next = next->next;
            next->next = pre->next;
            pre->next = next;
        }
        return res->next;
    }
};




/*两数相加
给你两个非空的链表，表示两个非负的整数。它们每位数字都是按照逆序的方式存储的，并且每个节点只能存储一位数字。
请你将两个数相加，并以相同形式返回一个表示和的链表。
你可以假设除了数字0之外，这两个数都不会以0开头。 */


class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {

        ListNode* head = new ListNode(-1);
        ListNode* til = head;
        bool carry = false;
        int sum = 0;

        while(l1!=NULL||l2!=NULL)
        {
            sum = 0;
            if(l1!=NULL)
                {
                    sum += l1->val;
                    l1 = l1->next;
                }
            if(l2!=NULL)
                {
                    sum += l2->val;
                    l2 = l2->next;
                }
            if(carry)
                sum++;
            til->next = new ListNode(sum%10);
            til = til->next;
            if(sum>=10)
                carry = true;
            else
                carry = false;
        }
        if(carry)
            til->next = new ListNode(1);
        return head->next;
    }
};




/*相交链表
编写一个程序，找到两个单链表相交的起始节点。 */


class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if(headA == nullptr || headB == nullptr)
            return nullptr;

        ListNode *L1 = headA, *L2 = headB;
        while (L1 != L2)
        {
            L1 = L1 ? L1->next : headB;
            L2 = L2 ? L2->next : headA;
        }
        return L1;
    }
};




/*合并两个递增链表
将两个升序链表合并为一个新的升序链表并返回。  */


class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2){
    if ((!l1) || (!l2))
        return l1 ? l1 : l2;
    ListNode* head = new ListNode(-1);
    ListNode* pre = head;
    while (l1 && l2)
    {
        if (l1->val < l2->val)
        {
            pre->next = l1;
            l1 = l1->next;
        }
        else
        {
            pre->next = l2; l2 = l2->next;
        }
        pre = pre->next;
    }
    pre->next = l1 ? l1 : l2;
    return head->next;
    }
};



/*排序列表
给你链表的头结点head，请将其按升序排列并返回排序后的链表。
在O(nlogn)时间复杂度和常数级空间复杂度下，对链表进行排序。 */


class Solution {
public:
    ListNode* sortList(ListNode* head) {
        if(head == nullptr || head->next == nullptr)
            return head;
        int len = 0;
        ListNode* p = head;
        while(p != nullptr)
        {
            p = p->next;
            len++;
        }
        ListNode* pres = new ListNode(-1);
        pres->next = head;
        for(int size = 1;size < len;size *= 2)
        {
            ListNode* cur = pres->next;
            ListNode* tail = pres;
            while(cur != nullptr)
            {
                ListNode* left = cur;
                ListNode* right = cut(left,size);
                cur = cut(right,size);
                tail->next = merge(left,right);
                while(tail->next != nullptr)
                    tail = tail->next;
            }
        }
        return pres->next;
    }

    ListNode* cut(ListNode* head, int n) {
        ListNode* p = head;
        while (--n && p)
        {
            p = p->next;
        }
        if(p==nullptr)
            return nullptr;
        ListNode* res = p->next;
        p->next = nullptr;
        return res;
    }

    ListNode* merge(ListNode* l1, ListNode* l2){
    if ((!l1) || (!l2))
        return l1 ? l1 : l2;
    ListNode* head = new ListNode(-1);
    ListNode* pre = head;
    while (l1 && l2)
    {
        if (l1->val < l2->val)
        {
            pre->next = l1;
            l1 = l1->next;
        }
        else
        {
            pre->next = l2; l2 = l2->next;
        }
        pre = pre->next;
    }
    pre->next = l1 ? l1 : l2;
    return head->next;
    }
};
