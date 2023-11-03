#include <stdio.h>
#include<time.h>
int gcd(int a, int b) {
    if (b == 0) {
        return a;
    } else {
        return gcd(b, a % b);
    }
}

int main() {
        clock_t t1 = clock();

    FILE* source_file = fopen("numbers.txt", "r");
    FILE* dest_file = fopen("output.txt", "w");

    if (!source_file) {
        printf("Error: Source file \"numbers.txt\" not found.\n");
        return 1;
    }

    if (!dest_file) {
        printf("Error: Destination file \"output.txt\" could not be opened.\n");
        return 1;
    }

    int numPairs;
    printf("Enter the number of pairs of numbers to read: ");
    scanf("%d", &numPairs);

    int num1, num2;
    printf("Content of the GCD of numbers in the file:\n");

    for (int i = 0; i < numPairs; i++) {
        if (fscanf(source_file, "%d %d", &num1, &num2) == 2) {
            int result = gcd(num1, num2);
            fprintf(dest_file, "The GCD of %d and %d is %d\n", num1, num2, result);
            printf("The GCD of %d and %d is %d\n", num1, num2, result);
        } else {
            printf("Error: Insufficient data in the source file.\n");
            break;
        }
    }

    fclose(source_file);
    fclose(dest_file);

    clock_t t2 = clock();
    clock_t t3 = t2-t1;
    double result = (double)(t3 / CLOCKS_PER_SEC);
    printf("%lf",result);
    

    return 0;
}
