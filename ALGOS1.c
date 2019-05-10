#include<stdio.h>
#include<stdlib.h>
struct Node
{
	int imp;
	struct Node * next;
	struct Node * prev;
};

void mergesort(struct Node ** org,int len)
{
	struct Node ** p1;
	struct Node ** p2;
	struct Node ** start;
	struct Node ** temp;
	p1 = (struct Node **)malloc(sizeof(struct Node*));
	p2 = (struct Node **)malloc(sizeof(struct Node*));
	start = (struct Node **)malloc(sizeof(struct Node*));
	temp = (struct Node **)malloc(sizeof(struct Node*));
	int first,second,total,check,reach;
	for(int i = 1;i < len;i *= 2)
	{
		*start = *org;
		check = 0;
		while(check < len)
		{	
			first = 0;
			second = 0;
			total = 0;
			reach = 0;
			*p1 = *start;
			*p2 = *start;
			while(reach < i && *p2)
			{
				*p2 = (*p2)->next;
				reach++;
			}
			reach = 0;
			while(reach < 2 * i && *start)
			{
				*start = (*start)->next;
				reach++;
			}
			//merge
			if(*p2 != NULL)
			{
				while(total < 2 * i && first < i && second < i && *p1 && *p2)
				{
					if((*p1)->imp <= (*p2)->imp)
					{
						*p1 = (*p1)->next;
						first++;
						total++;
					}
					else
					{
						*temp = (*p2)->next;
						//changing add of node before p2
						((*p2)->prev)->next = (*p2)->next;
						//changing node after p2
						//if p2 is the last node then ignore
						if((*p2)->next != NULL)
							((*p2)->next)->prev = (*p2)->prev;
						//establishing link of node before p1 and between p2
						//if p1 is the first node go to else
						if((*p1)->prev != (*p1))
						{
							((*p1)->prev)->next = *p2;
							(*p2)->prev = (*p1)->prev;
						}
						else
						{
							(*p2)->prev = *p2;
							*org = *p2;
						}
						//establishing link between nodes p1 and p2
						(*p2)->next = *p1;
						(*p1)->prev = *p2;
						//updating p2
						*p2 = *temp;
						second++;
						total++;
					}
				}
			}
			check += 2 * i;
		}
	}
}
int main()
{
	struct Node** org;
	org = (struct Node **) malloc (sizeof (struct Node*));
	struct Node ** tail;
	tail = (struct Node **)malloc(sizeof (struct Node*));
	int len = 5,val;
	for(int i = 0;i < len;i++)
	{
		scanf("%d",&val);
		struct Node * new;
		new = (struct Node *)malloc(sizeof(struct Node));
		if(!i)
			*org = new,*tail = new;
		new->imp = val;
		new->prev = *tail;
		new->next = NULL;
		(*tail)->next = new;
		*tail = new;
	}
	struct Node ** counter;
	counter = (struct Node **)malloc(sizeof (struct Node*));
	mergesort(org,len);
	*counter = *org; 
	for(int i = 0;i < len;i++)
	{
		printf("%d\n",(*counter)->imp);
		*counter = (*counter)->next;
	}
	return 0;
}