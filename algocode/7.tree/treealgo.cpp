//��Ŀ��Ҫ��Դ��leetcode

/*��֤��������ǰ�����л�

���л���������һ�ַ�����ʹ��ǰ�����������������һ���ǿսڵ�ʱ�����ǿ��Լ�¼������ڵ��ֵ���������һ���սڵ㣬���ǿ���ʹ��һ�����ֵ��¼������ #��
     _9_
    /   \
   3     2
  / \   / \
 4   1  #  6
/ \ / \   / \
# # # #   # #
���磬����Ķ��������Ա����л�Ϊ�ַ��� "9,3,4,#,#,1,#,#,2,#,6,#,#"������#����һ���սڵ㡣
����һ���Զ��ŷָ������У���֤���Ƿ�����ȷ�Ķ�������ǰ�����л�����дһ���ڲ��ع����������µĿ����㷨��
ÿ���Զ��ŷָ����ַ���Ϊһ��������Ϊһ����ʾ null ָ���'#'��
�������Ϊ�����ʽ������Ч�ģ���������Զ����������������Ķ��ţ�����"1,,3" ��  */


class Solution {
public:
    bool isValidSerialization(string preorder) {
        int len= preorder.length();
        int cout=1;
        int undou=0;
        int dou=0;

        if(!isdigit(preorder[0]))
            if(len==1)
                return true;
            else
                return false;

        for(const char& c:preorder)
        {
            if(cout==0)
                return false;
            if(isdigit(c))
            {
                cout++;
                undou++;
            }
            else if(c=='#')
            {
                cout--;
                undou++;
            }
            else if(c==',')
                dou++;
        }
        int x = undou - (dou + 1);
        cout -= x;
        if(cout==0)
            return true;
        else
            return false;
    }
};



/*��������
����һ�������ظ�Ԫ�ص���������nums��һ���Դ�����ֱ�ӵݹ鹹�������������������£�
�������ĸ�������nums�е����Ԫ�ء�
��������ͨ�����������ֵ��߲��ֵݹ鹹���������������
��������ͨ�����������ֵ�ұ߲��ֵݹ鹹���������������
�����и�������nums����������������  */


class Solution {
public:
    int getMaxIndex(const vector<int>& nums, int left, int right)
    {
        int index = left;
        for (int i = left; i < right; i++)
        {
            if (nums[i] > nums[index])
                index = i;
        }
        return index;
    }

    TreeNode* divid(vector<int>& nums, int left, int right)
    {
        if (left >= right)
            return nullptr;
        int root_index = getMaxIndex(nums, left, right);
        TreeNode* root = new TreeNode(nums[root_index]);
        root->left = divid(nums, left, root_index);
        root->right = divid(nums, root_index + 1, right);
        return root;
    }

    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        return divid(nums, 0, nums.size());
    }
};
