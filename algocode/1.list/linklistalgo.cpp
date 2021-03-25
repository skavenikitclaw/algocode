//��Ŀ��Ҫ��Դ��leetcode

/*��ת����
���㵥�����ͷָ��head����������left��right,����left <= right�����㷴ת��λ��left��λ��right������ڵ�,���ط�ת������� */


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




/*�������
���������ǿյ�������ʾ�����Ǹ�������������ÿλ���ֶ��ǰ�������ķ�ʽ�洢�ģ�����ÿ���ڵ�ֻ�ܴ洢һλ���֡�
���㽫��������ӣ�������ͬ��ʽ����һ����ʾ�͵�����
����Լ����������0֮�⣬����������������0��ͷ�� */


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




/*�ཻ����
��дһ�������ҵ������������ཻ����ʼ�ڵ㡣 */


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




/*�ϲ�������������
��������������ϲ�Ϊһ���µ������������ء�  */


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



/*�����б�
���������ͷ���head���뽫�䰴�������в���������������
��O(nlogn)ʱ�临�ӶȺͳ������ռ临�Ӷ��£�������������� */


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
