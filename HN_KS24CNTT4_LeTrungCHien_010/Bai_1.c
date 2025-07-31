//
// Created by Admin on 31/07/2025.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Book{
int id;
char title[20];
int price;
char author[20];
char category[20];
char date[20];
} Book;
typedef struct Node{
Book book;
struct Node * next;
} Node;
typedef struct DoubleNode{
 Book book;
struct DoubelNode * next;
struct DoubelNode * prev;
} DoubleNode;
Node*createNode(Book book) {
 Node*newNode=(Node*)malloc(sizeof(Node));
 newNode->book=book;
 newNode->next=NULL;
 return newNode;
}
Node*insertNode(Node*head,Book book) {
 DoubleNode*newNode=createNode(book);
 if(head==NULL) {
  head=newNode;
  return newNode;
 }
 Node*temp=head;
 while (temp->next !=NULL) {
  temp=temp->next;
 }
 temp->next=newNode;
 newNode->prev=temp;
 return head;
}
void printBook(Node*head) {
 if(head==NULL) {
  printf("Khong co sach\n");
  return;
 }
 Node*temp=head;
 while (temp !=NULL) {
  printf("ID :%d   ",temp->book.id);
  printf(" Titre :%s  ",temp->book.title);
  printf("Price :%d   ",temp->book.price);
  printf("Author :%s   ",temp->book.author);
  printf("Category :%s  ",temp->book.category);
  printf("Date :%s  ",temp->book.date);
  printf("\n");
  temp=temp->next;
 }
}
Node*deleteBook(Node*head) {
 if(head==NULL) {
  printf("khong co sach\n");
  return head;
 }
 int id;
 printf("Nhap id muon xoa :");
 scanf("%d",&id);
 Node*temp=head;
 Node*temp2=NULL;
 while (temp!=NULL&& temp->book.id!=id) {
  temp2=temp;
  temp=temp->next;
 }
 if (temp==NULL) {
  printf("khong tim thay sach muon xoa");
  return head;
 }
 if (temp==head) {
  head=head->next;
  free(temp);
  return head;
 }
 temp2->next=temp->next;
 free(temp);
 return head;
}
Node*updateBook(Node*head) {
 if (head==NULL) {
  printf("khong co sach\n");
  return head;
 }
 int id;
 printf("Nhap id muon sua :");
 scanf("%d",&id);
 Node*temp=head;
 while (temp!=NULL && temp->book.id!=id) {
  temp=temp->next;
 }
 char name[20];
 printf("Nhap ten moi :");
 scanf("%s",name);
 strcpy(temp->book.title,name);
 printf("Nhap ngay moi :");
 char date[20];
 scanf("%s",date);
 strcpy(temp->book.author,date);
 printf("Nhap ten tac gia moi :");
 char author[20];
 scanf("%s",author);
 strcpy(temp->book.author,author);
int price;
 printf("nhap gia moi:");
 scanf("%d",&price);
 temp->book.price=price;
}
void seachBook(Node*head) {
 if (head==NULL) {
  printf("khong co sach\n");
  return;
 }
 Node*temp=head;
 while (temp!=NULL) {
  if (strstr(temp->book.title,temp->book.author)!=NULL) {
   printf("ID :%d",temp->book.id);
   printf("Titre :%s",temp->book.title);
   printf("Price :%d",temp->book.price);
   printf("Author :%s",temp->book.author);
   printf("Category :%s",temp->book.category);
   printf("Date :%s",temp->book.date);
   printf("\n");
  }
  temp=temp->next;
 }
}
Node*sortBook(Node*head) {
 if (head==NULL) {
  printf("khong co sach");
  return head;
 }
 Node*i;
 Node*j;
 for (i=head;i!=NULL;i=i->next) {
  for (j=i->next;j!=NULL;j=j->next) {
    if (i->book.price > j->book.price) {
     Book temp=i->book;
     i->book=j->book;
     j->book=temp;
    }
  }
 }
 return head;
}
int main(){
 int id=1;
int choice;
 Node*head=NULL;
 DoubleNode*headDouble=NULL;
do{
  printf("========Menu=======\n");
  printf("1. them sach\n");
  printf("2. Hien thi danh sach cac quyen\n");
  printf("3. Xoa sach\n");
  printf("4. Cap nhat thong tin sach\n");
  printf("5. Danh dau cho thue\n");
  printf("6. Sap xep sach\n");
printf("7. Tim kiem sach\n");
printf("8. Thoat chuong trinh\n");
printf("Lua chon :");
scanf("%d",&choice);

 switch(choice){
  case 1:
   Book newBook;
   newBook.id=id++;
   printf("Nhap ten sach: ");
   scanf("%s",newBook.title);
   printf("Nhap gia :");
   scanf("%d",&newBook.price);
   printf("Nhap ten tac gia :");
   scanf("%s",newBook.author);
   printf("Nhap loai sach :");
   scanf("%s",newBook.category);
   printf("Nhap ngay nhap sach :");
   scanf("%s",newBook.date);
   head=insertNode(head,newBook);
 break;
 case 2:
   printBook(head);
 break;
case 3:
   head=deleteBook(head);
break;
case 4:
 head=updateBook(head);
break;
case 5:

break;
case 6:
   head=sortBook(head);
   printBook(head);
break;
case 7:
   seachBook(head);
break;
case 8:
 printf("Chuong trinh ket thuc\n");
break;
default:
printf("lua chon khong hop le\n");
break;
}
}while(choice!=8);
return 0;
}