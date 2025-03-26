#include <iostream>

union EndianTest {
    int value;
    char bytes[sizeof(int)];
};

void check_endianness() {
    EndianTest test;
    test.value = 0x12345678;  // 赋值 0x12345678，观察最低字节的存储顺序

    std::cout << "Memory representation: ";
    for (size_t i = 0; i < sizeof(int); i++) {
        printf("%02X ", static_cast<unsigned char>(test.bytes[i]));
    }
    std::cout << std::endl;

    if (test.bytes[0] == 0x78) {
        std::cout << "System is Little-Endian (小端)" << std::endl;
    } else if (test.bytes[0] == 0x12) {
        std::cout << "System is Big-Endian (大端)" << std::endl;
    } else {
        std::cout << "Unknown Endianness" << std::endl;
    }
}

int main() {
    check_endianness();
    system("lscpu | grep \"Byte Order\"");
    return 0;
}
