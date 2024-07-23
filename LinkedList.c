#include <stdio.h>
#include <stdlib.h>

typedef struct {
    void *next;
    int data;
} Node;

Node *head = NULL;
Node *new = NULL;

void printMenu() {
    printf("You have the following options:\n");
    printf("\t1. Add a node to the list\n");
    printf("\t2. Remove a node from the list\n");
    printf("\t3. Insert a node into the list\n");
    printf("\t4. Print the list\n");
    printf("\t5. Quit\n");
}

// add node to list
Node *addNode(int data) {
    if (head == NULL) {
        new = malloc(sizeof(Node));
        if (new == NULL) {
            return NULL;
        }
        new->data = data;
        head = new;
        new->next = NULL;
    }
    else {
        new = malloc(sizeof(Node));
        if (new == NULL) {
            return NULL;
        }
        new->data = data;
        new->next = head;
        head = new;
    }
    return new;
}

// remove node from list
int removeNode(int data) {
    Node *current = head;
    Node *prev = head;
    while (current != NULL) {
        if (current->data == data) {
            // if current node is the head
            if (current == head) {
                head = current->next;
            }
            else {
                prev->next = current->next;
                free(current);
                current = NULL;
            }
            return 1;
        }
        prev = current;
        current = current->next;
    }
    return 0;
}

// insert node into a position in list
Node *insertNode(int data, int position) {
    Node *current = head;
    while (current != NULL && position != 0) {
        position--;
    }
    if (position == 0) {
        printf("Requested position too far into list\n");
        return NULL;
    }
    Node *new = malloc(sizeof(Node));
    if (new == NULL) {
        return NULL;
    }
    new->data = data;
    new->next = current->next;
    current->next = new;
    return new;
}

// print list
void printList() {
    Node *current = head;
    while (current != NULL) {
        printf("%d->", current->data);
        current = current->next;
    }
    printf("\n");
    return;
}

int main(int argc, char **argv) {
    int option = -1;
    int userIn = 0;
    int userIn2 = 0;
    while (option != 5) {
        printMenu();
        int num_received = scanf("%d", &option);
        if (num_received == 1 && option > 0 && option <= 5) {
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
                    break;
            }
        }
    }

    printMenu();
    return 0;
}
