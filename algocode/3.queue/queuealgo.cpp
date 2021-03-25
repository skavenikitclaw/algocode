//��Ŀ��Ҫ��Դ��leetcode

/*�������ڵ����ֵ
����һ������ nums �ͻ������ڵĴ�С k�����ҳ����л�������������ֵ�� */


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



/*�ҳ����о�������������
����һ����������nums��һ��������k�����س���Ϊk����߾�������nums�����С�

������������Ǵ�������ɾ��һЩԪ�أ����ܲ�ɾ��Ԫ�أ��õ������С�

��������a��������b��һ������ͬ��λ���ϣ����a�е�����С��b�ж�Ӧ�����֣���ô���ǳ�������a��������b����ͬ�����£����߾�������
���磬[1,3,4]��[1,3,5]���߾��������ڵ�һ������ͬ��λ�ã�Ҳ�������һ��λ���ϣ�4С��5 ��  */


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


//����Ҳ����ջ���


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
