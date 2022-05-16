#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_ITEMS_ 160
#define STRING_SIZE_ 1024
#define ID_SIZE_ 5

typedef struct {
    char ID[ID_SIZE_];
    char Name[STRING_SIZE_];
    double Price;
    int Quantity;
} product;

void print_products(product list[MAX_ITEMS_], float priceLimit, int productCount) {
    for (int i = 0; i < productCount; i++) {
        if (list[i].Quantity > 0 && list[i].Price <= priceLimit) {
            printf("%s\n", list[i].Name);
        }
    }
}

int scan_products(FILE *fp, product list[MAX_ITEMS_]) {
    char buffer[STRING_SIZE_] = {0}, *token = 0;
    int i = 0;

    while(1) {
        if(feof(fp)) {
            break;
        }

        fgets(buffer, STRING_SIZE_, fp);

        token = strtok(buffer, ",");
        strcpy(list[i].ID, token);

        token = strtok(NULL, ",");
        strcpy(list[i].Name, token);

        token = strtok(NULL, ",");
        list[i].Price = atof(token);

        token = strtok(NULL, ",");
        list[i].Quantity = atoi(token);

        i++;    
    }

    return i+1;
}

int main(int argc, char *argv[3]) {

    if (argc != 3) {
        printf("Usage: ./a.out FILE_PATH PRICE_LIMIT.\n");
        return 1;
    }

    FILE *fp = fopen(argv[1], "r");
    if (fp == NULL) {
        printf("CANNOT OPEN FILE.");
    }

    product productList[MAX_ITEMS_] = {0};
    int productCount = scan_products(fp, productList);
    
    print_products(productList, atof(argv[2]), productCount);

    fclose(fp);
    return 0;
}