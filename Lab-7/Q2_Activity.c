#include <stdio.h>

// Input: start[]  =  {1, 3, 0, 5, 8, 5}, finish[] =  {2, 4, 6, 7, 9, 9};
struct Activity {
    int start;
    int finish;
};

void printActivities(struct Activity activities[], int n) {
    int i = 0;
    printf("Selected Activities:\n");

    printf("Activity %d: Start = %d, Finish = %d\n", i + 1, activities[i].start, activities[i].finish);

    for (int j = 1; j < n; j++) {
        if (activities[j].start >= activities[i].finish) {
            printf("Activity %d: Start = %d, Finish = %d\n", j + 1, activities[j].start, activities[j].finish);
            i = j;
        }
    }
}

void activitySelection(struct Activity activities[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (activities[j].finish > activities[j + 1].finish) {
                struct Activity temp = activities[j];
                activities[j] = activities[j + 1];
                activities[j + 1] = temp;
            }
        }
    }

    printActivities(activities, n);
}

int main() {
    int n;
    printf("Enter the number of activities: ");
    scanf("%d", &n);

    struct Activity activities[n];

    for (int i = 0; i < n; i++) {
        printf("Enter start and finish time for activity %d: ", i + 1);
        scanf("%d %d", &activities[i].start, &activities[i].finish);
    }

    activitySelection(activities, n);

    return 0;
}
