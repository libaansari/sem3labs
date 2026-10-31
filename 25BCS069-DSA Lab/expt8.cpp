#include <iostream> 

using namespace std; 

 

struct Node { 

    int data; 

    Node *left, *right; 

 

    Node(int value) { 

        data = value; 

        left = right = NULL; 

    } 

}; 

 

Node* insert(Node* root, int value) { 

    if (root == NULL) 

        return new Node(value); 

 

    if (value < root->data) 

        root->left = insert(root->left, value); 

    else if (value > root->data) 

        root->right = insert(root->right, value); 

 

    return root; 

} 

 

Node* findMin(Node* root) { 

    while (root->left != NULL) 

        root = root->left; 

    return root; 

} 

 

Node* deleteNode(Node* root, int value) { 

    if (root == NULL) 

        return NULL; 

 

    if (value < root->data) 

        root->left = deleteNode(root->left, value); 

    else if (value > root->data) 

        root->right = deleteNode(root->right, value); 

    else { 

        if (root->left == NULL) { 

            Node* temp = root->right; 

            delete root; 

            return temp; 

        } 

        else if (root->right == NULL) { 

            Node* temp = root->left; 

            delete root; 

            return temp; 

        } 

 

        Node* temp = findMin(root->right); 

        root->data = temp->data; 

        root->right = deleteNode(root->right, temp->data); 

    } 

 

    return root; 

} 

 

// Inorder: Left, Root, Right 

void inorder(Node* root) { 

    if (root != NULL) { 

        inorder(root->left); 

        cout << root->data << " "; 

        inorder(root->right); 

    } 

} 

 

// Preorder: Root, Left, Right 

void preorder(Node* root) { 

    if (root != NULL) { 

        cout << root->data << " "; 

        preorder(root->left); 

        preorder(root->right); 

    } 

} 

 

// Postorder: Left, Right, Root 

void postorder(Node* root) { 

    if (root != NULL) { 

        postorder(root->left); 

        postorder(root->right); 

        cout << root->data << " "; 

    } 

} 

 

void display(Node* root) { 

    cout << "\nInorder: "; 

    inorder(root); 

 

    cout << "\nPreorder: "; 

    preorder(root); 

 

    cout << "\nPostorder: "; 

    postorder(root); 

    cout << endl; 

} 

 

int main() { 

    Node* root = NULL; 

    int n, value, key; 

 

    cout << "Enter number of nodes: "; 

    cin >> n; 

 

    cout << "Enter node values: "; 

    for (int i = 0; i < n; i++) { 

        cin >> value; 

        root = insert(root, value); 

    } 

 

    cout << "\nBefore insertion and deletion:"; 

    display(root); 

 

    cout << "\nEnter value to insert: "; 

    cin >> value; 

    root = insert(root, value); 

 

    cout << "\nAfter insertion:"; 

    display(root); 

 

    cout << "\nEnter value to delete: "; 

    cin >> key; 

    root = deleteNode(root, key); 

 

    cout << "\nAfter deletion:"; 

    display(root); 

 

    return 0; 

} 