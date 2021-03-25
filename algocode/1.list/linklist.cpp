//单链表结构体
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

ListNode* list::CreateList(ListNode *head ,const int& n)  //创建单链表
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

void list::InsertList(const auto& t) //尾插法
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

void list::EraseList(const auto& t) //删除数据
    {
        ListNode* p = head;
        ListNode* q;
        if(p == NULL)
        {
            cout << "空表" << endl;
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

Listnode* list::SearchList(const auto& t)  //寻找数据节点
    {
        ListNode* p = head;
        if(p == NULL)
        {
            cout << "空表" << endl;
            return NULL;
        }

        while(p->val != t && p->next != NULL)
            p = p->next;
        if(p->val == t)
            return p;
        else
        {
            cout << t << "不存在" << endl;
            return NULL;
        }
    }

void list::ChangeList(const auto& t,const auto& c)  //更改链表数据
    {
        ListNode* p = NULL;
        p = SearchList(t);
        if(p != NULL)
           p->val = c;
    }


