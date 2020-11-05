#include<stdio.h>
#include<stdlib.h>

//made by kunsh manghwani 
//basic of c language circular queue
struct node{
	int a;
	struct node* next;
}*front,*ptr,*tptr,*rear;

void insert(){
	int d;
	if(front== NULL && rear==NULL){
		ptr = (struct node*)malloc(sizeof(struct node));
		printf("\n enter element ");
		scanf("%d",&d);
		ptr->a=d;
		front=ptr;
		rear=front;
		front->next=front;
		return ;
	}
	ptr = (struct node*)malloc(sizeof(struct node));
	printf("\n enter element ");
	scanf("%d",&d);
	ptr->a=d;
	ptr->next=front;
	rear->next=ptr;
	rear=ptr;
	return ;
}

void deletee(){
	if(front==rear){
		ptr=front;
		front=NULL;
		rear=NULL;
		free(ptr);
		return ;
	}
	ptr=front;
	front=front->next;
	free(ptr);
}

void display(){
	tptr=front;
	printf("%d\t ",tptr->a);
	tptr=tptr->next;
	if(front!=rear){
		while(tptr!=front){
			printf("%d\t",tptr->a);
			tptr=tptr->next;
		}	
	}
		
}

int main(){
	int c;
	printf("----------Circular Queue created using linked list---------------\n \n");
	while(1){
		printf("\n1--Insert\n2--Delete\n3--display\n4--exit\nEnter Choice: ");
	scanf("%d",&c);
		if(c==4){
			break;
		}
		switch(c){
			case 1:
				insert();
				break;
			case 2:
				deletee();
				break;
			case 3:
				display();
				break;
			default:
				printf("wrong choice");
		}
	}
	
	return 0;
}
