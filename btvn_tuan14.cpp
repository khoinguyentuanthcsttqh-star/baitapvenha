#include<iostream>
using namespace std;


struct Node {
    int data;
    Node* left;
    Node* right;
    int chieuCao;
};
int chieuCao(Node* p) {
    if (p == NULL)
        return 0;
    return p->chieuCao;
}
int soLonNhat(int a, int b) {
    if (a > b)
        return a;
    return b;
}
Node* taoNode(int x) {
    Node* p = new Node;

    p->data = x;
    p->left = NULL;
    p->right = NULL;
    p->chieuCao = 1;

    return p;
}
// quay phải
Node* XoayPhai(Node* y) {
    Node* x = y->left;
    Node* T = x->right;

    x->right = y;
    y->left = T;

    y->chieuCao = soLonNhat(chieuCao(y->left), chieuCao(y->right)) + 1;
    x->chieuCao = soLonNhat(chieuCao(x->left), chieuCao(x->right)) + 1;
    return x;
}
// quay trái
Node* XoayTrai(Node* x) {
    Node* y = x->right;
    Node* T = y->left;

    y->left = x;
    x->right = T;

    x->chieuCao = soLonNhat(chieuCao(x->left), chieuCao(x->right)) + 1;
    y->chieuCao = soLonNhat(chieuCao(y->left), chieuCao(y->right)) + 1;

    return y;
}
int tinhCanBang(Node* p) {
    if (p == NULL)
        return 0;

    return chieuCao(p->left) - chieuCao(p->right);
}
Node* themNode(Node* root, int x) {

    if (root == NULL)
        return taoNode(x);

    if (x < root->data)
        root->left = themNode(root->left, x);

    else if (x > root->data)
        root->right = themNode(root->right, x);

    else
        return root;

    root->chieuCao =
        soLonNhat(chieuCao(root->left), chieuCao(root->right)) + 1;

    int balance = tinhCanBang(root);
    // Left Left
    if (balance > 1 && x < root->left->data)
        return XoayPhai(root);

    // Right right
    if (balance < -1 && x > root->right->data)
        return XoayTrai(root);

    // Left right
    if (balance > 1 && x > root->left->data) {
        root->left = XoayTrai(root->left);
        return XoayPhai(root);
    }

    // Right Left
    if (balance < -1 && x < root->right->data) {
        root->right = XoayPhai(root->right);
        return XoayTrai(root);
    }

    return root;
}
// duyệt giữa LNR
void Duyet_giua(Node* root) {
    if (root != NULL) {
        Duyet_giua(root->left);
        cout << root->data << " ";
        Duyet_giua(root->right);
    }
}

int main() {

    int a[] = {32, 51, 27, 83, 96, 11, 45, 75, 66};
    int n = sizeof(a) / sizeof(a[0]);

    Node* root = NULL;

    // thêm các phần tử vào cây AVL
    for (int i = 0; i < n; i++) {
        root = themNode(root, a[i]);
    }

    cout << "Cac phan tu tren cay AVL sau khi duyet LNR:\n";
    Duyet_giua(root);

    return 0;
}
