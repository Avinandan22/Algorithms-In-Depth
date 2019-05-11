#include<stdio.h>
#include<stdlib.h>
struct Node
{
	float imp;
	struct Node * next;
	struct Node * prev;
};
struct database 
{
	int count;
	struct Node ** implist;
	struct Node ** lastnode;
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

	int N = 3;
	//N denotes number of organizations
	struct database data[N];
	for(int i = 0;i < N;i++)
	{
		struct Node** org;
	    org = (struct Node **) malloc (sizeof (struct Node*));
	    struct Node ** tail;
		tail = (struct Node **)malloc(sizeof (struct Node*));
		((data[i])).lastnode = tail;
		((data[i])).implist = org;
		((data[i])).count = 0;
	}
	//len denotes number of total entries
	int len = 6,orgidx,sh,sm,fh,fm;
	float val;
	//taking and storing data
	for(int i = 0;i < len;i++)
	{
		scanf("%d %d:%d-%d:%d %f",&orgidx,&sh,&sm,&fh,&fm,&val);
		struct Node * new;
		new = (struct Node *)malloc(sizeof(struct Node));
		if(data[orgidx - 1].count == 0)
		{
			*(data[orgidx - 1].implist) = new;
			*(data[orgidx - 1].lastnode) = new;
		}
		new->imp = val;
		new->prev = *(data[orgidx - 1].lastnode);
		new->next = NULL;
		(*(data[orgidx - 1].lastnode))->next = new;
		*(data[orgidx - 1].lastnode) = new;
		data[orgidx - 1].count = data[orgidx - 1].count + 1;
	}
	//sorting and printing data
	struct Node ** counter;
	counter = (struct Node **)malloc(sizeof (struct Node*));
	for(int j = 0;j < N;j++)
	{
		printf("%d ",j + 1);
		mergesort(data[j].implist,data[j].count);
		*counter = *(data[j].implist); 
		for(int i = 0;i < data[j].count;i++)
		{
			printf("%.3f ",(*counter)->imp);
			*counter = (*counter)->next;
		}
		printf("\n");
	}
	return 0;
}