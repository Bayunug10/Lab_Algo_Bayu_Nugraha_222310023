#include <iostream>

using namespace std;

// Struktur data untuk simpul Node
struct Node {
    int data;
    Node* left;
    Node* right;
};

// Fungsi untuk membuat simpul Node baru
Node* createNode(int data) {
    Node* newNode = new Node();
    if (!newNode) {
        cout << "Error: Alokasi memori gagal." << endl;
        return NULL;
    }
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Fungsi untuk memasukkan bilangan ke dalam Tree
Node* insertNode(Node* root, int data) {
    if (root == NULL) {
        root = createNode(data);
        return root;
    }
    if (data < root->data) {
        root->left = insertNode(root->left, data);
    } else if (data > root->data) {
        root->right = insertNode(root->right, data);
    }
    return root;
}

// Fungsi untuk traversal Pre-order (Pre-order: Root->Left->Right)
void preOrderTraversal(Node* root) {
    if (root == NULL) {
        return;
    }
    cout << root->data << " ";
    preOrderTraversal(root->left);
    preOrderTraversal(root->right);
}

// Fungsi untuk traversal In-order (In-order: Left->Root->Right)
void inOrderTraversal(Node* root) {
    if (root == NULL) {
        return;
    }
    inOrderTraversal(root->left);
    cout << root->data << " ";
    inOrderTraversal(root->right);
}

// Fungsi untuk traversal Post-order (Post-order: Left->Right->Root)
void postOrderTraversal(Node* root) {
    if (root == NULL) {
        return;
    }
    postOrderTraversal(root->left);
    postOrderTraversal(root->right);
    cout << root->data << " ";
}

int main() {
    Node* root = NULL;

    // Memasukkan bilangan ke dalam Tree
    root = insertNode(root, 12);
    root = insertNode(root, 16);
    root = insertNode(root, 20);
    root = insertNode(root, 24);
    root = insertNode(root, 32);

    // Menampilkan hasil traversal
    cout << "Pre-order traversal: ";
    preOrderTraversal(root);
    cout << endl;

    cout << "In-order traversal: ";
    inOrderTraversal(root);
    cout << endl;

    cout << "Post-order traversal: ";
    postOrderTraversal(root);
    cout << endl;

    return 0;
}