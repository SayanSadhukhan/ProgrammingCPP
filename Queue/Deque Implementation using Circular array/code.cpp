class MyCircularDeque
{
    int *arr;
    int front, rear, size;

public:
    MyCircularDeque(int k)
    {
        size = k;
        front = rear = -1;
        arr = new int[k];
    }

    bool insertFront(int value)
    {
        cout << "Inserting : " << value << " " << front << " " << rear << endl;
        /*  If Deque is full        */
        if ((front == 0 and rear == size - 1) || (rear == front - 1))
            return false;
        /*  If Deque is empty       */
        if (front == -1)
            front = rear = 0;
        /*  Circular nature mainatain       */
        else if (front == 0)
            front = size - 1;
        /*  Normal flow     */
        else
            front--;

        arr[front] = value;

        return true;
    }

    bool insertLast(int value)
    {
        /*  If Deque is full        */
        if ((front == 0 and rear == size - 1) || (rear == front - 1))
            return false;
        /*  If Deque is empty        */
        if (front == -1)
        {
            front = rear = 0;
        }
        /*      Maintain the circular nature of the queue     */
        else if (front != 0 and rear == size - 1)
            rear = 0;
        /*      Normal flow     */
        else
            rear++;

        arr[rear] = value;
        return true;
    }

    bool deleteFront()
    {
        /*  If deque is empty     */
        if (front == -1)
            return false;
        arr[front] = -1;
        /*  If deque has single element present     */
        if (front == rear)
            front = -1;
        /*  To maintain circular nature     */
        else if (front == size - 1)
            front = 0;
        /*  Normal flow     */
        else
            front++;
        return true;
    }

    bool deleteLast()
    {
        /*  If Deque is empty   */
        if (front == -1)
            return false;
        arr[rear] = -1;
        /*  If single element exists in deque*/
        if (front == rear)
            front = rear = -1;
        /*  Maintaining circular nature of the array    */
        else if (rear == 0)
            rear = size - 1;
        /*  Noramal flow    */
        else
            rear--;
        return true;
    }

    int getFront()
    {
        /*  Checking if deque is empty  */
        if (front == -1)
            return -1;
        return arr[front];
    }

    int getRear()
    {
        /*  Checking if deque is empty  */
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
        /*  Checking if Deque is full   */
        return ((front == 0 and rear == size - 1) || (rear == front - 1));
    }
};

/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque* obj = new MyCircularDeque(k);
 * bool param_1 = obj->insertFront(value);
 * bool param_2 = obj->insertLast(value);
 * bool param_3 = obj->deleteFront();
 * bool param_4 = obj->deleteLast();
 * int param_5 = obj->getFront();
 * int param_6 = obj->getRear();
 * bool param_7 = obj->isEmpty();
 * bool param_8 = obj->isFull();
 */