#include <stdio.h>
#include <stdlib.h>

struct ListNode{
    int val;
    struct ListNode *next;
};

struct ListNode *createNode(int val){
    struct ListNode *new_node = (struct ListNode*)malloc(sizeof(struct ListNode));
    new_node->val = val;
    new_node->next = NULL;
    return new_node;

}


void insert_end(struct ListNode **head,int value){
    struct ListNode *new_Node = createNode(value);
    if(*head == NULL){
        *head = new_Node;
        return;
    }

    struct ListNode *curr = *head;
    while(curr->next != NULL){
        curr = curr->next;
    }
    curr->next = new_Node;
}



void deAllocate(struct ListNode **root){
    struct ListNode *curr = *root;
    while(curr != NULL){
        struct ListNode *aux = curr;
        curr = curr->next;
        free(aux);
    }
    *root = NULL;
}


void Display(struct ListNode *head){
    struct ListNode *current = head;
    while(current != NULL){
            printf("%d \n",current->val);
            current = current->next;
    }
    if(current == NULL){
        printf("NULL");
    }
}

void Reverse_List(struct ListNode **head){
        struct ListNode *current = *head;
        int count = 0,i = 0;
        while(current != NULL){
            count++;
            current = current->next;
        }
        current = *head;
        int *Arr = (int*)malloc(count*sizeof(int));
        while(current != NULL){
            Arr[i++] = current->val;
            current = current->next;
        }
        current = *head;
        for(int i = count-1;i>=0;i--){
           current->val = Arr[i];
           current = current->next;
        }
        free(Arr);
}

struct ListNode *reverseList (struct ListNode* head) {
    struct ListNode *current = head;
        int count = 0,i = 0;
        while(current != NULL){
            count++;
            current = current->next;
        }
        current = head;
        int *Arr = (int*)malloc(count*sizeof(int));
        while(current != NULL){
            Arr[i++] = current->val;
            current = current->next;
        }
        current = head;
        for(int i = count-1;i>=0;i--){
           current->val = Arr[i];
           current = current->next;
        }
        free(Arr);
}


int main(){
    struct ListNode *root = NULL;
    insert_end(&root,0);
    insert_end(&root,1);
    insert_end(&root,4);
    insert_end(&root,-2);
    reverseList(root);
    Display(root);
    deAllocate(&root);

}
