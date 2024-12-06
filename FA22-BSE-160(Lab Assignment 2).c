#include <stdio.h>
#include <stdlib.h>

struct Node {
    int info;
    struct Node* next;
};

struct Node *list1 = NULL;
struct Node *list2 = NULL;
struct Node *mergedList = NULL;

void createList(struct Node** list, int x) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->info = x;
    newNode->next = NULL;

    if (*list == NULL) {
        *list = newNode;
    } else {
        struct Node* temp = *list;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

void mergeListsAtAlternatePositions() {
    struct Node* P1 = list1;
    struct Node* P2 = list2;
    struct Node* q1, *q2;

    while (P1 != NULL && P2 != NULL) {
        q1 = P1->next;
        q2 = P2->next;
        P2->next = q1;
        P1->next = P2;
        P1 = q1;
        P2 = q2;
    }

    list2 = P2;
}

void displayList(struct Node* list) {
    struct Node* currentNode = list;
    while (currentNode != NULL) {
        printf("%d ", currentNode->info);
        currentNode = currentNode->next;
    }
}

int main() {
    int choice;
    int value;

    do {
        printf("\nEnter your choice\n");
        printf("Press 1 to enter data in list 1\n");
        printf("Press 2 to enter data in list 2\n");
        printf("Press 3 to merge at alternate positions\n");
        printf("Press 4 to exit\n");
        printf("Your Choice : ");
        scanf("%d", &choice);

        switch (choice) {

        case 1:
            printf("Enter value for list 1: ");
            scanf("%d", &value);
            createList(&list1, value);
            break;

        case 2:
            printf("Enter value for list 2: ");
            scanf("%d", &value);
            createList(&list2, value);
            break;

        case 3:
            printf("\n\nFirst list elements are:\n");
            displayList(list1);

            printf("\n\nSecond list elements are:\n");
            displayList(list2);

            mergeListsAtAlternatePositions();

            printf("\n\nModified  1st list elements are:\n");
            displayList(list1);

            printf("\n\nModified 2nd  list elements are:\n");
            displayList(list2);

            break;

      case 0:
            printf("Exit\n");
            break;

        default:
            printf("Invalid choice\n");
        }
    } while (choice != 0);

    return 0;
}
