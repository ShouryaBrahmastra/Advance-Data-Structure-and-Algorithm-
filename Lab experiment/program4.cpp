/**
 * 
 * Implement the code for enqueue and dequeue operations.
 * 
 * Author: Shourya Gupta 
 * Copyright: ShouryaBrahmastra
 * 
 * **/
#include <iostream>
using namespace std;

#define MAX 1000

class Queue
{
    int front, rear;
    int arr[MAX];

public:
    Queue()
    {
        front = -1;
        rear = -1;
    }

    bool isFull()
    {
        return (rear == MAX - 1);
    }

    bool isEmpty()
    {
        return (front == -1 || front > rear);
    }

    void enqueue(int x)
    {
        if (isFull())
        {
            cout << "Queue is full\n";
            return;
        }
        if (isEmpty())
        {
            front = 0;
        }
        arr[++rear] = x;
        cout << x << " enqueued to queue\n";
    }

    int dequeue()
    {
        if (isEmpty())
        {
            cout << "Queue is empty\n";
            return -1;
        }
        int x = arr[front++];
        if (isEmpty())
        {
            front = -1;
            rear = -1;
        }
        return x;
    }

    void display()
    {
        if (isEmpty())
        {
            cout << "Queue is empty\n";
            return;
        }
        for (int i = front; i <= rear; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main()
{
    Queue q;
    int choice, value;
    do
    {
        cout << "\n1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            cout << "Enter value to enqueue: ";
            cin >> value;
            q.enqueue(value);
            break;
        case 2:
            value = q.dequeue();
            if (value != -1)
            {
                cout << "Dequeued element: " << value << endl;
            }
            break;
        case 3:
            q.display();
            break;
        case 4:
            cout << "Exiting...\n";
            break;
        default:
            cout << "Invalid choice, please try again.\n";
        }
    } while (choice != 4);
    return 0;
}
