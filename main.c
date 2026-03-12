#include <stdio.h>
#include <stdlib.h>

struct Node{
    void* value;
    int type_data;
    struct Node* next_node;
};


// add element at start of list
void add_value(void* value, struct Node** head, int type){
    struct Node* new_head = (struct Node*)malloc(sizeof(struct Node));
    new_head->value = value;
    new_head->next_node = *head;
    new_head->type_data = type;
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


int main_menu(){
    puts("Choose option:");
    puts("1) Pop first elem of list");
    puts("2) Clear all list");
    puts("3) Add elems at list");
    puts("4) Print list");
    puts("5) Exit");

    int options;

    while(1){
        printf("Enter:");
    
        int num = scanf("%d", &options);

        if (num == EOF) return 0;
    
        // if input is correct stop infinity loop
        if (num == 1){
            return options;
        }
        else{
            puts("Incorrect input. Enter number 1-4");

            // clear buffer
            int c;
            while ((c = getchar()) != '\n' && c != EOF);
        }

    }

   return 0;
 }


void add_element(){
    
    int type;

    printf("Enter type elem: 1 - INT; 2 - STRING\n");
    print("Enter:");
    
}
   

int main(){
    
    puts("Programm one. Linked list.\n\n");

    struct Node* HEAD = NULL; // pointer to the start of linked list
    
    while(1){
        
        int options = main_menu();

        switch(options){
            case 1:
                pop_front(&HEAD);
            case 2:
                clear_list(&HEAD);
            case 3:
                
            case 4:
            case 5:
                break
        }
    }
    
    return 0;
}
