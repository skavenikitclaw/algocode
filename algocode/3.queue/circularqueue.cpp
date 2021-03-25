//循环队列
class CircularQueue {
private:
    vector<int> que;
    int head;
    int tail;
    int len;

public:
    MyCircularQueue(int k) {        //构造器，设置队列长度为k
        len = k;
        head = tail = -1;
        que.assign(len,0);
    }

    bool enQueue(int value) {       //向循环队列插入一个元素。如果成功插入则返回真
        if(isFull())
            return false;
        if(isEmpty())
            head = tail = 0;
        else
            tail = (tail+1) % len;
        que[tail] = value;
        return true;
    }

    bool deQueue() {        //从循环队列中删除一个元素。如果成功删除则返回真
        if (isEmpty())
            return false;
        else
        {
            if (head == tail)
                head = tail = -1;
            else
                head = (head + 1) % len;
            return true;
        }
    }

    int Front() {       //从队首获取元素。如果队列为空，返回 -1
        if(isEmpty())
            return -1;
        return que[head];
    }

    int Rear() {        //获取队尾元素。如果队列为空，返回 -1
        if(isEmpty())
            return -1;
        return que[tail];
    }

    bool isEmpty() {        //检查循环队列是否为空
        return head == -1;
    }

    bool isFull() {         //检查循环队列是否已满
        return (tail + 1) % len == head;
    }
};
