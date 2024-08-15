#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    struct Node *next;
    int data;
} Node;

Node *head = NULL;

void printMenu() {
    printf("You have the following options:\n");
    printf("\t1. Add a node to the list\n");
    printf("\t2. Remove a node from the list\n");
    printf("\t3. Insert a node into the list\n");
    printf("\t4. Print the list\n");
    printf("\t5. Reverse the list\n");
    printf("\t6. Quit\n");
}

// add node to list
Node *addNode(int data) {
    Node *newNode = malloc(sizeof(Node));
    if (newNode == NULL) {
            return NULL;
        }
    newNode->data = data;
    newNode->next = NULL;
    if (head == NULL) {
        head = newNode;
    }
    else {
        Node *current = head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newNode;
    }
    return newNode;
}

// remove node from list
int removeNode(int data) {
    Node *current = head;
    Node *prev = NULL;
    while (current != NULL) {
        if (current->data == data) {
            // if current node is the head
            if (current == head) {
                head = current->next;
            }
            else {
                prev->next = current->next;
                free(current);
            }
            current = NULL;
            return 1;
        }
        prev = current;
        current = current->next;
    }
    return 0;
}

// insert node into a position in list
Node *insertNode(int data, int position) {
    if (position == 0) {
        Node *newNode = malloc(sizeof(Node));
        if (newNode == NULL) {
            return NULL;
        }
        newNode->data = data;
        newNode->next = head;
        head = newNode;
        return newNode;
    }
    
    Node *current = head;
    while (current != NULL && position > 1) {
        current = current->next;
        position--;
    }
    if (current == NULL || position > 1) {
        printf("The requested position is too far into the list\n");
        return NULL;
    }

    Node *newNode = malloc(sizeof(Node));
    if (newNode == NULL) {
        return NULL;
    }
    newNode->data = data;
    newNode->next = current->next;
    current->next = newNode;

    return newNode;
}

// print list
void printList() {
    Node *current = head;
    while (current != NULL) {
        printf("%d", current->data);
        if (current->next != NULL) {
            printf("->");
        }
        current = current->next;
    }
    printf("\n");
    return;
}

Node *reverseList(Node* head) {
    Node *current = head;
    Node *prev = NULL;
    Node *next;
    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    return prev;
}

int main(int argc, char **argv) {
    int option = -1;
    int userIn = 0;
    int userIn2 = 0;
    while (option != 6) {
        printMenu();
        int num_received = scanf("%d", &option);
        if (num_received == 1 && option > 0 && option <= 6) {
            switch(option) {
                case 1:
                    // add function
                    printf("What data should I insert?\n");
                    scanf("%d", &userIn);
                    Node *new = addNode(userIn);
                    break;
                case 2:
                    // remove function
                    printf("What node should I remove?\n");
                    scanf("%d", &userIn);
                    int success = removeNode(userIn);
                    if (!success) {
                        printf("Could not find the node to remove.\n");
                    }
                    break;
                case 3:
                    // insert function
                    printf("What data should I insert?\n");
                    scanf("%d", &userIn);
                    printf("What position should I insert at?\n");
                    scanf("%d", &userIn2);
                    Node *newNode = insertNode(userIn, userIn2);
                    if (newNode == NULL) {
                        printf("Could not insert into list.");
                    }
                    break;
                case 4:
                    printList();
                    break;
                case 5:
                // reverse function
                    head = reverseList(head);
                    printf("The linked list has been reversed.\n");
                    printList();
                    break;
                case 6:
                    break;
            }
        }
    }
    return 0;
}
