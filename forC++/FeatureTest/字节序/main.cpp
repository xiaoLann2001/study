#include <iostream>
#include <arpa/inet.h>

void testByteOrder() {
    unsigned int x = 0x12345678;
    unsigned char *p = (unsigned char *)&x;

    if (*p == 0x12) {
        printf("本机是大端序 (Big Endian)\n");
    } else {
        printf("本机是小端序 (Little Endian)\n");
    }
}

void testNetworkByteOrder() {
    unsigned short host_short = 0x1234;
    unsigned long host_long = 0x12345678;

    unsigned short net_short = htons(host_short);
    unsigned long net_long = htonl(host_long);

    printf("主机字节序 (short): 0x%x\n", host_short);
    printf("网络字节序 (short): 0x%x\n", net_short);

    printf("主机字节序 (long) : 0x%lx\n", host_long);
    printf("网络字节序 (long) : 0x%lx\n", net_long);
}

int main() {
    testByteOrder();

    system("lscpu | grep \"Byte Order\"");

    testNetworkByteOrder();

    return 0;
}
