//���������
struct BSTreeNode
{
    int val;
    BSTreeNode *lchild,*rchild;

    BSTreeNode(int value)
    {
        val = value;
        lchild = NULL;
        rchild = NULL;
    }
};

class BSTree
{
public:
    BSTree();
    ~BSTree();

    void FreeMemory(BSTreeNode* t);
    void Insert(int value);
    void Insert(BSTreeNode* t,int value);
    BSTreeNode* Search(int value);
    BSTreeNode* Search(BSTreeNode* t,int value);
    void Delete(int value);
    void PreOrder(BSTreeNode *t);
    void InOrder(BSTreeNode *t);
    void PostOrder(BSTreeNode *t);

private:
    BSTreeNode *root;
};


BSTree::BSTree()
{
    root = NULL;
}

BSTree::~BSTree()
{
    if (root == NULL)
        return;

    FreeMemory(root);
}

void BSTree::FreeMemory(BSTreeNode* t)      //�ͷ��ڴ�
{
    if (t == NULL)
        return;

    if (t->lchild != NULL)
        FreeMemory(t->lchild);

    if (t->rchild != NULL)
        FreeMemory(t->rchild);

    delete t;
    t = NULL;
}

void BSTree::Insert(int value)          //����
{
    if (root == NULL)
        root = new STreeNode(value);
    else
        Insert(root, value);
}

void BSTree::Insert(BSTreeNode* t,int value)
{
    if (t->val > value)
    {
        if (t->lchild == NULL)
            t->lchild = new STreeNode(value);
        else
            Insert(t->lchild,value);
    }
    else
    {
        if (t->rchild == NULL)
            t->rchild = new STreeNode(value);
        else
            Insert(t->rchild,value);
    }
}

BSTreeNode* BSTree::Search(int value)       //Ѱ��
{
    return Search(root,value);
}

BSTreeNode* BSTree::Search(BSTreeNode* t,int value)
{
    if (t == NULL)
        return NULL;

    if (t->val == value)
        return t;
    else
    {
        if (t->val > value)
            return Search(t->lchild,value);
        else
            return Search(t->rchild,value);
    }
}

void BSTree::Delete(int value)              //ɾ��
{
    BSTreeNode* bsparent = root;
    BSTreeNode* bsfind = root;
    //  �ҵ�valueԪ�ض�Ӧ�Ľڵ�
    while (bsfind != NULL)
    {
        if (bsfind->val == value)
            break;

        bsparent = bsfind;
        if (bsfind->val > value)
            bsfind = bsfind->lchild;
        else
            bsfind = bsfind->rchild;
    }

    if (bsfind == NULL)
        return;



    if (bsfind->lchild == NULL || bsfind->rchild == NULL)
    {
        BSTreeNode* temp = NULL;
        if (bsfind->lchild != NULL)
            temp = bsfind->lchild;
        else if (bsfind->rchild != NULL)
            temp = bsfind->rchild;

        if (bsparent->lchild == bsfind)
            bsparent->lchild = temp;
        else
            bsparent->rchild = temp;

        delete bsfind;
        bsfind = NULL;
    }
    else
    {
        BSTreeNode* temp = bsfind->lchild;
        BSTreeNode* tempparent = bsfind;

        while (temp->rchild != NULL)
        {
            tempparent = temp;
            temp = temp->rchild;
        }

        bsfind->val = temp->val;
        tempparent->rchild = NULL;
        delete temp;
        temp = NULL;
    }
}

void BSTree::PreOrder(BSTreeNode *t)            //ǰ�����
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



void BSTree::InOrder(BSTreeNode *t)             //�������
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


void BSTree::PostOrder(BSTreeNode *t)           //�������
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
