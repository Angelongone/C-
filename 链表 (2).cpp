#include<stdio.h>
#include<stdlib.h>
typedef struct student
{
	int num;
	char name[10];
	int gaokao;
	int kaoshi;
	struct student *next;//����next 
  } Node,*node;				//����Node,node 
  int main()
  {
  	int sum,i;
  	char name[10];
  	node p,p1,head;			//����node���͵��������� 
  	head=(node)malloc(sizeof(Node));	//��head����ռ� 
  	if(head==NULL)				//�ж��Ƿ�ɹ�����ռ� 
  	{
  		printf("error");
  		exit(1); 				//�����˳� 
	  }
	  else
	  {
	  	printf("������������");
	  	scanf("%d",&sum);
	  	head->next=NULL;			//��ΪheadĿǰ��û�п���ָ��Ŀռ� 
	  	for(i=0;i<sum;i++)
	  	{
	  		p=(node)malloc(sizeof(Node));
	  		if(p==NULL)
	  		{
	  			printf("error");
	  			exit(1);
			  }
			  else
			  {
			  	printf("������ѧ�ţ�");
				  scanf("%d",&p->num);
				  printf("������������");
				  scanf("%s",&p->name);
				  printf("������߿��ɼ���");
				  scanf("%d",&p->gaokao );
				  printf("���������ڳɼ���");
				  scanf("%d",&p->kaoshi);
				  if(head->next==NULL)
				  {
				  	head->next=p;			//���ǵ�һ����ֵ�Ŀռ� 
				  	p1=p;
				   } 
				   else
				   {						//�������������ӵ������� 
				   	p1->next=p;
				   	p1=p;
				   }
			  }
		  }
		  p1->next=NULL;
		  p=head->next;				//��Ϊ������Ҫ��p��ȡֵ�����Խ�pָ��ͷָ�� 
		  printf("ѧ����Ϣ���£�\n");
		  while(p!=NULL)				//ֱ��p=0�˳� 
		  {
		  	printf("ѧ�ţ�%d\n",p->num);
		  	printf("������%s\n",p->name);
		  	printf("�߿��ɼ���%d\n",p->gaokao);
		  	printf("���ڳɼ���%d\n",p->kaoshi);
			p=p->next; 						//ÿ��ѭ����pָ��������һ���ռ� 
		  }
	  }
  }



