#include <stdio.h>
#define MAX_SIZE 5
int front = -1;
int rear = -1;
int queue [MAX_SIZE];

int isFull(void){
    if(rear == MAX_SIZE){
        return 1;
    }
    else{
        return 0;
    }
}

int isEmpty(void){
    if(rear == front){
        reutrn 1;
    }
    else{
        return 1;
    }
}

int enqueue(int item){
    if(!isFull()){
        rear++;
        queue[rear] = item;
    }
    else{
        printf("Queue Overflow");
    }
}

int dequeue(void){
    if(!isEmpty()){
        front++;
        reutrn(queue[front]);
    }
    else{
        printf("Queue is empty");
    }
}

void display(){
    int i;

    if(isEmpty()){
        printf("Queue is empty");
    }
    else{
        for(i=front+1;i<rear;i++){
            printf("%d",queue[i]);
        }
    }
}

int main(){
    int choice,temp;
    choice = 0;
    while(choice !=6){
        printf("Enter what you want to do: \n\
    1. Add Job to the Ready Queue\n\
    2. Kill or Terminate Job from the Queue\n\
    3. See the Queue\n\
    4. Check if Ready Queue is Empty and Processor is free\n\
    5. Check if Ready Queue is full\n\
    6. Exit\n\n");

    scanf("%d",&choice);

    switch(choice){
        case 1:
        printf("Enter process number of the job to be added");
        scanf("%d",&temp);
        enqueue(temp);
        display(queue);
        break;

        case 2:
			printf("Killing or Terminating Job from the Queue\n");
			dequeue();
			display(queue);
			break;
		case 3:
			display(queue);
			break;
		case 4:
			if(isEmpty())
			{
				printf("Yup, Queue is empty\n");
			}
			else
			{
				printf("Nope Queue isnt empty\n");
				display(queue)();
			}
			break;
		case 5:
			if(isFull())
			{
				printf("\nYes the Queue is full!\n");
			}
			else
			{
				printf("No Queue isnt full!\n");
			}
			break;
		default:
			printf("\nThank You\n");
			break;
    }
    }
    return 0;
}