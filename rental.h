#ifndef RENTAL_MANAGEMENT_H
#define RENTAL_MANAGEMENT_H

#define MAX_RENTALS_PER_BLOCK 5

typedef struct {
    int customerID;
    char firstName[50];
    char lastName[50];
    char contactInfo[100];
} Customer;

typedef struct {
    char title[100];
    float rentalPrice;
} Game;

typedef struct {
    int day;
    int month;
    int year;
} Date;

typedef struct {
    int rentalID;
    Customer customer;
    Game game;
    Date rentalDate;
    Date returnDate;
} Rental;

typedef struct Block {
    Rental rentals[MAX_RENTALS_PER_BLOCK];
    int rentalCount;
    struct Block* next;
} Block;

// Function prototypes for rental operations
Rental createRental();
void displayRental(const Rental* rental);
Customer createCustomer();
Game createGame();
Date createDate();

// Function prototypes for storage management
void addRental(Block** head, Rental rental);
Rental* searchRental(Block* head, int rentalID);
void displayAllRentals(Block* head);
void saveRentals(Block* head, const char* filename);
Block* loadRentals(const char* filename);

#endif // RENTAL_MANAGEMENT_H
