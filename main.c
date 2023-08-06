#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_NAME_LENGTH 100
#define MAX_NAMES 100

int main() {
    srand(time(NULL)); // Seed the random number generator with the current time

    char names[MAX_NAMES][MAX_NAME_LENGTH];
    int numNames = 0;

    FILE *file = fopen("names.txt", "r");
    if (file == NULL) {
        printf("Error opening the file.\n");
        return 1;
    }

    // Read names from the file
    char buffer[MAX_NAME_LENGTH];
    while (fgets(buffer, MAX_NAME_LENGTH, file)) {
        size_t length = strlen(buffer);
        if (length > 0 && buffer[length - 1] == '\n') {
            buffer[length - 1] = '\0'; // Remove the newline character
            length--;
        }
        strncpy(names[numNames], buffer, MAX_NAME_LENGTH - 1);
        names[numNames][MAX_NAME_LENGTH - 1] = '\0'; // Null-terminate the string
        numNames++;
        if (numNames >= MAX_NAMES) {
            printf("Too many names in the file. The limit is %d.\n", MAX_NAMES);
            fclose(file);
            return 1;
        }
    }
    fclose(file);

    if (numNames == 0) {
        printf("No names found in the file.\n");
        return 1;
    }

    // Generate a random index to select a winner
    int winnerIndex = rand() % numNames;

    printf("The Unixhideout Laptop Raffle Winner:\n");
    printf("%s\n", names[winnerIndex]);

    return 0;
}
