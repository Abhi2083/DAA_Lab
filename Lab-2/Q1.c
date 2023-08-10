#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void decimal_to_binary(int num, FILE* dest_file) {
    if (num > 1) {
        decimal_to_binary(num / 2, dest_file);
    }
    fprintf(dest_file, "%d", num % 2);
}

int main() {
    clock_t t1 = clock();
    int n;
    char source_file[100], dest_file[100];

    printf("Enter the number of decimal numbers to convert to binary: ");
    scanf("%d", &n);

    printf("Enter the name of the source file: ");
    scanf("%s", source_file);

    printf("Enter the name of the destination file: ");
    scanf("%s", dest_file);

    FILE* source = fopen(source_file, "r");
    FILE* dest = fopen(dest_file, "w");

    if (!source) {
        printf("Error: Source file \"%s\" not found.\n", source_file);
        return 1;
    }

    if (!dest) {
        printf("Error: Destination file \"%s\" could not be opened.\n", dest_file);
        return 1;
    }

    printf("Content of the first '%d' decimal numbers and their equivalent binary numbers:\n", n);

    for (int i = 0; i < n; i++) {
        int num;
        if (fscanf(source, "%d", &num) == 1) {
            fprintf(dest, "The binary equivalent of %d is ", num);
            decimal_to_binary(num, dest);
            fprintf(dest, "\n");

            printf("Decimal: %d -> Binary: ", num);
            decimal_to_binary(num, stdout);
            printf("\n");
        } else {
            break;
        }
    }

    fclose(source);
    fclose(dest);

    clock_t t2 = clock();
    clock_t t3 = t2-t1;
    double result = (double)(t3 / CLOCKS_PER_SEC);
    printf("%lf",result);

    return 0;
}
