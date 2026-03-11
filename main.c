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

// clear all list
void clear_list(struct Node** head){
    if (*head == NULL){
        puts("List has already cleared!");
        return;
    }
    while (*head != NULL){
        pop_front(head); 
    }
}


// func makes bubble sort of list
void sort_list(struct Node** head, int (*cmp_func)(void*, void*)){

    struct Node* start = *head;
    struct Node* temp_head = *head;

    if (temp_head == NULL) return;

    int swapped = 0;

    while(1){

        if (temp_head->next_node == NULL && swapped == 0){
            return;
        }
        else if (temp_head->next_node == NULL && swapped != 0){
            temp_head = start;
            swapped = 0;
            continue;
        }


        void* first_elem = temp_head->value;
        void* second_elem = temp_head->next_node->value;
        
        if (cmp_func(first_elem, second_elem) == 1){
            temp_head->next_node->value = first_elem;
            temp_head->value = second_elem;
            swapped++;
        }

        temp_head = temp_head->next_node;
    }
}

void print_list(struct Node* head, void (*print_func)(void*)){
    printf("[ ");
    struct Node* tmp = head;
    while (tmp != NULL){
        print_func(tmp->value);
        tmp = tmp->next_node;
    }
    printf("]\n");
}

void print_int(void* data){
    int v = *(int*)data;
    printf("%d ", v);
}

void print_str(void* data){
    char* string = (char*)data;
    printf("%s ", string);
}

int q_func_int(void* f, void* s){
    
    int value1 = *(int*)f;
    int value2 = *(int*)s;

    if (value1 > value2) return 1;
    else 0;
}

int q_func_str(void* f, void* s){
    
    char* str1 = (char*)f;
    char* str2 = (char*)s;

    if (str1[0] > str2[0]) return 1;
    else 0;
}


int main(){
    
    int elem1 = 100;
    int elem2 = -100;
    int elem3 = 200;
    
    struct Node* HEAD = NULL;

    add_value(&elem1, &HEAD);
    add_value(&elem2, &HEAD);
    add_value(&elem3, &HEAD);

    print_list(HEAD, print_int); // [ 200 -100 100 ]

    sort_list(&HEAD, q_func_int);

    print_list(HEAD, print_int); // [ -100 100 200 ]
    
    pop_front(&HEAD);

    print_list(HEAD, print_int); // [ 100 200 ]
    
    clear_list(&HEAD);

    print_list(HEAD, print_int);

    char st1[10] = "C Hello";
    char st2[10] = "A my";
    char st3[10] = "B world!";
    
    add_value(st3, &HEAD);
    add_value(st2, &HEAD);
    add_value(st1, &HEAD);
    
    print_list(HEAD, print_str); // [ C Hello A my B world! ]

    sort_list(&HEAD, q_func_str);
    
    print_list(HEAD, print_str); // [ A my B world! C Hello ]
    
    clear_list(&HEAD);
    
    pop_front(&HEAD); // List is empty!


    return 0;
}
