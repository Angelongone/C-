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
			 		printf("����");
			 		exit(1);
				 }
				 else
				 {
				 	printf("���������֣�");
				 	scanf("%s",&p->name);
				 	printf("�������ַ��");
				 	scanf("%s",&p->city);
				 	printf("������绰��");
				 	scanf("%d",&p->num);
					printf("\n��������1���˳�����0��");
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
			printf("������%s\n",p->name);
			printf("��ַ��%s\n",p->city);
			printf("���룺%d\n",p->num);
			p=p->next;
		}
	 }
	 system("cls");
	 do
	 {
	 	printf("��Ҫ���������1����Ҫɾ��������2������Ҫ������0��");
		scanf("%d",&j);
		if(j==1)
		{
			printf("��������������֣�");
			scanf("%s",&name);
			pick=add(name,head);
			if(pick==0)
			{
				printf("û�д����ݣ���"); 
			}
			else
			{
				printf("�Բ��룡����");
			}
		 } 
		 else if(j==2)
		 {
		 	printf("������ɾ�����������");
		 	scanf("%s",&name);
		 	pick=del(name,head);
		 	if(pick==0)
		 	{
		 		printf("û�д����ݣ�����"); 
			 }
			 else
			 {
			 	printf("��ɾ��������");
			 }
		 }
		 printf("\n�Ƿ��������(�ǣ�1 �� ��0)��");
		 scanf("%d",&j); 
	 }while(j!=0);
	 system("cls");
	 printf("���������£�");
		p=head->next;
		while(p!=0)
		{
			printf("\n******************\n");
			printf("������%s\n",p->name);
			printf("��ַ��%s\n",p->city);
			printf("���룺%d\n",p->num);
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
	 			printf("���������֣�");
	 			scanf("%s",&New->name);
	 			printf("�������ַ��");
				scanf("%s",&New->city); 
				printf("��������룺");
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
