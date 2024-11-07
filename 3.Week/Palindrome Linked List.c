#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

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

void Add_elements(struct ListNode **head,int val){
    struct ListNode *new_node = createNode(val);
    if(*head == NULL){
        *head = new_node;
        return;
    }
    struct ListNode *current = *head;
    while (current->next != NULL){
        current = current->next;
    }
    current->next = new_node;
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
        printf("%d\n",current->val);
        current = current->next;
    }

    if(current == NULL){
        printf("NULL");
    }

}

struct ListNode* reverseList(struct ListNode* head) {
    struct ListNode *prev = NULL,*next = NULL;
    while(head != NULL){
        next = head->next;
        head->next = prev;
        prev = head;
        head = next;
    }
    return prev;
}

bool isPalindromeV3(struct ListNode* head) {
    struct ListNode *current = head;
    int count = 0;
    while(current != NULL){
        count++;
        current = current->next;
    }
    current = head;
    int *value = (int*)malloc(count*sizeof(int));
    for(int i  = 0;i<count;i++,current = current->next)
    {
        value[i] = current->val;
    }

    for(int i = 0;i<count/2;i++){
        if(value[i] != value[count-1-i])return false;
    }
    return x;

}


bool isPalindromeV2(struct ListNode* head) {
    if(head == NULL || head->next == NULL) return true;

    struct ListNode *slow = head,*fast = head;

    while(fast != NULL && fast->next != NULL){
        slow = head->next;
        fast = head->next->next;
    }

    struct ListNode *secondHalf = reverseList(slow);
    struct ListNode *firstHalf = head;
    struct ListNode *secondHalfCopy = secondHalf;

    while(secondHalf != NULL){
        if(secondHalf->val != firstHalf->val) return false;
        firstHalf = firstHalf->next;
        secondHalf = secondHalf->next;
    }
    return true;
}



bool isPalindrome(struct ListNode* head) {
    struct ListNode *current = head;
    int i = 0;
    while(current != NULL){
        current = current->next;
        i++;
    }

    current = head;
    int Arr[i];
    i = 0;
    for(current;current!=NULL;current = current->next,i++){
        Arr[i] = current->val;
    }

    for(int j = 0;j<i/2;j++){
        if(Arr[j] != Arr[i-1-j]){
                return false;
        }
    }
    return true;
}


int main(){
    struct ListNode *Root = NULL;
    Add_elements(&Root,1);
    Add_elements(&Root,2);
    Add_elements(&Root,1);
    printf("%d",isPalindromeV3(Root));

}
