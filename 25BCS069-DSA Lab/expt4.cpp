#include <iostream>
using namespace std;

// Definition of a Linked List Node
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

    // taking input here

    void createListFromUser() {
        int count, val;
        cout << "\n enter the no. of elements u want to enter? ";
        cin >> count;

        if (count <= 0) {
            cout << "Invalid \n";
            return;
        }

        cout << "Enter " << count << ":\n";
        for (int i = 0; i < count; i++) {
            cout << "Element " << (i + 1) << ": ";
            cin >> val;
            insertAtEnd(val); 
        }
        cout << "List created \n";
    }


    // 1. Insert at the Beginning
    void insertAtBeginning(int value) {
        Node* newNode = new Node(value);
        newNode->next = head;
        head = newNode;
        cout << "Successfully inserted " << value << " at the beginning.\n";
    }

    // 2. Insert at a Specific Position 
    void insertAtPosition(int value, int position) {
        if (position < 0) {
            cout << "Invalid position!\n";
            return;
        }
        if (position == 0) {
            insertAtBeginning(value);
            return;
        }

        Node* temp = head;
        for (int i = 0; i < position - 1 && temp != nullptr; i++) {
            temp = temp->next;
        }

        if (temp == nullptr) {
            cout << "Position out of bounds\n";
            return;
        }

        Node* newNode = new Node(value);
        newNode->next = temp->next;
        temp->next = newNode;
        cout << "Successfully inserted " << value << " at position " << position << ".\n";
    }

    // 3. Insert at the End
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


    // 1. Delete from the Beginning
    void deleteFromBeginning() {
        if (head == nullptr) {
            cout << "List is empty! Nothing to delete.\n";
            return;
        }

        Node* temp = head;
        head = head->next;
        cout << "Deleted " << temp->data << " from the beginning.\n";
        delete temp;
    }

    // 2. Delete from a Specific Position 
    void deleteFromPosition(int position) {
        if (head == nullptr) {
            cout << "List is empty! Nothing to delete.\n";
            return;
        }
        if (position < 0) {
            cout << "Invalid position!\n";
            return;
        }
        if (position == 0) {
            deleteFromBeginning();
            return;
        }

        Node* temp = head;
        for (int i = 0; i < position - 1 && temp != nullptr; i++) {
            temp = temp->next;
        }

        if (temp == nullptr || temp->next == nullptr) {
            cout << "Position out of bounds\n";
            return;
        }

        Node* nodeToDelete = temp->next;
        temp->next = nodeToDelete->next;
        cout << "Deleted " << nodeToDelete->data << " from position " << position << ".\n";
        delete nodeToDelete;
    }

    // 3. Delete from the End
    void deleteFromEnd() {
        if (head == nullptr) {
            cout << "List is empty Nothing to delete.\n";
            return;
        }#include <iostream>
using namespace std;

// Definition of a Linked List Node
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

    // taking input here

    void createListFromUser() {
        int count, val;
        cout << "\n enter the no. of elements u want to enter? ";
        cin >> count;

        if (count <= 0) {
            cout << "Invalid \n";
            return;
        }

        cout << "Enter " << count << ":\n";
        for (int i = 0; i < count; i++) {
            cout << "Element " << (i + 1) << ": ";
            cin >> val;
            insertAtEnd(val); 
        }
        cout << "List created \n";
    }


    // 1. Insert at the Beginning
    void insertAtBeginning(int value) {
        Node* newNode = new Node(value);
        newNode->next = head;
        head = newNode;
        cout << "Successfully inserted " << value << " at the beginning.\n";
    }

    // 2. Insert at a Specific Position 
    void insertAtPosition(int value, int position) {
        if (position < 0) {
            cout << "Invalid position!\n";
            return;
        }
        if (position == 0) {
            insertAtBeginning(value);
            return;
        }

        Node* temp = head;
        for (int i = 0; i < position - 1 && temp != nullptr; i++) {
            temp = temp->next;
        }

        if (temp == nullptr) {
            cout << "Position out of bounds\n";
            return;
        }

        Node* newNode = new Node(value);
        newNode->next = temp->next;
        temp->next = newNode;
        cout << "Successfully inserted " << value << " at position " << position << ".\n";
    }

    // 3. Insert at the End
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


    // 1. Delete from the Beginning
    void deleteFromBeginning() {
        if (head == nullptr) {
            cout << "List is empty! Nothing to delete.\n";
            return;
        }

        Node* temp = head;
        head = head->next;
        cout << "Deleted " << temp->data << " from the beginning.\n";
        delete temp;
    }

    // 2. Delete from a Specific Position 
    void deleteFromPosition(int position) {
        if (head == nullptr) {
            cout << "List is empty! Nothing to delete.\n";
            return;
        }
        if (position < 0) {
            cout << "Invalid position!\n";
            return;
        }
        if (position == 0) {
            deleteFromBeginning();
            return;
        }

        Node* temp = head;
        for (int i = 0; i < position - 1 && temp != nullptr; i++) {
            temp = temp->next;
        }

        if (temp == nullptr || temp->next == nullptr) {
            cout << "Position out of bounds\n";
            return;
        }

        Node* nodeToDelete = temp->next;
        temp->next = nodeToDelete->next;
        cout << "Deleted " << nodeToDelete->data << " from position " << position << ".\n";
        delete nodeToDelete;
    }

    // 3. Delete from the End
    void deleteFromEnd() {
        if (head == nullptr) {
            cout << "List is empty Nothing to delete.\n";
            return;
        }

        if (head->next == nullptr) {
            cout << "Deleted " << head->data << " from the end.\n";
            delete head;
            head = nullptr;
            return;
        }

        Node* temp = head;
        while (temp->next->next != nullptr) {
            temp = temp->next;
        }

        Node* nodeToDelete = temp->next;
        temp->next = nullptr;
        cout << "Deleted " << nodeToDelete->data << " from the end.\n";
        delete nodeToDelete;
    }

    // display list
    void display() {
        if (head == nullptr) {
            
            cout << "Current List: [ Empty ]\n";
            
            return;
        }

        
        cout << "Current List: ";
        Node* temp = head;
        while (temp != nullptr) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL\n";
        
    }


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
    int choice, val, pos;

    do {
        cout << "      LINKED LIST MENU OPERATIONS      \n";
        cout << "1. Enter / Create an Entire List\n";
        cout << "2. Insert at Beginning\n";
        cout << "3. Insert at Middle / Specific Position\n";
        cout << "4. Insert at End\n";
        cout << "5. Delete from Beginning\n";
        cout << "6. Delete from Middle / Specific Position\n";
        cout << "7. Delete from End\n";
        cout << "8. Display List\n";
        cout << "9. Exit\n";
        cout << "Enter your choice (1-9): ";
        cin >> choice;

        switch (choice) {
            case 1:
                list.createListFromUser();
                list.display();
                break;

            case 2:
                cout << "Enter value to insert: ";
                cin >> val;
                list.insertAtBeginning(val);
                list.display();
                break;

            case 3:
                cout << "Enter value to insert: ";
                cin >> val;
                cout << "Enter position (0-indexed): ";
                cin >> pos;
                list.insertAtPosition(val, pos);
                list.display();
                break;

            case 4:
                cout << "Enter value to insert: ";
                cin >> val;
                list.insertAtEnd(val);
                list.display();
                break;

            case 5:
                list.deleteFromBeginning();
                list.display();
                break;

            case 6:
                cout << "Enter position to delete (0-indexed): ";
                cin >> pos;
                list.deleteFromPosition(pos);
                list.display();
                break;

            case 7:
                list.deleteFromEnd();
                list.display();
                break;

            case 8:
                list.display();
                break;

            case 9:
                cout << "Exiting program. Memory cleaned up.\n";
                break;

            default:
                cout << "wrong choice \n";
        }
    } while (choice != 9);

    return 0;
}

        if (head->next == nullptr) {
            cout << "Deleted " << head->data << " from the end.\n";
            delete head;
            head = nullptr;
            return;
        }

        Node* temp = head;
        while (temp->next->next != nullptr) {
            temp = temp->next;
        }

        Node* nodeToDelete = temp->next;
        temp->next = nullptr;
        cout << "Deleted " << nodeToDelete->data << " from the end.\n";
        delete nodeToDelete;
    }

    // display list
    void display() {
        if (head == nullptr) {
            
            cout << "Current List: [ Empty ]\n";
            
            return;
        }

        
        cout << "Current List: ";
        Node* temp = head;
        while (temp != nullptr) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL\n";
        
    }


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
    int choice, val, pos;

    do {
        cout << "      LINKED LIST MENU OPERATIONS      \n";
        cout << "1. Enter / Create an Entire List\n";
        cout << "2. Insert at Beginning\n";
        cout << "3. Insert at Middle / Specific Position\n";
        cout << "4. Insert at End\n";
        cout << "5. Delete from Beginning\n";
        cout << "6. Delete from Middle / Specific Position\n";
        cout << "7. Delete from End\n";
        cout << "8. Display List\n";
        cout << "9. Exit\n";
        cout << "Enter your choice (1-9): ";
        cin >> choice;

        switch (choice) {
            case 1:
                list.createListFromUser();
                list.display();
                break;

            case 2:
                cout << "Enter value to insert: ";
                cin >> val;
                list.insertAtBeginning(val);
                list.display();
                break;

            case 3:
                cout << "Enter value to insert: ";
                cin >> val;
                cout << "Enter position (0-indexed): ";
                cin >> pos;
                list.insertAtPosition(val, pos);
                list.display();
                break;

            case 4:
                cout << "Enter value to insert: ";
                cin >> val;
                list.insertAtEnd(val);
                list.display();
                break;

            case 5:
                list.deleteFromBeginning();
                list.display();
                break;

            case 6:
                cout << "Enter position to delete (0-indexed): ";
                cin >> pos;
                list.deleteFromPosition(pos);
                list.display();
                break;

            case 7:
                list.deleteFromEnd();
                list.display();
                break;

            case 8:
                list.display();
                break;

            case 9:
                cout << "Exiting program. Memory cleaned up.\n";
                break;

            default:
                cout << "wrong choice \n";
        }
    } while (choice != 9);

    return 0;
}