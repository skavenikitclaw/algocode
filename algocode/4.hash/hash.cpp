class HashMap {
private:
    static const int base = 499;
    vector<list<pair<int,int>>>data;

    static int hash(int key)
    {
        return key%base;
    }
public:
    MyHashMap():data(base) {        //初始化

    }


    void put(int key, int value) {      //向 HashMap插入一个键值对(key, value)。如果key已经存在于映射中，则更新其对应的值value
        int pos = hash(key);

        for(auto x = data[pos].begin();x != data[pos].end();x++)
            if((*x).first == key)
            {
                (*x).second = value;
                return;
            }
        data[pos].push_back(make_pair(key,value));
    }


    int get(int key) {          //返回特定的key所映射的value；如果映射中不包含key的映射，返回-1
        int pos = hash(key);

        for(auto x = data[pos].begin();x != data[pos].end();x++)
            if((*x).first == key)
                return (*x).second;

        return -1;
    }


    void remove(int key) {          //如果映射中存在key的映射，则移除key和它所对应的value
        int pos = hash(key);

        for(auto x = data[pos].begin();x != data[pos].end();x++)
            if((*x).first == key)
            {
                data[pos].erase(x);
                return;
            }

    }
};
