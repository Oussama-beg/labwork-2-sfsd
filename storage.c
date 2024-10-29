#include <stdio.h>
#include <stdlib.h>
#include "rental.h"

void addRental(Block** head, Rental rental) {
    Block* current = *head;
    Block* previous = NULL;

    while (current != NULL && current->rentalCount == MAX_RENTALS_PER_BLOCK) {
        previous = current;
        current = current->next;
    }

    if (current == NULL) {
        current = (Block*)malloc(sizeof(Block));
        current->rentalCount = 0;
        current->next = NULL;
        if (previous == NULL) {
            *head = current;
        } else {
            previous->next = current;
        }
    }

    current->rentals[current->rentalCount++] = rental;
}

Rental* searchRental(Block* head, int rentalID) {
    Block* current = head;
    while (current != NULL) {
        for (int i = 0; i < current->rentalCount; i++) {
            if (current->rentals[i].rentalID == rentalID) {
                return &current->rentals[i];
            }
        }
        current = current->next;
    }
    return NULL;
}

void displayAllRentals(Block* head) {
    Block* current = head;
    while (current != NULL) {
        for (int i = 0; i < current->rentalCount; i++) {
            displayRental(&current->rentals[i]);
        }
        current = current->next;
    }
}

void saveRentals(Block* head, const char* filename) {
    FILE* file = fopen(filename, "ab"); // Open in append mode
    if (file == NULL) {
        printf("Error opening file for saving.\n");
        return;
    }

    Block* current = head;
    while (current != NULL) {
        fwrite(&current->rentalCount, sizeof(int), 1, file);
        fwrite(current->rentals, sizeof(Rental), current->rentalCount, file);
        current = current->next;
    }

    fclose(file);
}

Block* loadRentals(const char* filename) {
    FILE* file = fopen(filename, "rb");
    if (file == NULL) {
        printf("Error opening file for loading.\n");
        return NULL;
    }

    Block* head = NULL;
    Block* tail = NULL;
    while (!feof(file)) {
        int rentalCount;
        if (fread(&rentalCount, sizeof(int), 1, file) != 1) break;

        Block* newBlock = (Block*)malloc(sizeof(Block));
        newBlock->rentalCount = rentalCount;
        newBlock->next = NULL;
        fread(newBlock->rentals, sizeof(Rental), rentalCount, file);

        if (head == NULL) {
            head = newBlock;
        } else {
            tail->next = newBlock;
        }
        tail = newBlock;
    }

    fclose(file);
    return head;
}
