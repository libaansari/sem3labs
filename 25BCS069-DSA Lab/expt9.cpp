#include <iostream>
using namespace std;

class MaxHeap {
    int heap[100];
    int size;

public:
    MaxHeap() {
        size = 0;
    }

    // Insert an element
    void insert(int value) {
        int i = size;
        heap[size++] = value;

        while (i > 0 && heap[(i - 1) / 2] < heap[i]) {
            swap(heap[i], heap[(i - 1) / 2]);
            i = (i - 1) / 2;
        }

        cout << "Element inserted successfully.\n";
    }

    // Delete the maximum element
    void deleteMax() {
        if (size == 0) {
            cout << "Priority Queue is empty.\n";
            return;
        }

        cout << "Deleted element: " << heap[0] << endl;
        heap[0] = heap[--size];

        int i = 0;

        while (true) {
            int largest = i;
            int left = 2 * i + 1;
            int right = 2 * i + 2;

            if (left < size && heap[left] > heap[largest])
                largest = left;

            if (right < size && heap[right] > heap[largest])
                largest = right;

            if (largest == i)
                break;

            swap(heap[i], heap[largest]);
            i = largest;
        }
    }

    // Display the heap
    void display() {
        if (size == 0) {
            cout << "Priority Queue is empty.\n";
            return;
        }

        cout << "Max Priority Queue: ";
        for (int i = 0; i < size; i++)
            cout << heap[i] << " ";

        cout << endl;
    }
};

int main() {
    MaxHeap pq;
    int choice, value;

    do {
        cout << "\n1. Insert";
        cout << "\n2. Delete Maximum";
        cout << "\n3. Display";
        cout << "\n4. Exit";
        cout << "\nEnter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value: ";
                cin >> value;
                pq.insert(value);
                break;

            case 2:
                pq.deleteMax();
                break;

            case 3:
                pq.display();
                break;

            case 4:
                cout << "Exiting program.\n";
                break;

            default:
                cout << "Invalid choice.\n";
        }
    } while (choice != 4);

    return 0;
}