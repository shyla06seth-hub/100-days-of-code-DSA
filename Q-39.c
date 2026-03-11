//Implement a Min Heap using an array where the smallest element is always at the root.

#include <stdio.h>
#include <string.h>

#define MAX 1000

int heap[MAX];
int size = 0;

void swap(int *a, int *b){
    int t = *a;
    *a = *b;
    *b = t;
}

void heapifyUp(int i){
    while(i > 0){
        int parent = (i - 1) / 2;

        if(heap[parent] <= heap[i])
            break;

        swap(&heap[parent], &heap[i]);
        i = parent;
    }
}

void heapifyDown(int i){
    while(1){
        int left = 2*i + 1;
        int right = 2*i + 2;
        int smallest = i;

        if(left < size && heap[left] < heap[smallest])
            smallest = left;

        if(right < size && heap[right] < heap[smallest])
            smallest = right;

        if(smallest == i)
            break;

        swap(&heap[i], &heap[smallest]);
        i = smallest;
    }
}

void insert(int x){
    heap[size] = x;
    heapifyUp(size);
    size++;
}

void extractMin(){
    if(size == 0){
        printf("-1\n");
        return;
    }

    printf("%d\n", heap[0]);

    heap[0] = heap[size - 1];
    size--;

    heapifyDown(0);
}

void peek(){
    if(size == 0)
        printf("-1\n");
    else
        printf("%d\n", heap[0]);
}

int main(){

    int n, val;
    char op[20];

    scanf("%d", &n);

    for(int i = 0; i < n; i++){

        scanf("%s", op);

        if(strcmp(op, "insert") == 0){
            scanf("%d", &val);
            insert(val);
        }

        else if(strcmp(op, "extractMin") == 0){
            extractMin();
        }

        else if(strcmp(op, "peek") == 0){
            peek();
        }
    }

    return 0;
}