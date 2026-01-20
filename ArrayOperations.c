#include <stdio.h>

// Function declarations
void display(int arr[], int size);
void insertAtEnd(int arr[], int *size, int value);
void insertAtBeginning(int arr[], int *size, int value);
void insertAtPosition(int arr[], int *size, int pos, int value);
void deleteAtEnd(int arr[], int *size);
void deleteAtBeginning(int arr[], int *size);
void deleteAtPosition(int arr[], int *size, int pos);
void reverseTemp(int arr[], int size);
void reverseInPlace(int arr[], int size);
int sum(int arr[], int size);
int sumRec(int arr[], int size);
void search(int arr[], int size, int key);
void separateOddEven(int arr[], int size);
void separatePosNeg(int arr[], int size);

int main() {
    int mainArray[20];
    int size = 0;
    int choice, value, pos;

    while (1) {
        printf("\n--- ARRAY OPERATIONS MENU ---\n");
        printf("1. Insert at end\n");
        printf("2. Insert at beginning\n");
        printf("3. Insert at position\n");
        printf("4. Delete from end\n");
        printf("5. Delete from beginning\n");
        printf("6. Delete from position\n");
        printf("7. Reverse (temporary array)\n");
        printf("8. Reverse (in-place)\n");
        printf("9. Sum (without recursion)\n");
        printf("10. Sum (with recursion)\n");
        printf("11. Search element\n");
        printf("12. Separate odd/even\n");
        printf("13. Separate positive/negative\n");
        printf("0. Exit\n");

        scanf("%d", &choice);

        switch (choice) {
            case 1:
                scanf("%d", &value);
                insertAtEnd(mainArray, &size, value);
                break;

            case 2:
                scanf("%d", &value);
                insertAtBeginning(mainArray, &size, value);
                break;

            case 3:
                scanf("%d %d", &pos, &value);
                insertAtPosition(mainArray, &size, pos, value);
                break;

            case 4:
                deleteAtEnd(mainArray, &size);
                break;

            case 5:
                deleteAtBeginning(mainArray, &size);
                break;

            case 6:
                scanf("%d", &pos);
                deleteAtPosition(mainArray, &size, pos);
                break;

            case 7:
                reverseTemp(mainArray, size);
                break;

            case 8:
                reverseInPlace(mainArray, size);
                break;

            case 9:
                printf("Sum = %d\n", sum(mainArray, size));
                break;

            case 10:
                printf("Sum = %d\n", sumRec(mainArray, size));
                break;

            case 11:
                scanf("%d", &value);
                search(mainArray, size, value);
                break;

            case 12:
                separateOddEven(mainArray, size);
                break;

            case 13:
                separatePosNeg(mainArray, size);
                break;

            case 0:
                return 0;
        }

        display(mainArray, size);
    }
}

// Function definitions

void display(int arr[], int size) {
    printf("Array: ");
    for (int i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

void insertAtEnd(int arr[], int *size, int value) {
    arr[*size] = value;
    (*size)++;
}

void insertAtBeginning(int arr[], int *size, int value) {
    for (int i = *size; i > 0; i--)
        arr[i] = arr[i - 1];
    arr[0] = value;
    (*size)++;
}

void insertAtPosition(int arr[], int *size, int pos, int value) {
    for (int i = *size; i > pos; i--)
        arr[i] = arr[i - 1];
    arr[pos] = value;
    (*size)++;
}

void deleteAtEnd(int arr[], int *size) {
    (*size)--;
}

void deleteAtBeginning(int arr[], int *size) {
    for (int i = 0; i < *size - 1; i++)
        arr[i] = arr[i + 1];
    (*size)--;
}

void deleteAtPosition(int arr[], int *size, int pos) {
    for (int i = pos; i < *size - 1; i++)
        arr[i] = arr[i + 1];
    (*size)--;
}

void reverseTemp(int arr[], int size) {
    int temp[20];
    for (int i = 0; i < size; i++)
        temp[i] = arr[size - i - 1];
    for (int i = 0; i < size; i++)
        arr[i] = temp[i];
}

void reverseInPlace(int arr[], int size) {
    int i = 0, j = size - 1;
    while (i < j) {
        int t = arr[i];
        arr[i] = arr[j];
        arr[j] = t;
        i++; j--;
    }
}

int sum(int arr[], int size) {
    int s = 0;
    for (int i = 0; i < size; i++)
        s += arr[i];
    return s;
}

int sumRec(int arr[], int size) {
    if (size == 0)
        return 0;
    return arr[size - 1] + sumRec(arr, size - 1);
}

void search(int arr[], int size, int key) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == key) {
            printf("Found at index %d\n", i);
            return;
        }
    }
    printf("Not found\n");
}

void separateOddEven(int arr[], int size) {
    printf("Odd: ");
    for (int i = 0; i < size; i++)
        if (arr[i] % 2 != 0) printf("%d ", arr[i]);

    printf("\nEven: ");
    for (int i = 0; i < size; i++)
        if (arr[i] % 2 == 0) printf("%d ", arr[i]);
    printf("\n");
}

void separatePosNeg(int arr[], int size) {
    printf("Positive: ");
    for (int i = 0; i < size; i++)
        if (arr[i] >= 0) printf("%d ", arr[i]);

    printf("\nNegative: ");
    for (int i = 0; i < size; i++)
        if (arr[i] < 0) printf("%d ", arr[i]);
    printf("\n");
}