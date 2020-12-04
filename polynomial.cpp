#include<stdio.h>
#include<stdlib.h>
struct poly
{
	int coeff;
	int exp;
	struct poly *link;
};
struct poly* create1(struct poly *start1,int n1);
struct poly* create2(struct poly *start2,int n2);
void display(struct poly *start3);
struct poly* add(struct poly *start1,struct poly *start2,struct poly *start3);
main()
{
	struct poly *start1,*start2,*start3;
	start1=start2=start3=NULL;
	int n1,n2;
	printf("Enter the number of element in the first polynomial");
	scanf("%d",&n1);
	printf("Enter the number of element in the second polynomial");
	scanf("%d",&n2);
	start1=create1(start1,n1);
	start2=create2(start2,n2);
	start3=add(start1,start2,start3);
	display(start3);
}
struct poly* create1(struct poly *start1,int n1)
{
	struct poly *tail1=NULL;
	int i;
	printf("Enter elements of the first polynomial-");
	for(i=0;i<n1;i++)
	{
	struct poly *temp=(struct poly*)malloc(sizeof(struct poly));
	scanf("%d",&temp->coeff);
	scanf("%d",&temp->exp);
	temp->link=NULL;
	if(start1==NULL)
	{
		start1=tail1=temp;
	}
	else
	{
	tail1->link=temp;
	tail1=temp;
	}
}
	return start1;
}
struct poly* create2(struct poly *start2,int n2)
{
	struct poly *tail2=NULL;
	int i;
	printf("Enter elements of the second polynomial-");
	for(i=0;i<n2;i++)
	{
	struct poly *temp=(struct poly*)malloc(sizeof(struct poly));
	scanf("%d",&temp->coeff);
	scanf("%d",&temp->exp);
	temp->link=NULL;
	if(start2==NULL)
	{
		start2=tail2=temp;
	}
	else
	{
	    tail2->link=temp;
	    tail2=temp;
	}
}
	return start2;
}
struct poly* add(struct poly *start1,struct poly *start2,struct poly *start3)
{
	struct poly *tail3;
	tail3=NULL;
	while(start2!=NULL && start1!=NULL)
	{
	struct poly *p=(struct poly*)malloc(sizeof(struct poly));
	p->link=NULL;
		if(start1->exp>start2->exp)
		{
			p->coeff=start1->coeff;
			p->exp=start1->exp;
			start1=start1->link;
		}
		else if(start2->exp>start1->exp)
		{
			p->coeff=start2->coeff;
			p->exp=start2->exp;
			start2=start2->link;
		}
		else
		{
			p->coeff=start1->coeff+start2->coeff;
			p->exp=start1->exp;
			start1=start1->link;
			start2=start2->link;
		}
		if(start3==NULL)
		start3=tail3=p;
		else
		{
		tail3->link=p;
		tail3=p;
	}
		
	}
	if(start1==NULL)
	tail3->link=start2;
	else if(start2==NULL)
	tail3->link=start1;
	return start3;
}
void display(struct poly *start3)
{
	struct poly *t=start3;
	while(t!=NULL)
	{
		printf("%dx^%d",t->coeff,t->exp);
		if(t->link!=NULL)
		printf("+");
		t=t->link;	
	}
	printf("\n");
}
