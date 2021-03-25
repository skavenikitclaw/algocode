class HashMap {
private:
    static const int base = 499;
    vector<list<pair<int,int>>>data;

    static int hash(int key)
    {
        return key%base;
    }
public:
    MyHashMap():data(base) {        //��ʼ��

    }


    void put(int key, int value) {      //�� HashMap����һ����ֵ��(key, value)�����key�Ѿ�������ӳ���У���������Ӧ��ֵvalue
        int pos = hash(key);

        for(auto x = data[pos].begin();x != data[pos].end();x++)
            if((*x).first == key)
            {
                (*x).second = value;
                return;
            }
        data[pos].push_back(make_pair(key,value));
    }


    int get(int key) {          //�����ض���key��ӳ���value�����ӳ���в�����key��ӳ�䣬����-1
        int pos = hash(key);

        for(auto x = data[pos].begin();x != data[pos].end();x++)
            if((*x).first == key)
                return (*x).second;

        return -1;
    }


    void remove(int key) {          //���ӳ���д���key��ӳ�䣬���Ƴ�key��������Ӧ��value
        int pos = hash(key);

        for(auto x = data[pos].begin();x != data[pos].end();x++)
            if((*x).first == key)
            {
                data[pos].erase(x);
                return;
            }

    }
};
