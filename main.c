#include <stdio.h>
#include "rental.h"
#include "rental.h"

int main() {
    Block* rentalBlocks = NULL;
    int choice;

    do {
        printf("\n1. Add Rental\n2. Search Rental by ID\n3. Display All Rentals\n4. Save Rentals to File\n5. Load Rentals from File\n6. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: {
                Rental rental = createRental();
                addRental(&rentalBlocks, rental);
                break;
            }
            case 2: {
                int rentalID;
                printf("Enter Rental ID to search: ");
                scanf("%d", &rentalID);
                Rental* rental = searchRental(rentalBlocks, rentalID);
                if (rental != NULL) {
                    displayRental(rental);
                } else {
                    printf("Rental not found.\n");
                }
                break;
            }
            case 3:
                displayAllRentals(rentalBlocks);
                break;
            case 4:
                saveRentals(rentalBlocks, "rentals.dat");
                break;
            case 5:
                rentalBlocks = loadRentals("rentals.dat");
                break;
            case 6:
                printf("Exiting.\n");
                break;
            default:
                printf("Invalid choice.\n");
        }
    } while (choice != 6);

    return 0;
}
