#include <stdio.h>
#include <stdlib.h>

#define Num 20

void CreateBinaryTree(int*, int);
void Postorder(int);
void Inorder(int);
void Preorder(int);

int data[Num]={0};
int BinaryTree[Num]={0};

int main(void) {
    int n;
    printf("請輸入節點個數：");
    scanf("%d", &n);
    printf("請輸入這 %d 個節點的內容：\n", n);
    for (int i=0; i<n; i++) {
       scanf(" %d", &data[i]);
       }
    CreateBinaryTree(data, n); //呼叫建立二元樹之副程式
    printf("二元樹前序追蹤的結果：\n");
    Preorder(1);   //呼叫前序之副程式
    printf("\n");
    printf("二元樹中序追蹤的結果：\n");
    Inorder(1);   //呼叫中序之副程式
    printf("\n");
    printf("二元樹後序追蹤的結果：\n");
    Postorder(1);   //呼叫後序之副程式
    printf("\n");
    return 0;
    }

void CreateBinaryTree(int data[], int n) {   //建立二元樹
    int node=1, temp;
    for (int i=0; i<Num; i++) {BinaryTree[i]=0;}  //初值設定
    for (int i=0; i<n; i++) {
        BinaryTree[node]=data[i];
        node=node + 1;
        }
    }

void Postorder(int node) {   //後序追蹤
    if (BinaryTree[node] != 0) {
         Postorder(2*node);    //遞迴左子樹
         Postorder(2*node+1);  //遞迴右子樹
         if (BinaryTree[node] != 0) {  //列印樹根
             printf("%d ",BinaryTree[node]);
             }
         }
    }

void Inorder(int node) {  //中序追蹤
    if (BinaryTree[node] != 0) {
        Inorder(2*node);   //遞迴左子樹
        if (BinaryTree[node] != 0) {  //列印樹根
            printf("%d ", BinaryTree[node]);
            }
        Inorder(2*node+1);  //遞迴右子樹             
        }
    }

void Preorder(int node) {  //前序追蹤
    if (BinaryTree[node]!=0) {
         if (BinaryTree[node]!=0) {
             printf("%d ",BinaryTree[node]);  //列印樹根
             }
         Preorder(2*node);    //遞迴左子樹
         Preorder(2*node+1);  //遞迴右子樹
         }
    }
