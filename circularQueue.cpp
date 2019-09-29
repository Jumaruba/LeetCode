
class MyCircularQueue {
private:
    int tail;
    int head;
    vector <int> v;
public:
    /** Initialize your data structure here. Set the size of the queue to be k. */
    MyCircularQueue(int k) {
        for (int i = 0; i < k; i++)
            v.push_back(0);
        tail = -1;
        head = -1;
    }

    /** Insert an element into the circular queue. Return true if the operation is successful. */
    bool enQueue(int value) {
        if (isFull())
            return false;
        if (isEmpty()){
            tail = 0;
            head = 0;
            v[tail] = value;
        }
        else{
            tail++;
            tail%= v.size();
            v[tail] = value;
        }
        return true;

    }

    /** Delete an element from the circular queue. Return true if the operation is successful. */
    bool deQueue() {
        if(isEmpty())
            return false;
        head ++;
        if (head - tail == 1){
            head = -1;
            tail = -1;
        }
        else
            head%= v.size();
        return true;

    }

    /** Get the front item from the queue. */
    int Front() {
        if (isEmpty())
            return -1;
        return v[head];
    }

    /** Get the last item from the queue. */
    int Rear() {
        if (isEmpty())
            return -1;
        return v[tail];
    }

    /** Checks whether the circular queue is empty or not. */
    bool isEmpty() {
        if (head == -1 && tail == -1)
            return true;
        return false;
    }

    /** Checks whether the circular queue is full or not. */
    bool isFull() {
        if ((head == 0 && tail == v.size()-1) || head-tail == 1)
            return true;
        return false;
    }
};
