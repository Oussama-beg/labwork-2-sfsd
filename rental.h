// rental.h
#ifndef RENTAL_H
#define RENTAL_H

#define BLOCK_SIZE 5  // Define the block size (number of rentals per block)
#define MAX_RENTALS 100

// Define the structures
typedef struct {
    int customerID;
    char firstName[50];
    char lastName[50];
    char contactInfo[100];
} Customer;

typedef struct {
    int day;
    int month;
    int year;
} Date;

typedef struct {
    char title[100];
    float rentalPrice;
} Game;

typedef struct {
    int rentalID;
    Customer customer;
    Game game;
    Date rentalDate;
    Date returnDate;
    float totalPrice;
} Rental;

typedef struct {
    Rental rentals[BLOCK_SIZE];
    int count; // Number of rentals in the block
} RentalBlock;

// Function prototypes
Customer createCustomer();
Rental createRental();
void displayRental(Rental r);
Rental* searchRentalInBlock(RentalBlock *block, int rentalID);
void saveBlockToFile(RentalBlock *block, const char *filename);
int loadBlocksFromFile(RentalBlock blocks[], const char *filename);

#endif
