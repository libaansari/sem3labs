//delete list
#include <iostream>
using namespace std;

// Node structure representing each element of the linked list
struct Node {
    int data;
    Node* next;

    Node(int value) {
        data = value;
        next = nullptr;
    }
};

class LinkedList {
private:
    Node* head;

public:
    LinkedList() {
        head = nullptr;
    }

    // Used only to build up a starting list to delete from
    void insertAtEnd(int value) {
        Node* newNode = new Node(value);
        if (head == nullptr) {
            head = newNode;
            return;
        }
        Node* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newNode;
    }

    // Delete the node at the beginning of the list
    void deleteAtBeginning() {
        if (head == nullptr) {
            cout << "List is empty." << endl;
            return;
        }
        Node* temp = head;
        head = head->next;
        delete temp;
    }

    // Delete the node at the end of the list
    void deleteAtEnd() {
        if (head == nullptr) {
            cout << "List is empty." << endl;
            return;
        }
        if (head->next == nullptr) {
            delete head;
            head = nullptr;
            return;
        }
        Node* temp = head;
        while (temp->next->next != nullptr) {
            temp = temp->next;
        }
        delete temp->next;
        temp->next = nullptr;
    }

    // Delete the first node that contains the given value
    void deleteByValue(int value) {
        if (head == nullptr) {
            cout << "List is empty." << endl;
            return;
        }

        // If the head itself holds the value to delete
        if (head->data == value) {
            Node* temp = head;
            head = head->next;
            delete temp;
            return;
        }

        Node* current = head;
        while (current->next != nullptr && current->next->data != value) {
            current = current->next;
        }

        if (current->next == nullptr) {
            cout << value << " not found in the list." << endl;
            return;
        }

        Node* temp = current->next;
        current->next = current->next->next;
        delete temp;
    }

    // Delete the node at a given position (0-indexed)
    void deleteAtPosition(int position) {
        if (head == nullptr) {
            cout << "List is empty." << endl;
            return;
        }
        if (position == 0) {
            deleteAtBeginning();
            return;
        }
        Node* temp = head;
        for (int i = 0; i < position - 1 && temp->next != nullptr; i++) {
            temp = temp->next;
        }
        if (temp->next == nullptr) {
            cout << "Position out of range." << endl;
            return;
        }
        Node* toDelete = temp->next;
        temp->next = toDelete->next;
        delete toDelete;
    }

    // Display all elements of the list
    void display() {
        Node* temp = head;
        if (temp == nullptr) {
            cout << "List is empty." << endl;
            return;
        }
        while (temp != nullptr) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }

    // Destructor to free allocated memory
    ~LinkedList() {
        Node* temp = head;
        while (head != nullptr) {
            head = head->next;
            delete temp;
            temp = head;
        }
    }
};

int main() {
    LinkedList list;

    // Build a starting list: 5 -> 10 -> 15 -> 20 -> 30
    list.insertAtEnd(5);
    list.insertAtEnd(10);
    list.insertAtEnd(15);
    list.insertAtEnd(20);
    list.insertAtEnd(30);
    cout << "Starting list: ";
    list.display();

    list.deleteAtBeginning();
    cout << "After deleteAtBeginning(): ";
    list.display();

    list.deleteAtEnd();
    cout << "After deleteAtEnd(): ";
    list.display();

    list.deleteByValue(15);
    cout << "After deleteByValue(15): ";
    list.display();

    list.deleteAtPosition(0);
    cout << "After deleteAtPosition(0): ";
    list.display();

    return 0;
}