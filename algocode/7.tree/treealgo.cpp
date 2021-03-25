//题目主要来源于leetcode

/*验证二叉树的前序序列化

序列化二叉树的一种方法是使用前序遍历。当我们遇到一个非空节点时，我们可以记录下这个节点的值。如果它是一个空节点，我们可以使用一个标记值记录，例如 #。
     _9_
    /   \
   3     2
  / \   / \
 4   1  #  6
/ \ / \   / \
# # # #   # #
例如，上面的二叉树可以被序列化为字符串 "9,3,4,#,#,1,#,#,2,#,6,#,#"，其中#代表一个空节点。
给定一串以逗号分隔的序列，验证它是否是正确的二叉树的前序序列化。编写一个在不重构树的条件下的可行算法。
每个以逗号分隔的字符或为一个整数或为一个表示 null 指针的'#'。
你可以认为输入格式总是有效的，例如它永远不会包含两个连续的逗号，比如"1,,3" 。  */


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



/*最大二叉树
给定一个不含重复元素的整数数组nums。一个以此数组直接递归构建的最大二叉树定义如下：
二叉树的根是数组nums中的最大元素。
左子树是通过数组中最大值左边部分递归构造出的最大二叉树。
右子树是通过数组中最大值右边部分递归构造出的最大二叉树。
返回有给定数组nums构建的最大二叉树。  */


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
