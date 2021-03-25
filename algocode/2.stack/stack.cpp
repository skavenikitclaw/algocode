// ���
struct Node {
    int data;
    Node *next;
};

// ջ
struct StackNode{
    Node *Top;
    Node *Bottom;
};

class stack
{
public:
	void Init(StackNode *t);
    void CreateStack(StackNode *t);
    void Travers(StackNode *t);
    void Push(StackNode *t, int val);
    bool Pop(StackNode *t);
    bool getTop(StackNode *t, int &val);
    bool isEmpty(StackNode *t);
    int getSize(StackNode *t);
};



void stack::Init(StackNode *t)  // ��ʼ��
{
    t->Top = new Node();
    t->Bottom = t->Top;
    t->Top->next = NULL;
}


void stack::CreateStack(StackNode *t)  // ��ջ
{
    int val;

    while(cin >> val && val != -1)
        Push(t, val);
}


void stack::Travers(StackNode *t)  // ����ջ
{
    Node *p = t->Top;

    while(p != t->Bottom) {
        cout << p->data << " ";
        p = p->next;
    }
    cout << endl;
}


void stack::Push(StackNode *t, int val)  // ѹջ
{
    Node *newNode = new Node();
    newNode->data = val;
    newNode->next = t->Top;
    t->Top = newNode;
}



bool stack::Pop(StackNode *t)  // ��ջ
{
    if(isEmpty(t))
        return false;
    Node *r = t->Top;
    t->Top = r->next;
    delete r;
    r = NULL;
    return true;
}


bool stack::getTop(StackNode *t, int &val)  // ��ȡջ��Ԫ��
{
    if(isEmpty(t))
        return false;
    val = t->Top->data;
    return true;
}



bool stack::isEmpty(StackNode *t)  // �ж�ջ�Ƿ�Ϊ��
{
    if(t->Top == t->Bottom)
        return true;
    return false;
}



int stack::getSize(StackNode *t)  // ��ȡջ�ĳ���
{
    int len = 0;
    Node *p = t->Top;
    while(p != t->Bottom) {
        len++;
        p = p->next;
    }
    return len;
}
