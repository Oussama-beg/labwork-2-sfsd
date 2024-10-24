// main.c
#include <stdio.h>
#include "rental.h"

// Main program
int main() {
    int blockCount = 0;
    RentalBlock blocks[MAX_RENTALS / BLOCK_SIZE] = {0}; // Array of rental blocks
    int currentBlockIndex = 0; // Current block being used
    int choice, searchID;
    Rental* foundRental;

    do {
        printf("\nRental Management System\n");
        printf("1. Create Rental\n");
        printf("2. Display All Rentals\n");
        printf("3. Search for a Rental\n");
        printf("4. Save Rentals to File\n");
        printf("5. Load Rentals from File\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                // Check if current block is full
                if (blocks[currentBlockIndex].count == BLOCK_SIZE) {
                    currentBlockIndex++;
                    if (currentBlockIndex >= MAX_RENTALS / BLOCK_SIZE) {
                        printf("Maximum rental limit reached.\n");
                        break;
                    }
                }
                blocks[currentBlockIndex].rentals[blocks[currentBlockIndex].count++] = createRental();
                break;

            case 2:
                for (int i = 0; i <= currentBlockIndex; i++) {
                    for (int j = 0; j < blocks[i].count; j++) {
                        displayRental(blocks[i].rentals[j]);
                    }
                }
                break;

            case 3:
                printf("Enter Rental ID to search: ");
                scanf("%d", &searchID);
                foundRental = NULL;
                for (int i = 0; i <= currentBlockIndex; i++) {
                    foundRental = searchRentalInBlock(&blocks[i], searchID);
                    if (foundRental != NULL) break;
                }
                if (foundRental != NULL) {
                    displayRental(*foundRental);
                } else {
                    printf("Rental not found.\n");
                }
                break;

            case 4:
                for (int i = 0; i <= currentBlockIndex; i++) {
                    saveBlockToFile(&blocks[i], "rentals.dat");
                }
                break;

            case 5:
                blockCount = loadBlocksFromFile(blocks, "rentals.dat");
                currentBlockIndex = blockCount - 1; // Set to last loaded block
                break;

            case 6:
                printf("Exiting...\n");
                break;

            default:
                printf("Invalid choice! Please try again.\n");
                break;
        }
    } while (choice != 6);

    return 0;
}
