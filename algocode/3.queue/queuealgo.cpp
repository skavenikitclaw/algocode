//题目主要来源于leetcode

/*滑动窗口的最大值
给定一个数组 nums 和滑动窗口的大小 k，请找出所有滑动窗口里的最大值。 */


class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> res;
        if(nums.empty())
            return res;
        deque<int> deQ;

        for(int i=0; i<k; i++){
            while(!deQ.empty() && deQ.back()<nums[i])
                deQ.pop_back();
            deQ.push_back(nums[i]);
        }
        res.push_back(deQ.front());

        for(int i=k; i<nums.size(); i++){
            if(deQ.front() == nums[i-k])
                deQ.pop_front();
            while(!deQ.empty() && deQ.back() < nums[i])
                deQ.pop_back();
            deQ.push_back(nums[i]);
            res.push_back(deQ.front());
        }

        return res;
    }
};



/*找出最有竞争力的子序列
给你一个整数数组nums和一个正整数k，返回长度为k且最具竞争力的nums子序列。

数组的子序列是从数组中删除一些元素（可能不删除元素）得到的序列。

在子序列a和子序列b第一个不相同的位置上，如果a中的数字小于b中对应的数字，那么我们称子序列a比子序列b（相同长度下）更具竞争力。
例如，[1,3,4]比[1,3,5]更具竞争力，在第一个不相同的位置，也就是最后一个位置上，4小于5 。  */


class Solution {
public:
    vector<int> mostCompetitive(vector<int>& nums, int k) {
        int n = nums.size();
        deque<int> dq;
        for (int i = 0; i < n - k + 1; ++i) {
            while (!dq.empty() && nums[dq.back()] > nums[i])
                dq.pop_back();
            dq.push_back(i);
        }
        vector<int> res;
        int l = 0;
        for (int i = 0; i < k; ++i) {
            while (dq.front() < l)
                dq.pop_front();
            int idx = dq.front();
            int num = nums[idx];
            dq.pop_front();
            l = idx + 1;
            res.emplace_back(num);
            if (i < k - 1) {
                while (!dq.empty() && nums[dq.back()] > nums[n - k + 1 + i])
                    dq.pop_back();
                dq.push_back(n - k + 1 + i);
            }
        }
        return res;
    }
};


//该题也可用栈解答


class Solution {
public:
    vector<int> mostCompetitive(vector<int>& nums, int k) {
        vector<int> res;
        int n = nums.size(), count = n - k;
        for (int i = 0; i < nums.size(); i++) {
            while (res.size() > 0 && nums[i] < res.back() && count > 0) {
                res.pop_back();
                count--;
            }
            res.push_back(nums[i]);
        }
        while (res.size() > k)
            res.pop_back();
        return res;
    }
};
