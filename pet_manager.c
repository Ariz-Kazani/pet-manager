#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "pet_manager.h"

/*This program is a pet management system withing a grooming facility.
It uses a linked based data structure for its data storage. it allows the user
to add, delete and print pet records.
*/

// print the pet records
void printRecords(ListNode *head)
{
    ListNode *current = head; // current node
    char choice;              // selection
    while (1)
    {
        printf("a. Print all the cat records.\n");
        printf("b. Print all the dog records.\n");
        printf("c. Print all the pet records.\n");
        printf("e. to exit.\n\n");
        printf("Make a selection: ");
        scanf(" %c", &choice);
        if (choice == 'a' || choice == 'b' || choice == 'c')
            break;
        else if (choice == 'e')
            return;
        else
            printf("I\nnvalid choice.\n");
    }
    printf("\n");
    while (current != NULL)
    {
        // if choice is cat or all print stats
        if ((choice == 'a' || choice == 'c') && current->data->catOrDog == 0)
        {
            printf("Name: %-10s   ", current->data->name);
            printf("Age: %-2d   ", current->data->age);
            printf("Body Color: %-10s   ", current->data->bodyColor);
            printf("Breed: %-20s   ", current->data->cat.breed);
            printf("Eye Color: %-10s   ", current->data->cat.eyeColor);
            printf("Type: Cat");
            printf("\n");
        }
        // if choice is dog or all print stats
        else if ((choice == 'b' || choice == 'c') && current->data->catOrDog == 1)
        {
            printf("Name: %-10s   ", current->data->name);
            printf("Age: %-2d   ", current->data->age);
            printf("Body Color: %-10s   ", current->data->bodyColor);
            printf("Breed: %-20s   ", current->data->dog.breed);
            printf("Tail Type: %-10s   ", current->data->dog.tailType);
            printf("Type: Dog");
            printf("\n");
        }
        current = current->next;
    }
}

// insert new pet record
void insertRecord(ListNode **head)
{
    ListNode *current;
    if (*head == NULL) // if fno pets exist then create the head
    {
        *head = malloc(sizeof(ListNode));
        current = *head;
    }
    else
    {
        current = *head;
        while (current->next != NULL) // find last node
        {
            current = current->next;
        }
        current->next = malloc(sizeof(ListNode)); // allocate memory for new node
        current = current->next;
    }

    current->next = NULL;                    // set next pointer to NULL
    current->data = malloc(sizeof(PetInfo)); // allocate memory for new data
    while (getchar() != '\n')
        ;
    current->data->name = malloc(20 * sizeof(char)); // allocate memory for name
    printf("Enter the name of the pet: ");
    scanf("%19s", current->data->name); // get name
    while (getchar() != '\n')
        ;
    printf("Enter the age of the pet: ");
    scanf("%hhd", &(current->data->age)); // get age
    while (getchar() != '\n')
        ;
    current->data->bodyColor = malloc(10 * sizeof(char)); // allocate memory for body color
    printf("Enter the body color of the pet: ");
    scanf("%9s", current->data->bodyColor); // get body color
    while (getchar() != '\n')
        ;
    while (1) // error checking type of pet
    {
        printf("Enter the type of the pet (0 for cat, 1 for dog): ");
        scanf("%hhd", &(current->data->catOrDog)); // get type
        while (getchar() != '\n')
            ;
        if (current->data->catOrDog == 0 || current->data->catOrDog == 1)
            break;
        else
            printf("Invalid choice.\n");
    }
    if (current->data->catOrDog == 0)
    {
        current->data->cat.breed = malloc(20 * sizeof(char)); // allocate memory for breed
        printf("Enter the breed of the cat: ");
        scanf("%19s", current->data->cat.breed);                 // get breed
        current->data->cat.eyeColor = malloc(10 * sizeof(char)); // allocate memory for eye color
        printf("Enter the eye color of the cat: ");
        scanf("%9s", current->data->cat.eyeColor); // get eye color
    }
    else
    {
        current->data->dog.breed = malloc(20 * sizeof(char)); // allocate memory for breed
        printf("Enter the breed of the dog: ");
        scanf("%19s", current->data->dog.breed);                 // get breed
        current->data->dog.tailType = malloc(10 * sizeof(char)); // allocate memory for tail type
        printf("Enter the tail type of the dog: ");
        scanf("%9s", current->data->dog.tailType); // get tail type
    }
}

// delete pet records based on the name
void deleteRecord(ListNode **head)
{
    ListNode *current = *head; // current node
    ListNode *previous = NULL; // previous node
    char isFirst = 1;
    char name[21]; // name to delete
    while (getchar() != '\n')
        ;
    printf("Enter the name of the pet to remove: ");
    scanf("%20s", name);

    printf("\nRemoving the following pets\n\n");
    while (current != NULL)
    {
        if (strcmp(current->data->name, name) == 0) // if name is found
        {
            // print stats
            printf("Name: %-10s   ", current->data->name);
            printf("Age: %-2d   ", current->data->age);
            printf("Body Color: %-10s   ", current->data->bodyColor);
            if (current->data->catOrDog == 0)
            {
                printf("Breed: %-20s   ", current->data->cat.breed);
                printf("Eye Color: %-10s   ", current->data->cat.eyeColor);
                printf("Type: Cat");
                printf("\n");
            }
            else if (current->data->catOrDog == 1)
            {
                printf("Breed: %-20s   ", current->data->dog.breed);
                printf("Tail Type: %-10s   ", current->data->dog.tailType);
                printf("Type: Dog");
                printf("\n");
            }

            if (isFirst) // if first node
            {
                *head = (*head)->next;
                free(current->data->name);
                free(current->data->bodyColor);
                if (current->data->catOrDog == 0)
                {
                    free(current->data->cat.breed);
                    free(current->data->cat.eyeColor);
                }
                else
                {
                    free(current->data->dog.breed);
                    free(current->data->dog.tailType);
                }
                free(current->data);
                free(current);
                current = *head;
            }

            else // if not first node
            {
                previous->next = current->next;
                free(current->data->name);
                free(current->data->bodyColor);
                if (current->data->catOrDog == 0)
                {
                    free(current->data->cat.breed);
                    free(current->data->cat.eyeColor);
                }
                else
                {
                    free(current->data->dog.breed);
                    free(current->data->dog.tailType);
                }
                free(current->data);
                free(current);
                current = previous->next;
                isFirst = 0;
            }
        }
        else
        {
            previous = current;
            current = current->next;
            isFirst = 0;
        }
    }
    printf("\nRemoved all pets with the name %s\n", name);
}

