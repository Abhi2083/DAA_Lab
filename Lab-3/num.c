#include <stdio.h>

int main() {
    FILE *file = fopen("descending.txt", "w");
    if (file == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    for (int i = 600; i >= 1; i--) {
        fprintf(file, "%d ", i);
        if ((600 - i + 1) % 15 == 0) {
            fprintf(file, "\n");
        }
    }

    fclose(file);
    printf("Data written to file successfully.\n");

    return 0;
}
