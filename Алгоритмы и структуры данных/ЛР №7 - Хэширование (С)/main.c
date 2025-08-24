#define _CRT_SECURE_NO_WARNINGS

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <math.h>

#define M 513
#define K 2000
#define SIZE 128

typedef struct Person {
    char Surname[SIZE];
}person;

int Exists (person* perArr, person* per) {
    for (int i = 0; i < K; i++){
        if ((strcmp(perArr[i].Surname, per->Surname) == 0) && (strcmp(perArr[i].Surname, "none") != 0)) {
            return 1;
        }
        return 0;
    }
}


int ReadPerson(person* perArr) {
    FILE* inputFile = fopen("surname.txt", "r");
    if (!inputFile) {
        return 0;
    }
    char buff[SIZE];
    int i = 0;
    while (fscanf(inputFile, "%s", buff) == 1) {
        person t;
        strcpy(t.Surname, buff);
        if (Exists(perArr, &t)) {
            sprintf(perArr[i].Surname, "%s%d", buff, i);
        }else {
            strcpy(perArr[i].Surname, buff);
        }
        i++;
    }
    fclose(inputFile);

    return 1;
}

uint32_t GetHash(const person* key) {
    uint32_t hash = 0;

    for (int i = 0; i < strlen(key->Surname); i++){
        hash = (hash << 2) - hash + key->Surname[i];
    }

    return hash % M;
}

void PrintPerSur(person* perArr) {
    for (int i = 0; i < K; i++) {
        printf("0x%03x %s\n", GetHash(&perArr[i]), perArr[i].Surname);
    }
}

int main() {
    person personArr[K];
    for (int i = 0; i < K; strcpy(personArr[i].Surname, "none"), i++);

    if (!ReadPerson(personArr)) printf("[ERR] Open a file");

    int personHashMap[M] = { 0 };

    for (int i = 0; i < K; i++) {
        personHashMap[GetHash(&personArr[i])]++;
    }

    for (int i = 0; i < M; i++) {
        printf("%d %d\n", i + 1, personHashMap[i]);
    }

    double k = M / (double)K;
    double k_ = K / (double)M;

    double stats = 0;
    for (int i = 0; i < M; i++) {
        stats += (personHashMap[i] - k_) * (personHashMap[i] - k_);
    }

    printf("M=%d N=%d\n", M, K);

    printf(
        "%lf [%lf %lf]",
        k * stats,
        M - sqrt(M),
        M + sqrt(M)
    );

    return 0;
}

