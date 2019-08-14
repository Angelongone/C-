#include<stdio.h>
#include<stdlib.h>
typedef struct student
{
	int num;
	char name[10];
	int gaokao;
	int kaoshi;
	struct student *next;//定义next 
  } Node,*node;				//定义Node,node 
  int main()
  {
  	int sum,i;
  	char name[10];
  	node p,p1,head;			//定义node类型的三个变量 
  	head=(node)malloc(sizeof(Node));	//给head分配空间 
  	if(head==NULL)				//判断是否成功分配空间 
  	{
  		printf("error");
  		exit(1); 				//程序退出 
	  }
	  else
	  {
	  	printf("请输入人数：");
	  	scanf("%d",&sum);
	  	head->next=NULL;			//因为head目前还没有可以指向的空间 
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
			  	printf("请输入学号：");
				  scanf("%d",&p->num);
				  printf("请输入姓名：");
				  scanf("%s",&p->name);
				  printf("请输入高考成绩：");
				  scanf("%d",&p->gaokao );
				  printf("请输入现在成绩：");
				  scanf("%d",&p->kaoshi);
				  if(head->next==NULL)
				  {
				  	head->next=p;			//这是第一个有值的空间 
				  	p1=p;
				   } 
				   else
				   {						//将接下来的链接到链表中 
				   	p1->next=p;
				   	p1=p;
				   }
			  }
		  }
		  p1->next=NULL;
		  p=head->next;				//因为接下来要在p中取值，所以将p指向头指针 
		  printf("学生信息如下：\n");
		  while(p!=NULL)				//直到p=0退出 
		  {
		  	printf("学号：%d\n",p->num);
		  	printf("姓名：%s\n",p->name);
		  	printf("高考成绩：%d\n",p->gaokao);
		  	printf("现在成绩：%d\n",p->kaoshi);
			p=p->next; 						//每次循环将p指向他的下一个空间 
		  }
	  }
  }



