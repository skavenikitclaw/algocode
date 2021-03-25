//题目主要来源于leetcode

/*最后一块石头的重量
有一堆石头，每块石头的重量都是正整数。
每一回合，从中选出两块 最重的 石头，然后将它们一起粉碎。假设石头的重量分别为x和y，且x <= y。那么粉碎的可能结果如下：
如果x == y，那么两块石头都会被完全粉碎；
如果x != y，那么重量为x的石头将会完全粉碎，而重量为y的石头新重量为y-x。
最后，最多只会剩下一块石头。返回此石头的重量。如果没有石头剩下，就返回 0。  */


class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> res;
        for(const auto& c:stones)
            res.push(c);

        while(res.size() > 1)
        {
            int q = res.top();
            res.pop();
            int p = res.top();
            res.pop();
            if(q - p == 0)
                continue;
            else
                res.push(q - p);
        }
        if(res.size() == 1)
            return res.top();
        else
            return 0;
    }
};



/*前 K 个高频元素
给定一个非空的整数数组，返回其中出现频率前k高的元素  */



class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int, int> cr;
        for (const auto& num: nums)
            cr[num]++;
        priority_queue<pair<int, int>, vector<pair<int, int>>, less<>> pq;
        for (auto i(cr.begin()); i != cr.end(); i++)
        {
            pq.push(make_pair(i->second, i->first));
        }
        vector<int> res;
        for (int i = 0; i < k; i++)
        {
            auto item = pq.top();
            pq.pop();
            res.push_back(item.second);
        }
        return res;
    }
};
