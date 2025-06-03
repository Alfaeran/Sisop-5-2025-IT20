#include "std_lib.h"

int div(int a, int b) {
    int sign = 1;
    if (a < 0) { a = -a; sign *= -1; }
    if (b < 0) { b = -b; sign *= -1; }

    int result = 0;
    while (a >= b) {
        a -= b;
        result++;
    }
    return result * sign;
}

int mod(int a, int b) {
    int sign = (a < 0) ? -1 : 1;
    if (a < 0) a = -a;
    if (b < 0) b = -b;

    while (a >= b) {
        a -= b;
    }
    return a * sign;
}

bool strcmp(char *str1, char *str2) {
    int i = 0;
    while (str1[i] != '\0' && str2[i] != '\0') {
        if (str1[i] != str2[i]) return false;
        i++;
    }
    return str1[i] == '\0' && str2[i] == '\0';
}

void strcpy(char *dst, char *src) {
    int i = 0;
    while (src[i] != '\0') {
        dst[i] = src[i];
        i++;
    }
    dst[i] = '\0';
}

void clear(byte *buf, unsigned int size) {
    for (unsigned int i = 0; i < size; i++) {
        buf[i] = 0;
    }
}

void atoi(char *str, int *num) {
    int i = 0, sign = 1, result = 0;
    if (str[0] == '-') {
        sign = -1;
        i++;
    }
    while (str[i] >= '0' && str[i] <= '9') {
        result = result * 10 + (str[i] - '0');
        i++;
    }
    *num = result * sign;
}

void itoa(int num, char *str) {
    int i = 0, isNegative = 0;
    if (num == 0) {
        str[i++] = '0';
        str[i] = '\0';
        return;
    }

    if (num < 0) {
        isNegative = 1;
        num = -num;
    }

    while (num > 0) {
        str[i++] = (num % 10) + '0';
        num /= 10;
    }

    if (isNegative) str[i++] = '-';
    str[i] = '\0';

    int start = 0, end = i - 1;
    while (start < end) {
        char temp = str[start];
        str[start] = str[end];
        str[end] = temp;
        start++;
        end--;
    }
}
