#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void determineClass(char *ip) {
    int octet1;
    sscanf(ip, "%d", &octet1);

    if (octet1 >= 1 && octet1 <= 126) {
        printf("Class A\n");
    } else if (octet1 >= 128 && octet1 <= 191) {
        printf("Class B\n");
    } else if (octet1 >= 192 && octet1 <= 223) {
        printf("Class C\n");
    } else if (octet1 >= 224 && octet1 <= 239) {
        printf("Class D\n");
    } else if (octet1 >= 240 && octet1 <= 255) {
        printf("Class E\n");
    } else {
        printf("Invalid IP address\n");
    }
}

int main() {
    char ip[20];
    printf("Enter IP address: ");
    scanf("%s", ip);
    determineClass(ip);
    return 0;
}
