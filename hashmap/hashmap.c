#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>
#include <stdbool.h>

#define TABLE_SIZE 10
#define MAX_NAME 256

typedef struct{
    char name[MAX_NAME];
    int age;
}person;

person* hash_table[TABLE_SIZE];

unsigned int hash(char *name){
    int length = strnlen(name,MAX_NAME);
    unsigned int  hash_value = 0;
    for(int i=0; i<length; i++){
        hash_value += name[i];
        hash_value = (hash_value * name[i]) % TABLE_SIZE;
    }

    return hash_value;
}
void init_hash_table(){
    for(int i=0; i<TABLE_SIZE; i++){
        hash_table[i] = NULL;
    }
    //table is empty
}

void print_table(){
    for(int i=0; i<TABLE_SIZE; i++){
        if(hash_table[i] == NULL){
            printf("\t%d\t---\n",i);
        }
        else{
            printf("\t%d\t%s\n",i,hash_table[i]->name);
        }
    }
}
bool hash_table_insert(person *p){
    if(p==NULL) return false;
    int index = hash(p->name);
    if(hash_table[index] != NULL){
        return false;
    }
    hash_table[index] = p;
}

person* hash_table_look_up(char* name){
    int index = hash(name);
    if(hash_table[index] != NULL &&
    strncmp(hash_table[index]->name, name, MAX_NAME) == 0){
        return hash_table[index];
    }
    else{
        return NULL;
    }
}

person* hash_table_delete(char* name){
    int index = hash(name);
    if(hash_table[index] == NULL &&
    strncmp(hash_table[index]->name, name, MAX_NAME) == 0){
        person* tmp = hash_table[index];
        hash_table[index] = NULL;
        return tmp;
    }
    else{
        return NULL;
    }
}
int main(int argc, char**argv){

    init_hash_table();
    person anthony = {.name ="Anthony",.age=18};
    person eva = {.name ="Eva",.age=18};
    person hannah = {.name ="Hannah",.age=18};
    person bre = {.name ="Breanna",.age=20};
    hash_table_insert(&anthony);
    hash_table_insert(&eva);
    hash_table_insert(&hannah);
    hash_table_insert(&bre);
    print_table();

    person* tmp = hash_table_look_up("Eva");
    if(tmp==NULL){
        printf("NOT FOUND\n");
    }
    else{
        printf("\n%s FOUND\n",tmp->name);
    }

    tmp = hash_table_look_up("Anthony");
    if(tmp==NULL){
        printf("NOT FOUND\n");
    }
    else{
        printf("%s FOUND\n",tmp->name);
    }
    
    tmp = hash_table_look_up("freakbob");
    if(tmp==NULL){
        printf("NOT FOUND\n");
    }
    else{
        printf("\n%s FOUND\n",tmp->name);
    }
    //printf("Anthony => %u\n",hash("Anthony"));
    //printf("Hannah => %u\n",hash("Hannah"));
    //printf("Lathan => %u\n",hash("Lathan"));
    //printf("Eva => %u\n",hash("Eva"));
    //printf("Breanna => %u\n",hash("Breanna"));
    return 0;
}