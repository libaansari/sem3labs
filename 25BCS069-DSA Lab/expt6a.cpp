//USING LINKED LIST

#include <iostream>
using namespace std;


struct QNode {
    int data;
    QNode *next;
};

QNode *qFront = NULL;
QNode *qRear = NULL;

void enqueue(int x) {
    QNode *n = new QNode;
    n->data = x;
    n->next = NULL;

    if (qRear == NULL)                
        qFront = qRear = n;
    else {
        qRear->next = n;             
        qRear = n;
    }
    cout << x << " inserted\n";
}

void dequeue() {
    if (qFront == NULL) {
        cout << "Queue Underflow!\n";
        return;
    }
    QNode *temp = qFront;
    cout << temp->data << " deleted\n";
    qFront = qFront->next;
    if (qFront == NULL)                
        qRear = NULL;
    delete temp;
}

void displayQueue() {
    if (qFront == NULL) {
        cout << "Queue is empty\n";
        return;
    }
    cout << "Queue: ";
    for (QNode *p = qFront; p != NULL; p = p->next)
        cout << p->data << " ";
    cout << "\n";
}


struct DNode {
    int data;
    DNode *prev;
    DNode *next;
};

DNode *dFront = NULL;
DNode *dRear = NULL;

void insertFront(int x) {
    DNode *n = new DNode;
    n->data = x;
    n->prev = NULL;
    n->next = dFront;

    if (dFront == NULL)             
        dRear = n;
    else
        dFront->prev = n;
    dFront = n;
    cout << x << " inserted at front\n";
}

void insertRear(int x) {
    DNode *n = new DNode;
    n->data = x;
    n->next = NULL;
    n->prev = dRear;

    if (dRear == NULL)                 
        dFront = n;
    else
        dRear->next = n;
    dRear = n;
    cout << x << " inserted at rear\n";
}

void deleteFront() {
    if (dFront == NULL) {
        cout << "Deque Underflow!\n";
        return;
    }
    DNode *temp = dFront;
    cout << temp->data << " deleted from front\n";
    dFront = dFront->next;
    if (dFront == NULL)              
        dRear = NULL;
    else
        dFront->prev = NULL;
    delete temp;
}

void deleteRear() {
    if (dRear == NULL) {
        cout << "Deque Underflow!\n";
        return;
    }
    DNode *temp = dRear;
    cout << temp->data << " deleted from rear\n";
    dRear = dRear->prev;
    if (dRear == NULL)                
        dFront = NULL;
    else
        dRear->next = NULL;
    delete temp;
}

void displayDeque() {
    if (dFront == NULL) {
        cout << "Deque is empty\n";
        return;
    }
    cout << "Deque: ";
    for (DNode *p = dFront; p != NULL; p = p->next)
        cout << p->data << " ";
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