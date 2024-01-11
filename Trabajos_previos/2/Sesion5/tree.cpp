#include <iostream>
using namespace std;

// Definición de la estructura Node
struct Node {
    int data;
    struct Node *left, *right;
    Node(int data) {
        this->data = data;
        left = right = NULL;
    }
};

// Travesía en preorden (Preorder traversal)
void preorderTraversal(struct Node* node) {
    // Verificar si el nodo es nulo
    if (node == NULL)
        return;

    // Imprimir el valor del nodo actual
    cout << node->data << " ";

    // Llamadas recursivas para el subárbol izquierdo y derecho
    preorderTraversal(node->left);
    preorderTraversal(node->right);
}

// Travesía en postorden (Postorder traversal)
void postorderTraversal(struct Node* node) {
    // Verificar si el nodo es nulo
    if (node == NULL)
        return;

    // Llamadas recursivas para el subárbol izquierdo y derecho
    postorderTraversal(node->left);
    postorderTraversal(node->right);

    // Imprimir el valor del nodo actual
    cout << node->data << " ";
}

// Travesía en orden (Inorder traversal)
void inorderTraversal(struct Node* node) {
    // Verificar si el nodo es nulo
    if (node == NULL)
        return;

    // Llamadas recursivas para el subárbol izquierdo y derecho
    inorderTraversal(node->left);

    // Imprimir el valor del nodo actual
    cout << node->data << " -> ";

    inorderTraversal(node->right);
}

int main() {
    // Crear un árbol
    struct Node* root = new Node(1);
    root->left = new Node(12);
    root->right = new Node(9);
    root->left->left = new Node(5);
    root->left->right = new Node(6);

    // Imprimir los resultados de diferentes travesías
    cout << "Inorder traversal ";
    inorderTraversal(root);

    cout << "\nPreorder traversal ";
    preorderTraversal(root);

    cout << "\nPostorder traversal ";
    postorderTraversal(root);

    return 0;
}
