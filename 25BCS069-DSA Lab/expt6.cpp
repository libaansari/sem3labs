//USING ARRAY
#include <iostream>
using namespace std;

#define SIZE 5

int qArr[SIZE];
int qFront = -1, qRear = -1;

void enqueue(int x) {
    if (qRear == SIZE - 1) {
        cout << "Queue Overflow!\n";
        return;
    }
    if (qFront == -1) qFront = 0;     
    qArr[++qRear] = x;
    cout << x << " inserted\n";
}

void dequeue() {
    if (qFront == -1) {
        cout << "Queue Underflow!\n";
        return;
    }
    cout << qArr[qFront] << " deleted\n";
    if (qFront == qRear)               
        qFront = qRear = -1;
    else
        qFront++;
}

void displayQueue() {
    if (qFront == -1) {
        cout << "Queue is empty\n";
        return;
    }
    cout << "Queue: ";
    for (int i = qFront; i <= qRear; i++)
        cout << qArr[i] << " ";
    cout << "\n";
}


int dArr[SIZE];
int dFront = -1, dRear = -1;

bool dequeFull() {
    return (dFront == 0 && dRear == SIZE - 1) || (dFront == dRear + 1);
}

void insertFront(int x) {
    if (dequeFull()) {
        cout << "Deque Overflow!\n";
        return;
    }
    if (dFront == -1)              dFront = dRear = 0;   
    else if (dFront == 0)          dFront = SIZE - 1;   
    else                           dFront--;
    dArr[dFront] = x;
    cout << x << " inserted at front\n";
}

void insertRear(int x) {
    if (dequeFull()) {
        cout << "Deque Overflow!\n";
        return;
    }
    if (dFront == -1)              dFront = dRear = 0;   
    else if (dRear == SIZE - 1)    dRear = 0;           
    else                           dRear++;
    dArr[dRear] = x;
    cout << x << " inserted at rear\n";
}

void deleteFront() {
    if (dFront == -1) {
        cout << "Deque Underflow!\n";
        return;
    }
    cout << dArr[dFront] << " deleted from front\n";
    if (dFront == dRear)               dFront = dRear = -1;   
    else if (dFront == SIZE - 1)       dFront = 0;
    else                               dFront++;
}

void deleteRear() {
    if (dFront == -1) {
        cout << "Deque Underflow!\n";
        return;
    }
    cout << dArr[dRear] << " deleted from rear\n";
    if (dFront == dRear)               dFront = dRear = -1;   
    else if (dRear == 0)               dRear = SIZE - 1;
    else                               dRear--;
}

void displayDeque() {
    if (dFront == -1) {
        cout << "Deque is empty\n";
        return;
    }
    cout << "Deque: ";
    int i = dFront;
    while (true) {
        cout << dArr[i] << " ";
        if (i == dRear) break;
        i = (i + 1) % SIZE;
    }
    cout << "\n";
}

int main() {
    int type, choice, x;

    cout << "1. Queue\n2. Deque\nEnter choice: ";
    cin >> type;

    if (type == 1) {
        do {
            cout << "\n1. Enqueue\n2. Dequeue\n3. Display\n0. Exit\nEnter choice: ";
            cin >> choice;
            if (choice == 1) { cout << "Enter value: "; cin >> x; enqueue(x); }
            else if (choice == 2) dequeue();
            else if (choice == 3) displayQueue();
        } while (choice != 0);
    }
    else if (type == 2) {
        do {
            cout << "\n1. Insert Front\n2. Insert Rear\n3. Delete Front\n"
                 << "4. Delete Rear\n5. Display\n0. Exit\nEnter choice: ";
            cin >> choice;
            if (choice == 1) { cout << "Enter value: "; cin >> x; insertFront(x); }
            else if (choice == 2) { cout << "Enter value: "; cin >> x; insertRear(x); }
            else if (choice == 3) deleteFront();
            else if (choice == 4) deleteRear();
            else if (choice == 5) displayDeque();
        } while (choice != 0);
    }
    return 0;
}