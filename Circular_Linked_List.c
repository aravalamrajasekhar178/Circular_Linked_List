#include<stdio.h>
#include<stdlib.h>
struct Node{
    int data;
    struct Node* next;
};
struct Node* head=NULL;

// Creating the Node
struct Node* create(int val){
    struct Node* node=(struct Node*)malloc(sizeof(struct Node));
    node->data=val;
    if(head==NULL){
        node->next=node;
    }else{
        node->next=head;
    }
    return node;
}

// Inserting the node at beginning of Circular Linked List
void insert_at_begin(int val){
    if(head==NULL){
        head=create(val);
    }else{
        struct Node* temp1=create(val);
        struct Node* temp2=head;
        while(temp2->next!=head){
            temp2=temp2->next;
        }
        temp2->next=temp1;
        temp1->next=head;
        head=temp1;
    }
    printf("Node successfully inserted\n");
}

// Inserting the node at the end in Circular Linked List
void insert_at_end(int val){
    if(head==NULL){
        head=create(val);
    }else{
    struct Node* temp1=head;
    struct Node* temp2=create(val);
    while(temp1->next!=head){
        temp1=temp1->next;
    }
    temp1->next=temp2;
    }
    printf("Node successfully inserted\n");
}

// Inserting the node after specified position in Circular Linked List
void insert_after_somePosition(int val,int loc){
    struct Node* temp1=create(val);
    struct Node* temp2=head;
    for(int i=0;i<loc-1;i++){
        temp2=temp2->next;
        if(temp2==head){
            printf("Node can't be inserted in specified position\n");
            return;
        }
    }
    struct Node* temp3=temp2->next;
    temp2->next=temp1;
    temp1->next=temp3;
    printf("Node successfully Inserted\n");
    return;
}

// Deleting the first element of Circular Linked List
void delete_at_begin(){
    if(head==NULL){
        printf("Node can't be deleted from beginning because circular linked list is empty\n");
        return;
    }
    if(head->next==head){
        struct Node* temp=head;
        head=NULL;
        free(temp);  // free() method is used to deallocate the dynamically allocated memory to the node and helps in reducing the memory wastage
        printf("Node successfully deleted\n");
        return;
    }
    struct Node* temp1=head->next;
    struct Node* temp2=head;
    struct Node* temp3=head;
    while(temp3->next!=head){
        temp3=temp3->next;
    }
    temp3->next=temp1;
    head=temp1;
    free(temp2); // free() method is used to deallocate the dynamically allocated memory to the node and helps in reducing the memoruy wastage
    printf("Node successfully deleted\n");
    return;
}

// Deleting the last node of the Circular Linked List
void delete_at_end(){
    if(head==NULL){
        printf("Node can't be deleted from end because circular linked list is empty\n");
        return;
    }
    if(head->next==head){
        struct Node* temp=head;
        free(temp);  // free method is used to deallocate the dynamically allocated memmory to the node and helps in reducing the memory wastage
        printf("Node successfully deleted\n");
        return;
    }
    struct Node* slow=head;
    struct Node* fast=head->next;
    while(fast->next!=head){
        fast=fast->next;
        slow=slow->next;
    }
    struct Node* temp=fast;
    slow->next=fast->next;
    free(temp);  //free() method is used to deallocate the dynamically allocated memory to the node and helps in reducing the memory wastage
    printf("Node successfully deleted\n");
}

// Deleting an element in the Circular Linked List after the specified position
void delete_after_somePosition(int loc){
    if(head==NULL){
        printf("Node can't be deleted after the specified location because circular linked list is empty\n");
        return;
    }
    if(head->next==head){
        printf("Node can't be deleted after the specified location\n");
        return;
    }
    struct Node* slow=head;
    struct Node* fast=head->next;
    for(int i=0;i<loc-1;i++){
        slow=slow->next;
        fast=fast->next;
        if(slow->next==head){
            printf("Node can't be deleted after the specified location\n");
            return;
        }
    }
    struct Node* temp=fast;
    slow->next=fast->next;
    free(temp);     // free() method is used to deallocate the dynamically allocated memory to the node and helps in reducing the memory wastage
    printf("Node successfully Deleted\n");
    return;
}

//Searching an element in the Circular Linked List
int search_value(int val){
    struct Node* temp=head;
    while(temp->next!=head){
        if(temp->data==val){
            return 1;
        }
        temp=temp->next;
    }
    if(temp->data==val){
        return 1;
    }
    return 0;
}

//Printing the Circular Linked List
void print_LinkedList(){
    struct Node* temp=head;
    if(temp==NULL){
        printf("No Elements Inserted\n");
        return;
    }
    printf("Inserted Circular Linked List Elements:\n");
    while(temp->next!=head){
        printf("%d -> ",temp->data);
        temp=temp->next;
    }
    printf("%d -> %d .....\n",temp->data,temp->next->data);
}
int main(){
    printf("Please select one of the following options:\n");
    printf("1. Insert the Node at beginning\n");
    printf("2. Insert the Node at end\n");
    printf("3. Insert the Node after the specified position\n");
    printf("4. Delete the Node at beginning\n");
    printf("5. Delete the Node at end\n");
    printf("6. Delete the Node after the specified position\n");
    printf("7. Searching the Node\n");
    printf("8. Printing the Node\n");
    printf("other than this: Exit\n");
    printf("----------------------------------\n\n");
    while(1){
    printf("Enter your option :\n");
    int n,num,pos,flag=0;
    scanf("%d",&n);
    switch(n){
        case 1:printf("Enter the number to insert into the node:\n");
               scanf("%d",&num);
               insert_at_begin(num);
               break;
        case 2:printf("Enter the  number to insert into the node:\n");
               scanf("%d",&num);
               insert_at_end(num);
               break;
        case 3:printf("Enter the number to insert into the node:\n");
               scanf("%d",&num);
               printf("Enter the position after which you insert the node:\n");
               scanf("%d",&pos);
               insert_after_somePosition(num,pos);
               break;
        case 4:delete_at_begin();
               break;
        case 5:delete_at_end();
               break;
        case 6:printf("Enter the position after which you are willing to delete the node\n");
            scanf("%d",&pos);
            while(pos<1){
                printf("Enter the position after which you are willing to delete the node\n");
                scanf("%d",&pos);
            }
            delete_after_somePosition(pos);
            break;
        case 7:printf("Enter the Element which you want to search\n");
               int val;
               scanf("%d",&val);
               if(search_value(val)){
                   printf("Element found\n");
               }else{
                   printf("Element not found\n");
               }
               break;
        case 8:print_LinkedList();
               break;
        default:flag=1;
                break;
               
            
    }
    if(flag==1){
        break;
    }
    }
    return 0;
}