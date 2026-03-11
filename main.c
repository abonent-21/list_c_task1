#include <stdio.h>
#include <stdlib.h>

struct Node{
    void* value;
    struct Node* next_node;
};


// add element at start of list
void add_value(void* value, struct Node** head){
    struct Node* new_head = (struct Node*)malloc(sizeof(struct Node));
    new_head->value = value;
    new_head->next_node = *head;
    *head = new_head;
}


// delete head of list
void pop_front(struct Node** head){
    if (*head == NULL){
        puts("List is empty!");
        return;
    }

    struct Node* temp = *head;
    *head = temp->next_node;
    free(temp);
}


// func makes bubble sort of list
void sort_list(struct Node** head, int (*cmp_func)(void* void*)){
    
}

int main(){

    return 0;
}
