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
LinkList create_list(){//����һ������ͷ���ĵ�����
        LinkList p,q;
        LinkList L;
        L=(LinkList)malloc(sizeof(LNode));
        q=L;
        int x;//�Լ�����n�����ݵĽ�����־������0����

        char name[30];
        char phone[20];
        scanf("%d%s%s",&x,&name,&phone);
        while(x){
                 p=(LinkList)malloc(sizeof(LNode));
                 p->data.id=x;
                 strcpy(p->data.name,name);
                 strcpy(p->data.phone,phone);
                 q->next=p;
                 q=p;
                 scanf("%d%s%s",&x,&name,&phone);
        }
        q->next=NULL;//�������һ���ڵ����
        return L;
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
//����
LinkList locate_list(LinkList L,int e){
        LinkList p;
        p=L->next;
        while(p){
                if(p->data.id==e)
                return p;
                p=p->next;
        }
        return NULL;
}
//ͳ�ƽڵ���� 
int count_list(LinkList L){
        LinkList p;
        int x;
        p=L->next;
        while(p){
                x++;
                p=p->next;
        }
        return x;
}
//���ҽڵ�
LinkList  find_list(LinkList L,int x){
	LinkList p;
        int i=0;
        p=L->next;
        while(p){
                i++;
                if(i==x)
                	return p;
                p=p->next;
                
        }
        return NULL;
}
//c����ĳ���ڵ��ǰ��
LinkList find_pre_list(LinkList L,int x) {
		LinkList p,pre;
        int i=0;
        p=L->next;
        pre=L;
        while(p){        	
                i++;
                if(i==x)
                	return pre;
                	pre=p;
                p=p->next;
                
        }
        return NULL;
}
void pandu(LinkList p){
	if(p){
	printf("���\t����\t�绰\n");
    printf("%d\t%s\t%s\n",p->data.id,p->data.name,p->data.phone);
	}else
	printf("û���ҵ���\n");
	
}
int main(){
        //����һ���洢�ռ�
        LinkList L,p;
        int sum;
        L=create_list();
        print_list(L);
        p=locate_list(L,2);//�����Ϊ2�Ľڵ�
        if(p!=NULL)
        	printf("�ҵ���\n");
        else
            printf("û�ҵ�\n");
        sum=count_list(L);
        printf("����%d���ڵ�\n",sum);
        //���ҵ�2���ڵ�
        p=find_list(L,2);
        pandu(p);
        //���ҵڶ�������ǰ��
		p=find_pre_list(L,2);
		pandu(p);
        system("pause");
        return 0;
}

