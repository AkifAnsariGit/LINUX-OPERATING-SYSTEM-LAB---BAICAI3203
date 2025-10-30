#include <stdio.h>

int main() {
    int files[50], indexBlock[50], i, j, k, choice, n, start, length;

    for (i = 0; i < 50; i++)
        files[i] = 0;

    while (1) {
        printf("\nFile Allocation Methods:");
        printf("\n1. Sequential");
        printf("\n2. Indexed");
        printf("\n3. Linked");
        printf("\n4. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("\nEnter starting block and length of files: ");
                scanf("%d%d", &start, &length);
                for (i = start; i < (start + length); i++) {
                    if (files[i] == 0)
                        files[i] = 1;
                    else {
                        printf("\nBlock %d already allocated.", i);
                        break;
                    }
                }
                if (i == (start + length))
                    printf("\nFile allocated successfully.");
                break;

            case 2:
                printf("\nEnter index block: ");
                scanf("%d", &indexBlock[0]);
                if (files[indexBlock[0]] == 1) {
                    printf("\nBlock already allocated.");
                    break;
                }
                files[indexBlock[0]] = 1;
                printf("Enter number of blocks and block numbers: ");
                scanf("%d", &n);
                for (i = 1; i <= n; i++) {
                    scanf("%d", &indexBlock[i]);
                    if (files[indexBlock[i]] == 0)
                        files[indexBlock[i]] = 1;
                    else
                        printf("\nBlock %d already allocated.", indexBlock[i]);
                }
                printf("\nFile Indexed Allocation Successful.");
                printf("\nIndex Block %d -> ", indexBlock[0]);
                for (i = 1; i <= n; i++)
                    printf("%d ", indexBlock[i]);
                break;

            case 3:
                printf("\nEnter starting block and length of file: ");
                scanf("%d%d", &start, &length);
                j = start;
                if (files[start] == 1) {
                    printf("\nStarting block already allocated.");
                    break;
                }
                for (i = 0; i < length; i++) {
                    if (files[j] == 0) {
                        files[j] = 1;
                        printf("%d -> ", j);
                        j = (j + 1) % 50;
                    } else {
                        printf("\nBlock %d already allocated.", j);
                        break;
                    }
                }
                if (i == length)
                    printf("File allocated successfully.");
                break;

            case 4:
                return 0;

            default:
                printf("\nInvalid choice.");
        }
    }
}
