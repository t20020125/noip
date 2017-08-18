#include<iostream>
#include<cstdio>
#include<cstring>
#include<map>
#include<vector>
#include<set>
#include<sstream> 
#include<algorithm>
using namespace std;
struct simple_node{
	int value;
	simple_node *next;//结构中可以嵌套其他结构，但是嵌套本结构时，只能用指针 ，否则编译错误 
}; 
simple_node* append(int value)//基本方法，参数（当前值），返回新生成的节点 
{
	simple_node *temp=new simple_node;
	temp->value=value;
	temp->next=NULL;
	return temp;
}
int main()
{
	///////////////////////////////////////////////////////////////////////////////////////
	////////////////////////////////////////链表//////////////////////////////////////////
	///////////////////////////////////////////////////////////////////////////////////////
	//////////////////////////////////////////////////////////////////////////////////////// 
	//简单链表
	//将0到9添加到simple_node型链表中
	simple_node *parent,*head;
	head=parent=append(0); //head一般保持不变，一边以后引用 
	for(int i=1;i<10;i++)
	{
		parent->next= append(i);//返回值就是下一个节点了。
		parent= parent->next; 			
	} 
	
	//遍历
	simple_node *pnode=head;
	while(pnode!=NULL)//0 1 2 .. 9
	{
		cout<<pnode->value<<" ";
		pnode=pnode->next;
	} 
	//插入
	//在3后面插入一个值,0,1,2,3,3,4,5,...9
	pnode=head;
	while(pnode!=NULL)
	{
		if(pnode->value==3)
		{
			simple_node *temp=new simple_node;
			temp->value=3;
			temp->next=pnode->next;
			pnode->next=temp;
			break;		
			
		}
		pnode=pnode->next;
	 } 
	 //删除值为2的节点
	pnode=head;
	//while(pnode!=NULL)
	//{
	//	if(pnode->value==2)
	//	{
			//已经来不及了，2删除了，2下面的节点就找不到父节点了。		
			
	//	}
	//}
	if(head->value==2) head=head->next;
	else
	{
		while(pnode->next!=NULL)
		{
			if(pnode->next->value==2)
			{
				simple_node *temp=pnode->next;
				pnode->next=temp->next;
				delete temp;//回收分配的内存 ，注意delete temp之后，temp就不能再访问了 
				break;
			}
			pnode=pnode->next;
		}
	}
	pnode=head;
	while(pnode!=NULL)//0 1 3 3 4 .. 9
	{
		cout<<pnode->value<<" ";
		pnode=pnode->next;
	 }
	 ///删除链表中的所有元素，释放其所占用内存空间
	 pnode=head;
	 while(pnode!=NULL)
	 {
	 	simple_node *temp=pnode->next;//先保存子节点，否则删除pnode之后，子节点就找不到了 
	 	delete pnode;
	 	pnode=temp;
	  } 
	 ///环形链表，最后一个元素的next==head
	 ///双向链表，定义两个指针，pre和next，pre指向父节点，这样节点删除和移动时方便一些。 
	 
	return 0;
}
