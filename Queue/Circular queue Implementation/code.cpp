class MyCircularQueue
{
    int *arr;
    int front, rear, size;

public:
    MyCircularQueue(int k)
    {
        front = rear = -1;
        arr = new int[k];
        size = k;
    }

    bool enQueue(int value)
    {
        /*  When Queue is full  */
        if ((front == 0 and rear == size - 1) or (rear == (front - 1)))
        {
            return false;
        }
        /*  Queue is empty  */
        else if (front == -1)
        {
            front = rear = 0;
        }
        else if (rear == size - 1 && front != 0)
        {
            rear = 0; // To maintain the cyclic nature of the queue
        }
        else
        {
            rear++;
        }
        arr[rear] = value;
        // cout<<rear<<" "<<front<<" "<<size<<endl;
        return true;
    }

    bool deQueue()
    {
        if (front == -1)
            return false;
        arr[front] = -1;

        if (front == rear)
        {
            front = rear = -1;
        }
        else if (front == size - 1)
        { // To maintain the cyclic nature of the queue
            front = 0;
        }
        else
            front++;

        return true;
    }

    int Front()
    {
        if (front == -1)
            return -1;
        return arr[front];
    }

    int Rear()
    {
        if (front == -1)
            return -1;
        return arr[rear];
    }

    bool isEmpty()
    {
        return (front == -1);
    }

    bool isFull()
    {
        return ((front == 0 and rear == size - 1) or (rear == front - 1));
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */