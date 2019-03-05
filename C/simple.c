#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h.>

int* two_sum(int* nums, int numsSize, int target)
{
    int *w = (int*)malloc(2 * sizeof(int));

    for (int i = 0; i < numsSize - 1; i++) {
        for (int j = i + 1; j < numsSize; j++) {
            if (nums[i] + nums[j] == target) {
                w[0] = i;
                w[1] = j;
                return w;
            }
        }
    }
    return w;       
}

void binary_print(int N)
{
    if (N) {
        binary_print(N >> 1);
        printf("%d", N&1);
    }
}


// https://leetcode.com/problems/binary-gap/
int binary_gap(int N)
{
    int last;
    for (last = 0; ((N >> last) & 1) == 0; last++);
    int distance = 0;
    for (int i = last; (N >> i); i++) {
        if ( ((N >> i) & 1) ) {
            if ( i - last > distance ) {
                distance = i - last;
            }
            last = i; 
        }
    }
    return distance;
}


// https://leetcode.com/problems/buddy-strings/
bool buddy_strings(char* A, char* B)
{
    if ( strlen(A) != strlen(B) ) {
        return false;
    }
    int letters_a['z' + 1] = {0};
    int letters_b['z' + 1] = {0};
    
    int ia = 0, ib = 0; //флаги окончания 1 и 2 строки соответственно
    for (int i = 0; ia == 0 || ib == 0; i++) {
        if ( A[i] == '\0' ) ia = 1; // закончилась 1 строка
        if ( B[i] == '\0' ) ib = 1; // закончилась 2 строка

        //пока строки не закочились, считаем буквы
        if ( !ia ) letters_a[A[i]]++; 
        if ( !ib ) letters_b[B[i]]++;
    }
    
    int count = 1;
    for (int c = 'a'; c <= 'z'; c++) {
        count -= abs(letters_a[c] - letters_b[c]);
    }
    if ( count < 0 ) return false; // больше чем одно несовпадение
    int mis = 0;
    if ( count == 1 ) mis--; 
    ia = 0, ib = 0;
    for (int i = 0; ia == 0 && ib == 0; i++) {
        if ( A[i] == '\0' ) ia = 1;
        if ( B[i] == '\0' ) ib = 1;
        if ( A[i] != B[i] ) mis++;
    }

    if ( mis > 1 || mis < 0 || ia != ib ) return false;

    return true;
}

int main(int argc, char const *argv[])
{
    char A[64], B[64];
    scanf("%s", A);
    scanf("%s", B);
    for (int i = 0; A[i] != '\0'; i++) {
        printf("%c\n", A[i]);
    }
    printf("%s",  buddy_strings(A, B) ? "true" : "false");  
    return 0;
}
