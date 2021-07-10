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


void insert_first(struct Student* array,int n,struct Student w){
    n=n+1;
    realloc(array,sizeof(struct Student) * (n));
    int i;
    for ( i =n-1 ;i>0;i--){
        array[i]=array[i-1];
    }
    array[i]=w;
}

void insert_last(struct Student* array,int n,struct Student w){
     n=n+1;
    realloc(array,sizeof(struct Student) * (n));
    array[n-1]=w;
}

void insert_mid(struct Student* array,int  n,struct Student w,int mid){
    n=n+1;
    realloc(array,sizeof(struct Student) * (n));
    int i;
    for ( i =n-1 ;i > mid;i--)
        {
        array[i]=array[i-1];
    }
    array[i]=w;
}

void printStudentData(struct Node *node);

struct Node *head,*tail;

int main()
{
    int k;
    int n;
    int x;
    int ch;
    struct Student w1,w2,w3,w4;
    printf("For Array Press 1\n");
     printf("For LinkedList Press 2\n");
   scanf("%i",&ch);
if (ch==1)
{


    w1.name ="mohamed";
    w1.id = 36;
    w1.day=1;
    w1.month=3;
    w1.year=12;
    w1.lastYearScore=55;

   w2.name ="tarek";
    w2.id = 362;
    w2.day=12;
    w2.month=32;
    w2.year=122;
    w2.lastYearScore=552;
    w3.name ="amr";
    w3.id = 363;
    w3.day=13;
    w3.month=33;
    w3.year=123;
    w3.lastYearScore=553;
    w4.name ="magdy";
    w4.id = 364;
    w4.day=14;
    w4.month=34;
    w4.year=124;
    w4.lastYearScore=554;
    printf("Insert The size of array\n");
    scanf("%d",&n);

    struct Student* array = (struct Student*)malloc(sizeof(struct Student) * n);

     int i;
     for( i =0;i<n;i++){
         array[i]=w1;
    }
    printf("To Insert First Press 1\n");
    printf("To Insert Mid Press 2\n");
    printf("To Insert last Press 3\n");
    scanf("%i",&k);
  if(k==1)

        {insert_first(array,n,w2);
    n=n+1;}
    else if (k==2)
    {printf("insert a number between 1 and %i\n",n);
    scanf("%d" ,&x);
    if (x<=0 || x>n)
         printf("wrong number\n The old List \n");
insert_mid(array,n,w2,x-1);
    n++;}

   else if (k==3)
    {insert_last(array,n,w2);
    n++;}

    else
        printf("wrong number\n");

     for(int i =0;i<n;i++){
              printf("Student%d:\n",i+1);
         printf("Student%d Name: %s\n",i+1,array[i].name);
         printf("Student%d ID: %d\n",i+1,array[i].id);
         printf("Student%d BirthDay: %d / %d / %d\n",i+1,array[i].day,array[i].month,array[i].year);
         printf("Student%d Last Year score: %d\n",i+1,array[i].lastYearScore);
         printf("__________________________________\n");
    }

 return 0;}
     else if (ch==2)
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
 } else  {printf("Wrong Number");

    return 0;
}
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
