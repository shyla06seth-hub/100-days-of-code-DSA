//Deque (Double-Ended Queue)

#include <stdio.h>
#include <string.h>

#define MAX 100

int deque[MAX];
int front = -1, rear = -1;

void push_front(int x){
    if(front == -1){
        front = rear = 0;
    }
    else if(front == 0){
        printf("Overflow\n");
        return;
    }
    else{
        front--;
    }
    deque[front] = x;
}

void push_back(int x){
    if(rear == MAX-1){
        printf("Overflow\n");
        return;
    }
    if(front == -1){
        front = rear = 0;
    }
    else{
        rear++;
    }
    deque[rear] = x;
}

void pop_front(){
    if(front == -1){
        printf("Deque Empty\n");
        return;
    }

    printf("%d\n", deque[front]);

    if(front == rear){
        front = rear = -1;
    }
    else{
        front++;
    }
}

void pop_back(){
    if(front == -1){
        printf("Deque Empty\n");
        return;
    }

    printf("%d\n", deque[rear]);

    if(front == rear){
        front = rear = -1;
    }
    else{
        rear--;
    }
}

void get_front(){
    if(front == -1)
        printf("-1\n");
    else
        printf("%d\n", deque[front]);
}

void get_back(){
    if(front == -1)
        printf("-1\n");
    else
        printf("%d\n", deque[rear]);
}

void is_empty(){
    if(front == -1)
        printf("true\n");
    else
        printf("false\n");
}

void get_size(){
    if(front == -1)
        printf("0\n");
    else
        printf("%d\n", rear - front + 1);
}

int main(){
    int n, val;
    char op[20];

    scanf("%d", &n);

    for(int i = 0; i < n; i++){
        scanf("%s", op);

        if(strcmp(op,"push_front")==0){
            scanf("%d",&val);
            push_front(val);
        }
        else if(strcmp(op,"push_back")==0){
            scanf("%d",&val);
            push_back(val);
        }
        else if(strcmp(op,"pop_front")==0){
            pop_front();
        }
        else if(strcmp(op,"pop_back")==0){
            pop_back();
        }
        else if(strcmp(op,"front")==0){
            get_front();
        }
        else if(strcmp(op,"back")==0){
            get_back();
        }
        else if(strcmp(op,"empty")==0){
            is_empty();
        }
        else if(strcmp(op,"size")==0){
            get_size();
        }
    }

    return 0;
}