#include <stdio.h>
#include "rental.h"

Date createDate() {
    Date date;
    printf("Enter Date (DD MM YYYY): ");
    scanf("%d %d %d", &date.day, &date.month, &date.year);
    return date;
}

Customer createCustomer() {
    Customer customer;
    printf("Enter Customer ID: ");
    scanf("%d", &customer.customerID);
    printf("Enter First Name: ");
    scanf("%s", customer.firstName);
    printf("Enter Last Name: ");
    scanf("%s", customer.lastName);
    printf("Enter Contact Info: ");
    scanf("%s", customer.contactInfo);
    return customer;
}

Game createGame() {
    Game game;
    printf("Enter Game Title: ");
    scanf("%s", game.title);
    printf("Enter Rental Price: ");
    scanf("%f", &game.rentalPrice);
    return game;
}

Rental createRental() {
    Rental rental;
    rental.customer = createCustomer();
    printf("Enter Rental ID: ");
    scanf("%d", &rental.rentalID);
    rental.game = createGame();
    printf("Enter Rental Date:\n");
    rental.rentalDate = createDate();
    printf("Enter Return Date:\n");
    rental.returnDate = createDate();
    return rental;
}

void displayRental(const Rental* rental) {
    printf("\nRental ID: %d\n", rental->rentalID);
    printf("Customer Name: %s %s\n", rental->customer.firstName, rental->customer.lastName);
    printf("Game Title: %s\n", rental->game.title);
    printf("Rental Date: %02d/%02d/%04d\n", rental->rentalDate.day, rental->rentalDate.month, rental->rentalDate.year);
    printf("Return Date: %02d/%02d/%04d\n", rental->returnDate.day, rental->returnDate.month, rental->returnDate.year);
    printf("Rental Price: %.2f\n", rental->game.rentalPrice);
}
