#include <stdio.h>

int ShiftLeftCircular(int value) {
    return ((value << 1) | (value >> 7)) & 0xFF;
}

int InvertBits(int value) {
    return (~value) & 0xFF;
}

int ShiftRightCircular(int value) {
    return ((value >> 1) | (value << 7)) & 0xFF;
}

int ApplyMask(int value) {
    return value ^ 129;
}

int EncryptValue(int value) {
    value = ShiftLeftCircular(value);
    value = InvertBits(value);
    value = ShiftRightCircular(value);
    value = ApplyMask(value);
    return value;
}

int main() {
    char inputChar;
    
    printf("Ingrese el caracter a encriptar: ");
    scanf(" %c", &inputChar);
    
    int result = EncryptValue((int)inputChar);
    
    printf("%c -> %c\n", inputChar, (char)result);
    
    return 0;
}