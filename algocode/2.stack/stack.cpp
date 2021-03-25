// 结点
struct Node {
    int data;
    Node *next;
};

// 栈
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



void stack::Init(StackNode *t)  // 初始化
{
    t->Top = new Node();
    t->Bottom = t->Top;
    t->Top->next = NULL;
}


void stack::CreateStack(StackNode *t)  // 建栈
{
    int val;

    while(cin >> val && val != -1)
        Push(t, val);
}


void stack::Travers(StackNode *t)  // 遍历栈
{
    Node *p = t->Top;

    while(p != t->Bottom) {
        cout << p->data << " ";
        p = p->next;
    }
    cout << endl;
}


void stack::Push(StackNode *t, int val)  // 压栈
{
    Node *newNode = new Node();
    newNode->data = val;
    newNode->next = t->Top;
    t->Top = newNode;
}



bool stack::Pop(StackNode *t)  // 出栈
{
    if(isEmpty(t))
        return false;
    Node *r = t->Top;
    t->Top = r->next;
    delete r;
    r = NULL;
    return true;
}


bool stack::getTop(StackNode *t, int &val)  // 获取栈顶元素
{
    if(isEmpty(t))
        return false;
    val = t->Top->data;
    return true;
}



bool stack::isEmpty(StackNode *t)  // 判断栈是否为空
{
    if(t->Top == t->Bottom)
        return true;
    return false;
}



int stack::getSize(StackNode *t)  // 获取栈的长度
{
    int len = 0;
    Node *p = t->Top;
    while(p != t->Bottom) {
        len++;
        p = p->next;
    }
    return len;
}
