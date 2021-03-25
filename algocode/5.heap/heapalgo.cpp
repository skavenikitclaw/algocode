//��Ŀ��Ҫ��Դ��leetcode

/*���һ��ʯͷ������
��һ��ʯͷ��ÿ��ʯͷ������������������
ÿһ�غϣ�����ѡ������ ���ص� ʯͷ��Ȼ������һ����顣����ʯͷ�������ֱ�Ϊx��y����x <= y����ô����Ŀ��ܽ�����£�
���x == y����ô����ʯͷ���ᱻ��ȫ���飻
���x != y����ô����Ϊx��ʯͷ������ȫ���飬������Ϊy��ʯͷ������Ϊy-x��
������ֻ��ʣ��һ��ʯͷ�����ش�ʯͷ�����������û��ʯͷʣ�£��ͷ��� 0��  */


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



/*ǰ K ����ƵԪ��
����һ���ǿյ��������飬�������г���Ƶ��ǰk�ߵ�Ԫ��  */



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
