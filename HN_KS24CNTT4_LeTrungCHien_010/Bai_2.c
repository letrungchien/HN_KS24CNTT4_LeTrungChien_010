//
// Created by Admin on 31/07/2025.
//
#include<stdio.h>
#include<stdlib.h>
typedef  struct Employee {
    char name[20];
    char date[20];
} Employee;
typedef  struct Node {
    Employee* employee;
    struct Node*left;
    struct Node*right;
} Node;
typedef struct Queue {
    Node**data;
    int capacity;
    int front;
    int rear;
} Queue;

Node* createNode(Employee *employee) {
    Node*newNode=(Node*)malloc(sizeof(Node));
    newNode->employee=employee;
    newNode->left=NULL;
    newNode->right=NULL;
    return newNode;
}
Queue* createQueue(int capacity) {
    Queue*newQueue=(Queue*)malloc(sizeof(Queue));
    newQueue->capacity=capacity;
    newQueue->front=0;
    newQueue->rear=-1;
    newQueue->data=(Node**)malloc(sizeof(Node*)*capacity);
    return newQueue;
}
int isEmpty(Queue* queue) {
    if (queue->front>queue->rear){
    return 1;
    }
    return 0;
}

void pushQueue(Queue* queue, Node* node) {
    if(queue->rear==queue->capacity-1) {
        printf("FULL");
        return;
    }
    queue->rear++;
    queue->data[queue->rear]=node;
}
void pushNode(Node**root, Employee* employee) {
    if(*root==NULL) {
        *root=createNode(employee);
        return ;
    }
    Queue* queue=createQueue(100);
    pushQueue(queue,*root);
    while (!isEmpty(queue)) {
        Node*node=queue->data[queue->front];
        queue->front++;
        if (node->left !=NULL) {
            pushQueue(queue,node->left);
        }else {
            node->left=createNode(employee);
            free(queue->data);
            free(queue);
            return ;
        }
        if (node->right !=NULL) {
            pushQueue(queue,node->right);
        }else {
            node->right=createNode(employee);
            free(queue->data);
            free(queue);
            return;
        }

    }
}
void printNode(Node**root) {
    if(*root==NULL) {
        printf("EMPTY");
        return;
    }
    Queue*queue=createQueue(100);
    pushQueue(queue,*root);
    while (!isEmpty(queue)) {
        Node*node=queue->data[queue->front];
        printf("Ten :%s   ",node->employee->name);
        printf("Ngay :%s  \n",node->employee->date);
        queue->front++;
        if (node->left !=NULL) {
            pushQueue(queue,node->left);
        }
        if (node->right !=NULL) {
            pushQueue(queue,node->right);
        }
    }
    free(queue->data);
    free(queue);
    return;
}
int high(Node* root) {
    if (root==NULL) {
        return 0;
    }
    int h1=high(root->left);
    int h2=high(root->right);

    return 1+(h1>h2 ? h1 : h2);
}
int main() {
int choice;
    Node*root=NULL;
    do {
        printf("========MENU=========\n");
        printf("1.Them nhan su\n");
        printf("2 .In so do nhan su\n");
        printf("3 . Tim kiem nhan vien\n");
        printf("4 .Tinh chieu cao\n");
        printf("5. In duong dan tu CEO den nhan su bat ky\n");
        printf("6. thoat");
        printf("Nhap lua chon :");
        scanf("%d",&choice);
       switch(choice) {
           case 1:
               Employee *newEmployee;
               printf("Nhap ten :");
               scanf("%s",&newEmployee->name);
               printf("Nhap ngay");
               scanf("%s",&newEmployee->date);
               pushNode(&root,&newEmployee);
               break;
               case 2:
               printNode(&root);
               break;
               case 3:
               break;
               case 4:
               break;
               case 5:
               printf("chieu cao la",high(root));
               break;
              case 6:
               printf("Chuong trinh ket thuc");
               break;
               default:
               printf("Lua chon khong hop le\n");
               break;

       }
    }while(choice != 6);
    return  0;
}