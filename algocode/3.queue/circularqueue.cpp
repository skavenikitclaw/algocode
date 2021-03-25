//ѭ������
class CircularQueue {
private:
    vector<int> que;
    int head;
    int tail;
    int len;

public:
    MyCircularQueue(int k) {        //�����������ö��г���Ϊk
        len = k;
        head = tail = -1;
        que.assign(len,0);
    }

    bool enQueue(int value) {       //��ѭ�����в���һ��Ԫ�ء�����ɹ������򷵻���
        if(isFull())
            return false;
        if(isEmpty())
            head = tail = 0;
        else
            tail = (tail+1) % len;
        que[tail] = value;
        return true;
    }

    bool deQueue() {        //��ѭ��������ɾ��һ��Ԫ�ء�����ɹ�ɾ���򷵻���
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

    int Front() {       //�Ӷ��׻�ȡԪ�ء��������Ϊ�գ����� -1
        if(isEmpty())
            return -1;
        return que[head];
    }

    int Rear() {        //��ȡ��βԪ�ء��������Ϊ�գ����� -1
        if(isEmpty())
            return -1;
        return que[tail];
    }

    bool isEmpty() {        //���ѭ�������Ƿ�Ϊ��
        return head == -1;
    }

    bool isFull() {         //���ѭ�������Ƿ�����
        return (tail + 1) % len == head;
    }
};
