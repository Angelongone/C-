 #include<stdio.h>
 #include<stdlib.h>
 #include<string.h>
 typedef struct number
 {
 	char name[10];
 	char city[10];
 	int num;
 	struct number *next;
 }Node,*node;
 node add(char *temp,node head);
 node del(char *temp,node head);
 int main()
 {
 	int close,j;
 	char name[10];
 	node head,p,p1,pick;
 	head=(node)malloc(sizeof(Node));
 	if(head==0)
 	{
 		printf("eorro");
 		exit(1);
	 }
	 else
	 {
	 	head->next=0;
	 	do{
			 
			 	p=(node)malloc(sizeof(Node));
			 	if(p==0)
			 	{
			 		printf("错误");
			 		exit(1);
				 }
				 else
				 {
				 	printf("请输入名字：");
				 	scanf("%s",&p->name);
				 	printf("请输入地址：");
				 	scanf("%s",&p->city);
				 	printf("请输入电话：");
				 	scanf("%d",&p->num);
					printf("\n继续输入1，退出输入0：");
					scanf("%d",&close); 
					printf("\n");
				 	if(head->next==0)
				 	{
				 		head->next=p;
				 		p1=p;
					 }
					 else
					 {
					 	p1->next=p;
					 	p1=p;
					 }
				 }
		}while(close!=0);
		system("cls"); 
		p1->next=0;
		p=head->next;
		while(p!=0)
		{
			printf("\n******************\n");
			printf("姓名：%s\n",p->name);
			printf("地址：%s\n",p->city);
			printf("号码：%d\n",p->num);
			p=p->next;
		}
	 }
	 system("cls");
	 do
	 {
	 	printf("需要添加请输入1，需要删除请输入2，不需要请输入0：");
		scanf("%d",&j);
		if(j==1)
		{
			printf("请输入插入点的名字：");
			scanf("%s",&name);
			pick=add(name,head);
			if(pick==0)
			{
				printf("没有此数据！！"); 
			}
			else
			{
				printf("以插入！！！");
			}
		 } 
		 else if(j==2)
		 {
		 	printf("请输入删除点的姓名：");
		 	scanf("%s",&name);
		 	pick=del(name,head);
		 	if(pick==0)
		 	{
		 		printf("没有此数据！！！"); 
			 }
			 else
			 {
			 	printf("以删除！！！");
			 }
		 }
		 printf("\n是否继续操作(是：1 ， 否：0)：");
		 scanf("%d",&j); 
	 }while(j!=0);
	 system("cls");
	 printf("新数据如下：");
		p=head->next;
		while(p!=0)
		{
			printf("\n******************\n");
			printf("姓名：%s\n",p->name);
			printf("地址：%s\n",p->city);
			printf("号码：%d\n",p->num);
			p=p->next;
		}
	 
 }
 
 
 
 
 node add(char *temp,node head)
 {
 	node New,
 	p=head->next;
 	New=(node)malloc(sizeof(Node));
 	if(New==0)
 	{
 		printf("erro");
 		exit(1);
	 }
	 else
	 {
	 	while(p!=0)
	 	{
	 		if(strcmp(temp,p->name)==0)
	 		{
	 			printf("请输入名字：");
	 			scanf("%s",&New->name);
	 			printf("请输入地址：");
				scanf("%s",&New->city); 
				printf("请输入号码：");
				scanf("%d",&New->num);
				New->next=p->next;
				p->next=New; 
				return New;
			}
			else
			{
				p=p->next;
			}
		 }
		 return NULL;
	 }
 }
  
node del(char *temp,node head)
{
	node p,q;
	p=head;
	while(p!=0)
	{
		if(strcmp(temp,p->next->name)==0)
		{
			q=p->next;
			p->next=p->next->next;
			free(q);
			return head;
		}
		else
		{
			p=p->next;
			return 0;
		}
	}
 } 
