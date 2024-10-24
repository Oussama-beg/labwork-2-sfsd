// block_storage.c
#include <stdio.h>
#include <stdlib.h>
#include "rental.h"

// Function to save a block of rentals to a file
void saveBlockToFile(RentalBlock *block, const char *filename) {
    FILE *file = fopen(filename, "ab"); // Append mode for saving blocks
    if (file == NULL) {
        printf("Unable to open file for writing.\n");
        return;
    }
    fwrite(block, sizeof(RentalBlock), 1, file);
    fclose(file);
    printf("Rental block saved successfully.\n");
}

// Function to load blocks from a file
int loadBlocksFromFile(RentalBlock blocks[], const char *filename) {
    FILE *file = fopen(filename, "rb");
    if (file == NULL) {
        printf("Unable to open file for reading.\n");
        return 0;
    }

    int count = 0;
    while (fread(&blocks[count], sizeof(RentalBlock), 1, file)) {
        count++;
    }

    fclose(file);
    printf("Rental blocks loaded successfully.\n");
    return count;
}
