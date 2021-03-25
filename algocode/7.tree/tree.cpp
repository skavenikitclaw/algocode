//二叉树
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


TreeNode *Tree::Create(TreeNode *t)         //创建二叉树
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


void Tree::Release(TreeNode *t)           //释放二叉树
{
    if(t != NULL)
    {
        Release(t->lchild);
        Release(t->rchild);
        delete t;
    }
}



void Tree::PreOrder(TreeNode *t)            //前序遍历
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



void Tree::InOrder(TreeNode *t)             //中序遍历
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


void Tree::PostOrder(TreeNode *t)           //后序遍历
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
