/*
���ԡ����� �����ݵĴ洢 ������ʽ�洢
*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct{
        int id;
        char name[30];
        char phone[20];
        //char addr[50];
}ELenType;
typedef struct node{
        ELenType data;
        struct node *next;//ָ����һ��Ԫ�صĵ�ַ
}*LinkList,LNode;
LinkList create_head_list(){//����һ������ͷ���ĵ�����
        LinkList h;
        LinkList p;
        h=(LinkList)malloc(sizeof(LNode));
        h->next=NULL;
        int x;//�Լ�����n�����ݵĽ�����־������0����
        char name[30];
        char phone[20];
        scanf("%d%s%s",&x,&name,&phone);
        while(x){
                 p=(LinkList)malloc(sizeof(LNode));
                 p->data.id=x;
                 strcpy(p->data.name,name);
                 strcpy(p->data.phone,phone);
                 p->next=h->next;
                 h->next=p;                 
                 scanf("%d%s%s",&x,&name,&phone);
        }       
        return h;
}
LinkList reverse_list(LinkList L){
	LinkList h,q,r;
	h=L;
	h->next=NULL;
	q=L->next;
	while(q){
	r=q;
	q++;
	r->next=h->next;
	h->next=r;	
	}
	return h;
	
}
void print_list(LinkList L){
        LinkList p;
        p=L->next;
        printf("���\t����\t�绰\n");
        while(p){
                printf("%d\t%s\t%s\n",p->data.id,p->data.name,p->data.phone);
                p=p->next;
        }
}
int main(){
		LinkList L,s;        
        L=create_head_list();        
        print_list(L);
        s=reverse_list(L);
        print_list(s);
        system("pause");
        return 0;
}
