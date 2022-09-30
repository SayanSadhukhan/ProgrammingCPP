#include <bits/stdc++.h>
using namespace std;

#define ll long long int

class Queue
{
    int *arr;
    int front, rear, capacity;
    public:
    Queue(int c)
    {
        front = rear = 0;
        arr = new int;
        capacity = c;
    }

    ~Queue(){ delete[] arr;}

    void push(int x);
    int pop();
    void display();
    int SIZE();

};

/*  Definition of all the queue functions  */
void Queue::push(int x){
    if (rear == capacity)
    {
        cout << "Overflow" << endl;
        return;
    }
    arr[rear++] = x;
    return;
}

int Queue:: pop(){
    if (front == rear)
    {
        cout << "underflow" << endl;
        return 0;
    }
    int tmp = arr[front];
    for (int i = 0; i < rear; i++)
        arr[i] = arr[i + 1];
    capacity--;
    rear--;
    return tmp;
}

void Queue:: display(){
    if (rear == front)
    {
        cout << "Underflow" << endl;
        return;
    }
    for (int i = front; i < rear; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int Queue:: SIZE(){
    return rear;
}

void file_i_o()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}

int main(int argc, char const *argv[])
{
    clock_t begin = clock();
    file_i_o();
    // Write your code here....
    Queue q(5);
    q.push(10);
    q.push(20);
    q.push(90);
    q.push(80);
    q.push(100);

    cout<<q.pop()<<endl;
    cout<<q.pop()<<endl; 
    cout<<q.SIZE()<<endl;
    q.display();
#ifndef ONLINE_JUDGE
    clock_t end = clock();
    cout << "\n\n Executed In: " << double(end - begin) / CLOCKS_PER_SEC * 1000 << " ms";
#endif
    return 0;
}