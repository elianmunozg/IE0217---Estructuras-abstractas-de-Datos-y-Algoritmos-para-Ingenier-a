#include <iostream>
#define SIZE 5
using namespace std;

class Queue {
private:
    int items[SIZE];
    int front, rear;

public:
    Queue() {
        front = -1;
        rear = -1;
    }

    bool isFull() {
        // Verifica si la cola está llena
        if (front == 0 && rear == SIZE - 1) {
            return true;
        }
        return false;
    }

    bool isEmpty() {
        // Verifica si la cola está vacía
        if (front == -1)
            return true;
        else
            return false;
    }

    void enqueue(int element) {
        if (isFull()) {
            cout << "Queue is full";
        } else {
            if (front == -1)
                front = 0;
            rear++;
        }
        items[rear] = element;
        cout << endl << "Inserted " << element << endl;
    }

    int dequeue() {
        int element;
        if (isEmpty()) {
            cout << "Queue is empty" << endl;
            return (-1);
        } else {
            element = items[front];
            front++;
            if (front > rear) {
                front = -1;
                rear = -1;
            }
            cout << endl << "Deleted -> " << element << endl;
            return (element);
        }
    }

    void display() {
        int i;
        if (isEmpty()) {
            cout << endl << "Empty Queue" << endl;
        } else {
            cout << endl << "Front index-> " << front << endl;
            cout << "Items -> ";
            for (i = front; i <= rear; i++)
                cout << items[i] << " ";
            cout << endl << "Rear index-> " << rear << endl;
        }
    }
};

int main() {
    // Crear una instancia de la cola
    Queue q;

    // deQueue no es posible en una cola vacía
    q.dequeue();

    // enQueue de 5 elementos
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    q.enqueue(4);
    q.enqueue(5);

    // El sexto elemento no se puede agregar porque la cola está llena
    q.enqueue(6);

    // Mostrar el estado actual de la cola
    q.display();

    // deQueue elimina el elemento ingresado primero, es decir, 1
    q.dequeue();

    // Ahora tenemos solo 4 elementos
    q.display();

    return 0;
}
