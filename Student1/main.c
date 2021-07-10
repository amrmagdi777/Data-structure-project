#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Student{
char *name;
int id, day, month, year, lastYearScore;
};

struct Node
{
	struct Student s;
	struct Node* next;
};

void printStudentData(struct Node *node);

struct Node *head,*tail;

int main()
{
    head = NULL;
    tail = NULL;
    generateLinkedList(10, &head, &tail);

    struct Student s1, s2, s3, s4, s5;

    s1.name = "Mohamed";
    s1.id = 9128;
    s1.day = 2;
    s1.month = 3;
    s1.year = 2000;
    s1.lastYearScore = 99;

    s2.name = "Tarek";
    s2.id = 2348;
    s2.day = 19;
    s2.month = 9;
    s2.year = 2000;
    s2.lastYearScore = 91;

    s3.name = "Abdallah";
    s3.id = 8721;
    s3.day = 12;
    s3.month = 5;
    s3.year = 1999;
    s3.lastYearScore = 90;

    s4.name = "Kamel";
    s4.id = 3902;
    s4.day = 4;
    s4.month = 4;
    s4.year = 1994;
    s4.lastYearScore = 94;

    s5.name = "Aly";
    s5.id = 1224;
    s5.day = 10;
    s5.month = 2;
    s5.year = 1992;
    s5.lastYearScore = 80;

    pushStudent(s1);
    appendStudent(s2);
    insertMiddle(s3, 4);
    pushStudent(s4);
    insertMiddle(s5, 1);

    printList(head);

    return 0;
}

void pushStudent(struct Student student){
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
	newNode->s = student;
if(head == NULL){ // if linked list is empty, put newStudent in the head
    head = newNode;
    newNode->next = NULL;
    printf("linked list is empty... creating a new one");
    return;
}
newNode->next = head;
head = newNode;
}

void appendStudent(struct Student newStudent){
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
	newNode->s = newStudent;
if(head == NULL){ // if linked list is empty, put newStudent in the head
    head = newNode;
    newNode->next = NULL;
    printf("linked list is empty... creating a new one");
    return;
}
tail->next = newNode;
newNode->next = NULL;
tail = newNode;
}

void insertMiddle(struct Student newStudent, int pos){
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
	newNode->s = newStudent;

 struct Node* temp = head;
 for (int i = 1; i < pos; i++)
        temp = temp->next;

newNode->next = temp->next;
 temp->next = newNode;

}

/*
//getting size of the linked list
int size = 1;
struct Student *temp = linkedListHeadRef;
while( temp->nextAddress != NULL){
        size++;
        temp = temp->nextAddress;
}
    int index = (size / 2) - 1; // we will put the student after that index
 printf("size: %d\n", size);

 */


struct Node* createStudent(){
struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
temp->s.name = "tarek";
temp->s.id = 37;
temp->s.day = 5;
temp->s.month = 4;
temp->s.year = 2000;
temp->s.lastYearScore = 98;

return temp;
}

void generateLinkedList(int size){
struct Node *current, *next;
current = createStudent();
current->s.id = 0;
head = current;
for(int i = 1; i < size; i++){
    next = createStudent();
    next->s.id = i;
    current->next = next;
    current = next;
}
tail = next;
tail->next = NULL;
}
void printStudentData(struct Node* node)
{
            printf(" \n Id is: %d \n", node->s.id);
            printf(" Name is: %s \n", node->s.name);
            printf(" Address of struct is: %d \n", node);
            printf(" Address of next struct is: %d \n", node->next);
}

void printList(){
struct Node *node = head;
while(node != NULL){
            printf(" \n Id is: %d \n", node->s.id);
            printf(" Name is: %s \n", node->s.name);
            printf(" Address of struct is: %d \n", node);
            printf(" Address of next struct is: %d \n", node->next);
            node = node->next;
}
}
