#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Student{
    int prn ;
    int marks;
    char name[100];
}

void accept_array(struct Student students[],int number_of_students){
    for(int i=0;i<number_of_students;i++){
        printf("Enter the roll number : ");
        scanf("%d",&students[i].prn);
        printf("Enter marks : ");
        scanf("%d",&students[i].marks);
        printf("Enter name");
        scanf("%s",students[i].name);
    }
}

void display(struct Student students[],int number_of_students,int i){
    for(int i=0;i<number_of_students;i++){
        printf("|\t%d|\t%s|\t%d|\n", students[i].roll_no, students[i].name, students[i].marks);
    }
}

void swap(struct Student *a, struct Student *b){
    struct Student temp = *a;
    *a = *b;
    *b =temp;
}

