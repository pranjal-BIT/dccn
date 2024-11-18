#include <stdio.h>
#include <string.h>

void xorOperation(char *a, char *b, char *result) {
    for (int i = 1; b[i] != '\0'; i++) {
        result[i - 1] = (a[i] == b[i]) ? '0' : '1';
    }
    result[strlen(b) - 1] = '\0';
}

void computeCRC(char *dataword, char *divisor, char *codeword) {
    int m = strlen(divisor);
    int n = strlen(dataword);
    char augmentedDataword[100];
    strcpy(augmentedDataword, dataword);

    for (int i = 0; i < m - 1; i++) {
        strcat(augmentedDataword, "0");
    }

    char remainder[100], temp[100];
    strncpy(remainder, augmentedDataword, m);
    remainder[m] = '\0';

    for (int i = m; i <= strlen(augmentedDataword); i++) {
        if (remainder[0] == '1') {
            xorOperation(remainder, divisor, temp);
        } else {
            xorOperation(remainder, "0000", temp);
        }
        strcpy(remainder, temp);
        if (i < strlen(augmentedDataword)) {
            strncat(remainder, &augmentedDataword[i], 1);
        }
    }

    strcpy(codeword, dataword);
    strcat(codeword, &remainder[1]);
}

int main() {
    char dataword[100], divisor[100], codeword[200];
    printf("Enter dataword: ");
    scanf("%s", dataword);
    printf("Enter divisor (CRC-4): ");
    scanf("%s", divisor);

    computeCRC(dataword, divisor, codeword);
    printf("Codeword: %s\n", codeword);

    return 0;
}
