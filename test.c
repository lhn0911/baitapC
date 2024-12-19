#include <stdio.h>
#include <stdlib.h>

// Định nghĩa cấu trúc của một nút trong cây nhị phân
struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};

// Hàm tạo một nút mới
struct Node *createNode(int data)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Hàm chèn giá trị vào cây nhị phân tìm kiếm (BST)
struct Node *insertNode(struct Node *root, int data)
{
    if (root == NULL)
    {
        root = createNode(data);
    }
    else if (data < root->data)
    {
        root->left = insertNode(root->left, data);
    }
    else
    {
        root->right = insertNode(root->right, data);
    }
    return root;
}

// Hàm duyệt cây Tiền Thứ Tự (Pre-order)
void preOrderTraversal(struct Node *root)
{
    if (root != NULL)
    {
        printf("%d ", root->data);
        preOrderTraversal(root->left);
        preOrderTraversal(root->right);
    }
}

// Hàm duyệt cây Trung Thứ Tự (In-order)
void inOrderTraversal(struct Node *root)
{
    if (root != NULL)
    {
        inOrderTraversal(root->left);
        printf("%d ", root->data);
        inOrderTraversal(root->right);
    }
}

// Hàm duyệt cây Hậu Thứ Tự (Post-order)
void postOrderTraversal(struct Node *root)
{
    if (root != NULL)
    {
        postOrderTraversal(root->left);
        postOrderTraversal(root->right);
        printf("%d ", root->data);
    }
}

int main()
{
    struct Node *root = NULL;
    int n, value;

    // Nhập số lượng nút và các giá trị của chúng
    printf("Nhap so luong nut trong cay: ");
    scanf("%d", &n);

    printf("Nhap gia tri cac nut:\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &value);
        root = insertNode(root, value);
    }

    // In kết quả các kiểu duyệt cây
    printf("Duyet Tien Thu Tu: \n");
    preOrderTraversal(root);
    printf("\n");

    printf("Duyet Trung Thu Tu: \n");
    inOrderTraversal(root);
    printf("\n");

    printf("Duyet Hau Thu Tu: \n");
    postOrderTraversal(root);
    printf("\n");

    return 0;
}