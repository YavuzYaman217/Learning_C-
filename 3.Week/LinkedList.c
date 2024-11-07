#include   <stdio.h>
#include   <stdlib.h>

struct Node{
    int x;
    struct Node *next;
};

struct Node *createNode(int value){
    struct Node *create_Node = (struct Node*)malloc(sizeof(struct Node));
    create_Node->x = value;
    create_Node->next = NULL;
    return create_Node;
}

void deAllocate(struct Node **root){
    struct Node *curr = *root;
    while(curr != NULL){
        struct Node *aux = curr;
        curr = curr->next;
        free(aux);
    }
    *root = NULL;
}

void insert_end(struct Node **head,int value){
    struct Node *new_Node = createNode(value);
    if(*head == NULL){
        *head = new_Node;
        return;
    }

    struct Node *curr = *head;
    while(curr->next != NULL){
        curr = curr->next;
    }
    curr->next = new_Node;
}

void insertBeginning(struct Node **head,int value){
   struct Node *new_Node = createNode(value);
   new_Node->next = *head;
   *head = new_Node;
}

void ListRemove(struct Node **head,int value){

    struct Node *current = *head;
    struct Node *aux = NULL;
    while(current != NULL){
        if(current->x == value){
                if(aux == NULL){
                    *head = current->next;
                }else{

                    aux->next = current->next;
                }
        }
        aux = current;
        current = current->next;

    }
}
void Replace_Element(struct Node **head,int b,int a){
    struct Node *curr = *head;
    int Boolean = 0;
    while(curr != NULL){
        if(curr->x == b){
            curr->x = a;
            Boolean = 1;
        }
        curr = curr->next;
    }

    (Boolean == 1)? printf("The number you want to change is found : %d \n", b): printf("The number you want to change could not find : %d \n", b);

}

void insert_after(struct Node *node,int value){
    struct Node *new_node = createNode(value);
    if(new_node == NULL){
        return;
    }
    new_node->next = node->next;
    node->next = new_node;
}

void Insert_Sorted(struct Node **head,int value){
    if(*head == NULL || (*head)->x >= value){
        insertBeginning(head,value);
        return;
    }

    struct Node *current = *head;
    while(current->next != NULL){
        if(current->next->x >= value){
            /*
            insert_after(head,value);
            return;
            */
            break;
        }
        current = current->next;
    }
    insert_after(*head,value);
}

void Sorted_list(struct Node **head){
    if(*head == NULL) return;
    struct Node *current;
    struct Node *next_node = NULL;
    int swapped;
    do{
        swapped = 0;
        current = *head;
        while(current->next != next_node){
         if(current->x > current->next->x){
                 int temp = current->x;
                current->x = current->next->x;
                current->next->x = temp;
                swapped = 1;
            }
            current = current->next;
        }
        next_node = current;
    }while(swapped);
}

void Display(struct Node *head){
    struct Node *current = head;
    while(current != NULL){
            printf("%d \n",current->x);
            current = current->next;
    }
    if(current == NULL){
        printf("NULL");
    }
}

void removeElements(struct Node** head, int val) {
    struct Node *dummy = (struct Node*)malloc(sizeof(struct Node));
    dummy->next = *head;
    struct Node* current = dummy;
    while (current->next != NULL) {
        if (current->next->x == val) {
            current->next = current->next->next;
        } else {
            current = current->next;
        }
    }
    *head = dummy->next;
    free(dummy);
}


int main(){
    struct Node *root = NULL;
    insert_end(&root,17);
    insert_end(&root,17);
    insert_end(&root,18);
    insert_end(&root,17);
    insert_end(&root,16);
    removeElements(&root,17);
    //Insert_Sorted(&root,17);
    //Sorted_list(&root);
    //ListRemove(&root,15);
    //Replace_Element(&root,15,17);
    Display(root);
    deAllocate(&root);
    return 0;
}
