#include<stdio.h>
#include<stdlib.h>
#include <string.h> 
#define N 20 
typedef int ElemType;
typedef struct{
	//���ݿռ䣬��100�� 
	ElemType data[N];
	//�ռ��д�Ŷ������� 
	int top;//��ǰռ�� 
}SqStack;   
/*
����ջ���Ǹ�����ʹ�õ�
1.��ʼ��:�����һ��ջ���Ҹ������ 
2.ջ��  ����һ��ջ�����жϽ�����ж�ջ�ǲ��ǿա� 
3.ջ�� �����һ��ջ�����ж���� �ж�ջ�ǲ����� 
4.Ԫ�ؽ�  ��Ҫ��ջ��һ��Ԫ��   �Ұ�Ԫ�طŽ�ջ� 
5.Ԫ�س�   ���һ��ջ ����ȡ������Ԫ�� 
����������ʹ��ջ�ˣ� 
*/
void init_stack(SqStack *s){
	s->top=0;//ջ��λ�ã�ָ��ջ��Ԫ����һ��λ�� 
} 
//�п� 
int empty_stack(SqStack *s) {
	if(s->top==0)
	return 1;
	return 0;
}
//���� 
int full_stack(SqStack *s) {
	if(s->top==4)
	return 1;
	return 0;
}
//��ջ 
void push_stack(SqStack *s,ElemType e){
	if(full_stack(s)){
		printf("stack full.");
		exit(0);
	}
	s->data[s->top]=e;
	s->top++;
}
//��ջ 
void pop_stack(SqStack *s,ElemType *e){
	if(empty_stack(s)){
		printf("stack empty.");
		exit(0);
	}
	s->top--;
	*e=s->data[s->top];

}
//��ȡջ��Ԫ��
ElemType get_stack(SqStack s){
	return s.data[s.top-1];
} 
int main(){
	//123����213�� 
	SqStack s;
	int x,y;
	init_stack(&s);
	push_stack(&s,1);
	x=get_stack(s);
	printf("%d\n",x);
	push_stack(&s,2);
	x=get_stack(s);
	printf("%d\n",x);
	pop_stack(&s,&y);
	printf("%d\n",y);
	pop_stack(&s,&y);
	printf("%d\n",y);
		push_stack(&s,3);
	x=get_stack(s);
	printf("%d\n",x);
	system("pause");
	return 0;
}
