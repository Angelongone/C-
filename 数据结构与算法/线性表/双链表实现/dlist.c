#include "dlist.h"
#include <stdio.h>
#include <stdlib.h>

pHead DlistCreate()  //创建双向链表
{
	pHead ph = (pHead)malloc(sizeof(struct Head)); //为头结点分配空间
	if (ph == NULL)
		printf("分配头结点失败！"); //为了方便运行结果查看，不设置return返回
	//创建好头结点后，初始化头结点中数据
	ph->length = 0;
	ph->next = NULL;
	return ph; //将头结点返回
}
int getLength(pHead ph) //获取双向链表的长度
{
	//先对传入进来的链表作健壮性检查
	if (ph == NULL)
		printf("传入的双链表有误！");
	return ph->length;
}

int IsEmpty(pHead ph) //判断双链表是否为空
{
	if (ph == NULL)
		printf("传入的双链表有误！");
	if (ph->length == 0) //如果长度为0，则链表为空
		return 1;
	else
		return 0;
}

int DlistInsert(pHead ph, int pos, int val) //在链表的pos位置插入元素val
{
	pNode pval = NULL;
	//先作健壮性判断
	if (ph == NULL || pos < 0 || pos > ph->length)
		printf("插入元素时，参数传入有误！");

	//如果参数无误，就要为元素分配结点空间
	pval = (pNode)malloc(sizeof(struct Node));
	pval->data = val; //将值val保存到此结点中

	//接下来要判断在哪个位置插入元素，先判断链表是否为空
	if (IsEmpty(ph)) //如果链表为空
	{
		ph->next = pval; //直接将结点插入到头结点后
		pval->next = NULL;
		pval->pre = NULL; //第一个结点不回指头结点
	}
	else //如果双链表不为空，则要判断是插入哪个位置
	{
		pNode pCur = ph->next;
		if (pos == 0) //在第一个位置（头结点后）插入
		{
			ph->next = pval; //头结点指向pval
			pval->pre = NULL;
			pval->next = pCur; //pval的后继指针指向pCur
			pCur->pre = pval; //pCur前驱指针指向pval
		}
		else //如果不是插入到第一个位置
		{
			for (int i = 1; i < pos; i++) //就要遍历链表找到要插入的位置
			{
				pCur = pCur->next; //pCur指针向后移
			}
			//循环结束后，此时pCur指向的是要插入的位置
			pval->next = pCur->next; //指针断开再连接的过程
			pCur->next->pre = pval;
			pval->pre = pCur;
			pCur->next = pval;
		}
	}
	ph->length++;
	return 1;
}

pNode DlistDelete(pHead ph, int val) //删除双向链表ph中的元素val
{
	if (ph == NULL || ph->length == 0)
	{
		printf("参数传入有误！");
	}
	//如果参数无误，则遍历找到值为val的元素，然后将其删除
	pNode pval = DlistFind(ph, val); //找到值所在的结点
	if (pval == NULL)
	{
		return NULL;
	}
	printf("将其删除\n");
	//因为双链表中的结点既有前驱结点又有后继结点
	pNode pRe = pval->pre; //pRe指向pval结点的前驱结点
	pNode pNext = pval->next; //pNext指向pval结点的后继结点

	pRe->next = pNext;
	pNext->pre = pRe;
	return pval;
}

pNode DlistFind(pHead ph, int val) //查找某个元素
{
	if (ph == NULL)
	{
		printf("参数传入有误！");
	}
	//如果参数无误，则需要遍历双链表，查找要找的元素
	pNode pTmp = ph->next;  //此过程与单链表无异
	do
	{
		if (pTmp->data == val)
		{
			printf("有此元素！\n");
			return pTmp;
		}
		pTmp = pTmp->next;
	} while (pTmp->next != NULL); //循环条件是直到链表结尾

	printf("没有值为%d的元素!\n", val);
	return NULL;
}

void DlistDestory(pHead ph) //销毁链表
{
	pNode pCur = ph->next;
	pNode pTmp;
	if (ph == NULL)
		printf("参数传入有误！");

	while (pCur->next != NULL)
	{
		pTmp = pCur->next;
		free(pCur); //将结点释放
		pCur = pTmp;
	}
	ph->length = 0; //回到初始化状态
	ph->next = NULL;
}

void printFront(pHead ph) //打印双向链表中的元素，从前往后打印
{
	if (ph == NULL)
	{
		printf("参数传入有误！");
	}
	pNode pTmp = ph->next;
	while (pTmp != NULL)
	{
		printf("%d  ", pTmp->data);
		pTmp = pTmp->next;
	}
	printf("\n");
}

void printLast(pHead ph) //倒序打印，从链表末尾开始向前打印
{
	if (ph == NULL)
	{
		printf("参数传入有误！");
	}
	pNode pTmp = ph->next;
	while (pTmp->next != NULL)
	{
		pTmp = pTmp->next;  //先将指针pTmp移动到末尾结点
	}
	for (int i = --ph->length; i >= 0; i--) //从末尾结点向前打印元素
	{
		printf("%d  ", pTmp->data);
		pTmp = pTmp->pre;
	}
	printf("\n");
}
