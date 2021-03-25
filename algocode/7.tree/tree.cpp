//������
struct TreeNode
{
    int val;
    TreeNode *lchild,*rchild;
};

class Tree
{
public:
    TreeNode *Create(TreeNode *t);
    void Release(TreeNode *t);
    void PreOrder(TreeNode *t);
    void InOrder(TreeNode *t);
    void PostOrder(TreeNode *t);
};


TreeNode *Tree::Create(TreeNode *t)         //����������
{
    int ch;
    cin >> ch;
    if(ch == '#')
        t = NULL;
    else
    {
        Tree *t = new TreeNode;
        t->val = ch;
        t->lchild = Create(t->lchild);
        t->rchild = Create(t->rchild);
    }
    return t;
}


void Tree::Release(TreeNode *t)           //�ͷŶ�����
{
    if(t != NULL)
    {
        Release(t->lchild);
        Release(t->rchild);
        delete t;
    }
}



void Tree::PreOrder(TreeNode *t)            //ǰ�����
{
    if(t == NULL)
        return;
    else
    {
        cout << t->val;
        PreOrder(t->lchild);
        PreOrder(t->rchild);
    }
}



void Tree::InOrder(TreeNode *t)             //�������
{
    if(t == NULL)
        return;
    else
    {
        InOrder(t->lchild);
        cout << t->val;
        InOrder(t->rchild);
    }
}


void Tree::PostOrder(TreeNode *t)           //�������
{
    if(t == NULL)
        return;
    else
    {
        PostOrder(t->lchild);
        PostOrder(t->rchild);
        cout << t->val;
    }
}
