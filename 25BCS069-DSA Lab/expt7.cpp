#include <iostream> 

#include <queue> 

using namespace std; 

 

struct Node { 

    int data; 

    Node* left; 

    Node* right; 

    Node(int val) : data(val), left(nullptr), right(nullptr) {} 

}; 

 

// Insert at the first free position, level by level (left to right) 

Node* insert(Node* root, int val) { 

    Node* newNode = new Node(val); 

    if (root == nullptr) return newNode; 

 

    queue<Node*> q; 

    q.push(root); 

 

    while (!q.empty()) { 

        Node* curr = q.front(); 

        q.pop(); 

 

        if (curr->left == nullptr) { 

            curr->left = newNode; 

            break; 

        } 

        q.push(curr->left); 

 

        if (curr->right == nullptr) { 

            curr->right = newNode; 

            break; 

        } 

        q.push(curr->right); 

    } 

    return root; 

} 

 

// Inorder traversal: Left -> Root -> Right 

void inorder(Node* root) { 

    if (root == nullptr) return; 

    inorder(root->left); 

    cout << root->data << " "; 

    inorder(root->right); 

} 

 

// Preorder traversal: Root -> Left -> Right 

void preorder(Node* root) { 

    if (root == nullptr) return; 

    cout << root->data << " "; 

    preorder(root->left); 

    preorder(root->right); 

} 

 

// Postorder traversal: Left -> Right -> Root 

void postorder(Node* root) { 

    if (root == nullptr) return; 

    postorder(root->left); 

    postorder(root->right); 

    cout << root->data << " "; 

} 

 

int main() { 

    Node* root = nullptr; 

    int n, val, choice; 

 

    cout << "Enter number of nodes: "; 

    cin >> n; 

 

    cout << "Enter values: "; 

    for (int i = 0; i < n; i++) { 

        cin >> val; 

        root = insert(root, val); 

    } 

 

    do { 

        cout << "\nChoose traversal:\n"; 

        cout << "1. Inorder\n"; 

        cout << "2. Preorder\n"; 

        cout << "3. Postorder\n"; 

        cout << "4. Exit\n"; 

        cout << "Enter choice: "; 

        cin >> choice; 

 

        switch (choice) { 

            case 1: 

                cout << "Inorder traversal: "; 

                inorder(root); 

                cout << "\n"; 

                break; 

            case 2: 

                cout << "Preorder traversal: "; 

                preorder(root); 

                cout << "\n"; 

                break; 

            case 3: 

                cout << "Postorder traversal: "; 

                postorder(root); 

                cout << "\n"; 

                break; 

            case 4: 

                cout << "Exiting.\n"; 

                break; 

            default: 

                cout << "Invalid choice, try again.\n"; 

        } 

    } while (choice != 4); 

 

    return 0; 

}