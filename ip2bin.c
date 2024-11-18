#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

void convertTo32Bit(char *ip) {
    int octets[4];
    sscanf(ip, "%d.%d.%d.%d", &octets[0], &octets[1], &octets[2], &octets[3]);

    unsigned long result = (octets[0] << 24) | (octets[1] << 16) | (octets[2] << 8) | octets[3];
    printf("32-bit Address: %lu\n", result);
}

int main() {
    char ip[20];
    printf("Enter IP address: ");
    scanf("%s", ip);
    convertTo32Bit(ip);
    return 0;
}
