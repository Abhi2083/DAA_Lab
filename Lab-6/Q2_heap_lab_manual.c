#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

typedef struct person {
    int id;
    char *name;
    int age;
    int height;
    int weight;
} person;

person *heap[MAX_SIZE];
int heapSize = 0;

void swap(person **a, person **b) {
    person *temp = *a;
    *a = *b;
    *b = temp;
}

void minHeapify(int index) {
    int leftChild = 2 * index + 1;
    int rightChild = 2 * index + 2;
    int smallest = index;

    if (leftChild < heapSize && heap[leftChild]->age < heap[smallest]->age)
        smallest = leftChild;

    if (rightChild < heapSize && heap[rightChild]->age < heap[smallest]->age)
        smallest = rightChild;

    if (smallest != index) {
        swap(&heap[index], &heap[smallest]);
        minHeapify(smallest);
    }
}

void maxHeapify(int index) {
    int leftChild = 2 * index + 1;
    int rightChild = 2 * index + 2;
    int largest = index;

    if (leftChild < heapSize && heap[leftChild]->weight > heap[largest]->weight)
        largest = leftChild;

    if (rightChild < heapSize && heap[rightChild]->weight > heap[largest]->weight)
        largest = rightChild;

    if (largest != index) {
        swap(&heap[index], &heap[largest]);
        maxHeapify(largest);
    }
}

void insertMinHeap(person *p) {
    if (heapSize == MAX_SIZE) {
        printf("Heap is full\n");
        return;
    }

    heap[heapSize] = p;
    int now = heapSize;
    heapSize++;

    while (now > 0 && heap[(now - 1) / 2]->age > heap[now]->age) {
        swap(&heap[(now - 1) / 2], &heap[now]);
        now = (now - 1) / 2;
    }
}

void insertMaxHeap(person *p) {
    if (heapSize == MAX_SIZE) {
        printf("Heap is full\n");
        return;
    }

    heap[heapSize] = p;
    int now = heapSize;
    heapSize++;

    while (now > 0 && heap[(now - 1) / 2]->weight < heap[now]->weight) {
        swap(&heap[(now - 1) / 2], &heap[now]);
        now = (now - 1) / 2;
    }
}

person* deleteMin() {
    if (heapSize == 0) {
        printf("Heap is empty\n");
        return NULL;
    }

    person *minElement = heap[0];
    heap[0] = heap[heapSize - 1];
    heapSize--;
    minHeapify(0);
    
    return minElement;
}

person* deleteMax() {
    if (heapSize == 0) {
        printf("Heap is empty\n");
        return NULL;
    }

    person *maxElement = heap[0];
    heap[0] = heap[heapSize - 1];
    heapSize--;
    
     maxHeapify(0);
    
     return maxElement;
}

void display() {
   for(int i=0;i<heapSize;i++)
   printf("%d %s %d %d %d\n",heap[i]->id,heap[i]->name,heap[i]->age,heap[i]->height,heap[i]->weight);
}

int main() {
   FILE* fp=fopen("data.txt","r");
   char buffer[1024];
   fgets(buffer,1024,fp);
   printf("%s\n", buffer);
   while(fgets(buffer,1024,fp))
   { 
       person* p=(person*)malloc(sizeof(person));
       p->name=(char*)malloc(100*sizeof(char));
       sscanf(buffer,"%d %s %d %d %d",&p->id,p->name,&p->age,&p->height,&p->weight);
       insertMinHeap(p);
   }
   fclose(fp);
   
   while(1)
   { 
       printf("\nMAIN MENU (HEAP)\n");
       printf("1. Read Data\n");
       printf("2. Create a Min-heap based on the age\n");
       printf("3. Create a Max-heap based on the weight\n");
       printf("4. Display weight of the youngest person\n");
       printf("5. Insert a new person into the Min-heap\n");
       printf("6. Delete the oldestperson\n");
       printf("7. Exit\n");
       
       int choice; scanf("%d",&choice);
       
       if(choice==1)
       {
           display();
       }
       else if(choice==2)
       {
           for(int i=heapSize/2-1;i>=0;i--)
           minHeapify(i);
           display();
       }
       else if(choice==3)
       {
           for(int i=heapSize/2-1;i>=0;i--)
           maxHeapify(i);
           display();
       }
       else if(choice==4)
       {
           printf("%d\n",heap[0]->weight);
       }
       else if(choice==5)
       {
           person* p=(person*)malloc(sizeof(person));
           p->name=(char*)malloc(100*sizeof(char));
           printf("Enter the details of the person\n");
           scanf("%d %s %d %d %d",&p->id,p->name,&p->age,&p->height,&p->weight);
           insertMinHeap(p);
       }
       else if(choice==6)
       {
           person* p=deleteMin();
           printf("Deleted person is %d %s %d %d %d\n",p->id,p->name,p->age,p->height,p->weight);
       }
       else
       break;
   }
   
   return 0;
}
