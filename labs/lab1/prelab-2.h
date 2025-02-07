#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#define HASH_SIZE  10007

unsigned int hash(int num);
void hash_table_init();
int hash_insert(int num);
int getArrayInfo(int array[], int size, int* max, int* min, int hash_table[HASH_SIZE]);