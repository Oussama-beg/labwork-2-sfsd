// rental.c
#include <stdio.h>
#include <string.h>
#include "rental.h"

// Function to create a customer
Customer createCustomer() {
    Customer c;
    printf("Enter Customer ID: ");
    scanf("%d", &c.customerID);
    printf("Enter First Name: ");
    scanf("%s", c.firstName);
    printf("Enter Last Name: ");
    scanf("%s", c.lastName);
    printf("Enter Contact Info: ");
    scanf("%s", c.contactInfo);
    return c;
}

// Function to create a rental
Rental createRental() {
    Rental r;
    r.customer = createCustomer();

    printf("Enter Rental ID: ");
    scanf("%d", &r.rentalID);

    printf("Enter Game Title: ");
    scanf("%s", r.game.title);

    printf("Enter Rental Price: ");
    scanf("%f", &r.game.rentalPrice);

    printf("Enter Rental Date (DD MM YYYY): ");
    scanf("%d %d %d", &r.rentalDate.day, &r.rentalDate.month, &r.rentalDate.year);

    printf("Enter Return Date (DD MM YYYY): ");
    scanf("%d %d %d", &r.returnDate.day, &r.returnDate.month, &r.returnDate.year);

    r.totalPrice = r.game.rentalPrice; // Simple assumption for rental price calculation

    return r;
}

// Function to display a rental
void displayRental(Rental r) {
    printf("\nRental ID: %d\n", r.rentalID);
    printf("Customer: %s %s\n", r.customer.firstName, r.customer.lastName);
    printf("Game Title: %s\n", r.game.title);
    printf("Rental Date: %02d/%02d/%d\n", r.rentalDate.day, r.rentalDate.month, r.rentalDate.year);
    printf("Return Date: %02d/%02d/%d\n", r.returnDate.day, r.returnDate.month, r.returnDate.year);
    printf("Total Price: $%.2f\n", r.totalPrice);
}

// Function to search for a rental in a block by ID
Rental* searchRentalInBlock(RentalBlock *block, int rentalID) {
    for (int i = 0; i < block->count; i++) {
        if (block->rentals[i].rentalID == rentalID) {
            return &block->rentals[i];
        }
    }
    return NULL;
}
