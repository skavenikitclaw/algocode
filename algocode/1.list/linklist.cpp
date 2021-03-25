//������ṹ��
struct ListNode{
	auto val;
	ListNode* next;
};


class list
{
private:
    ListNode* head;
public:
    list():head(NULL);
    ListNode* CreateList(ListNode *head ,const int& n);
    void InsertList(const auto& t);
    void EraseList(const auto& t);
    Listnode* SearchList(const auto& t);
    void ChangeList(const auto& t,const auto& c);

};

ListNode* list::CreateList(ListNode *head ,const int& n)  //����������
    {
        ListNode* p = head;
        for (int i = 1; i < n; ++i)
        {
            ListNode* pNewNode = new ListNode;
            auto t;
            cin >> t;
            InsertList(t);
        }
    }

void list::InsertList(const auto& t) //β�巨
    {
        ListNode* p = head;
        ListNode* pNewNode = new ListNode;
        if(P == NULL)
        {
            p->val = t;
            p->next = NULL;
        }
        else
        {
            while(p->next != NULL)
                p = p->next;
            pNewNode->val = t;
            pNewNode->next = NULL;
            p->next = pNewNode;
            p = pNewNode;
        }
    }

void list::EraseList(const auto& t) //ɾ������
    {
        ListNode* p = head;
        ListNode* q;
        if(p == NULL)
        {
            cout << "�ձ�" << endl;
            return;
        }
        if(p->val == t)
        {
            head = p->next;
            delete p;
        }
        else
        {
            while(p->val != t && p->next != NULL)
            {
                q = p;
                p = p->next;
            }
            if(p->val == t)
            {
                q->next = p->next;
                delete p;
            }
        }
    }

Listnode* list::SearchList(const auto& t)  //Ѱ�����ݽڵ�
    {
        ListNode* p = head;
        if(p == NULL)
        {
            cout << "�ձ�" << endl;
            return NULL;
        }

        while(p->val != t && p->next != NULL)
            p = p->next;
        if(p->val == t)
            return p;
        else
        {
            cout << t << "������" << endl;
            return NULL;
        }
    }

void list::ChangeList(const auto& t,const auto& c)  //������������
    {
        ListNode* p = NULL;
        p = SearchList(t);
        if(p != NULL)
           p->val = c;
    }