// menu
void menu(ListNode **head)
{
    int choice; // user choice
    while (1)
    {
        printf("\n");
        printf("1. Print pet records.\n");
        printf("2. Insert new pet record.\n");
        printf("3. Delete pet records based on the name.\n");
        printf("4. Quit.\n");
        printf("\nEnter your choice: ");
        if (scanf("%d", &choice) != 1)
        {
            while (getchar() != '\n')
                ;
            choice = 0;
        }
        printf("\n");

        switch (choice)
        {
        case 1: // print pet records
            printRecords(*head);
            break;
        case 2: // inser new pet record
            insertRecord(head);
            break;
        case 3: // delete pet records based on the name
            deleteRecord(head);
            break;
        case 4: // quit
            char quit[4];
            printf("Are you sure you want to quit? (enter Yes to quit or anything else to not): ");

            if (scanf("%s", quit) == 1 && strcmp(quit, "yes") == 0 || strcmp(quit, "Yes") == 0)
            {
                while (getchar() != '\n')
                    ;
                printf("Quitting...\n");
                return;
            }
            while (getchar() != '\n')
                ;
            break;
        default: // invalid choice
            printf("Invalid choice.\n");
            break;
        }
    }
}

int main(int argc, char *argv[])
{
    int numPets = 0;
    srand(time(NULL));
    // Define some test data
    char *names[] = {"Whiskers", "Mittens", "Shadow", "Mango", "Meowgi", "Buddy", "Bailey", "Cheesebro"};
    char *bodycolor[] = {"Black", "White", "Siamese", "Golden", "Gray"};
    char *catBreeds[] = {"Persian", "Siamese", "Bengal", "Abyssinian", "Ragdoll", "Sphynx"};
    char *catEyeColors[] = {"Yellow", "Green", "Blue", "Amber"};
    char *dogBreeds[] = {"Labrador Retriever", "German Shepherd", "Golden Retriever", "Bulldog", "Beagle", "Poodle", "Dachshund"};
    char *dogTailTypes[] = {"Straight", "Curled", "Docked", "Bobbed"};

    ListNode *head = NULL;
    ListNode *current = head;

    char catOrDog;
    if (argc > 1 && atoi(argv[1]) >= 0)
        numPets += atoi(argv[1]);
    else
    {
        printf("Invalid Arguments\n");
        return 1;
    }

    // Create a linked list of pet info
    for (int i = 0; i < numPets; i++)
    {
        if (i == 0)
        {
            head = malloc(sizeof(ListNode));
            current = head;
        }
        // memory is allocated for the data to make
        // de alocation of pets entered by the user esier
        current->data = malloc(sizeof(PetInfo));
        current->data->name = malloc(20 * sizeof(char));
        strcpy(current->data->name, names[rand() % 8]);
        current->data->age = (rand() % 20) + 1;
        current->data->bodyColor = malloc(10 * sizeof(char));
        strcpy(current->data->bodyColor, bodycolor[rand() % 5]);
        catOrDog = rand() % 2;
        current->data->catOrDog = catOrDog;

        if (catOrDog == 0) // assign cat data
        {
            current->data->cat.breed = malloc(20 * sizeof(char));
            strcpy(current->data->cat.breed, catBreeds[rand() % 6]);
            current->data->cat.eyeColor = malloc(10 * sizeof(char));
            strcpy(current->data->cat.eyeColor, catEyeColors[rand() % 4]);
        }
        else if (catOrDog == 1) // assign dog data
        {
            current->data->dog.breed = malloc(20 * sizeof(char));
            strcpy(current->data->dog.breed, dogBreeds[rand() % 7]);
            current->data->dog.tailType = malloc(10 * sizeof(char));
            strcpy(current->data->dog.tailType, dogTailTypes[rand() % 4]);
        }

        if (i < numPets - 1) // create a new node
        {
            current->next = malloc(sizeof(ListNode));
            current = current->next;
            current->next = NULL; // Set the next pointer of the new node to NULL
        }
        else // last node
        {
            current->next = NULL; // Set the next pointer of the last node to NULL
        }
    }

    menu(&head);

    // free the memory
    current = head;
    ListNode *temp;
    while (current != NULL)
    {
        free(current->data->name);
        free(current->data->bodyColor);
        if (current->data->catOrDog == 0)
        {
            free(current->data->cat.breed);
            free(current->data->cat.eyeColor);
        }
        else
        {
            free(current->data->dog.breed);
            free(current->data->dog.tailType);
        }
        free(current->data);
        temp = current;
        current = current->next;
        free(temp);
    }
    return 0;
}