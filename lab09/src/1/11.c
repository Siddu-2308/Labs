#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node* next;
} Node;

/* Interactive traversal of linked list */
void interactive(Node* head){
    char op[2];
    if (!head){
        printf("List is empty. Exiting ...\n");
        return;
    }

    Node* ptr = head;
    do {
        printf("Enter d to move ptr the next element or q to quit\n");
        if(ptr){
            printf("ptr is pointing to the element %d\n", ptr->data);
            if(ptr->next){
                printf("Next element is %d\n", ptr->next->data);
            }
        } else {
            printf("ptr is NULL. Press q to exit\n");
        }

        scanf("%s", op);

        switch(op[0]){
            case 'd':
                if(ptr) ptr = ptr->next;
                break;
            case 'q':
                printf("Exiting interactive mode\n");
                break;
            default:
                printf("Invalid option. Valid options are d (forward), q (quit)\n");
                break;
        }
    } while(op[0] != 'q');
}

/* Insert at head */
void insert(Node** ref_to_head, int num){
    Node* new_node = malloc(sizeof(Node));
    if(!new_node) {
        printf("Memory allocation failed!\n");
        return;
    }
    new_node->data = num;
    new_node->next = *ref_to_head;
    *ref_to_head = new_node;
}

/* Search element */
Node* search(Node* head, int num){
    Node* temp = head;
    while(temp){
        if(temp->data == num) return temp;
        temp = temp->next;
    }
    return NULL;
}

/* Delete element */
int delete(Node** ref_to_head, int num){
    Node* temp = *ref_to_head;
    Node* prev = NULL;

    // If head needs to be deleted
    if(temp && temp->data == num){
        *ref_to_head = temp->next;
        free(temp);
        return 1;
    }

    while(temp && temp->data != num){
        prev = temp;
        temp = temp->next;
    }

    if(!temp) return 0; // not found

    prev->next = temp->next;
    free(temp);
    return 1;
}

/* Reverse linked list */
void reverse(Node** ref_to_head){
    Node* prev = NULL;
    Node* curr = *ref_to_head;
    Node* next = NULL;

    while(curr){
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }

    *ref_to_head = prev;
}

/* Print list */
void print(Node* head){
    if(!head){
        printf("-1\n");
        return;
    }
    Node* temp = head;
    while(temp){
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

/* Free memory */
void free_list(Node* head){
    Node* temp;
    while(head){
        temp = head;
        head = head->next;
        free(temp);
    }
}

int main(){
    int num;
    char op[2];
    Node* head = NULL;

    do {
        scanf("%s %d", op, &num);
        switch(op[0]){
            case 'i': insert(&head, num); break;
            case 's': printf("%s\n", search(head, num) ? "True" : "False"); break;
            case 'd': printf("%s\n", delete(&head, num) ? "Deleted" : "Failed"); break;
            case 'r': reverse(&head); break;
            case 'p': print(head); break;
            case 'q': break;
            default: printf("Invalid op %s\n", op); break;
        }
    } while(op[0] != 'q');

    free_list(head);
    return 0;
}
