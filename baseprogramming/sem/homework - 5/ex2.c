#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PRODUCTS 100
#define MAX_ORDERS 100

struct Product {
    char name[50];
    float price;
    int number;
};

struct Order {
    char address[100];
    int product_number;
};

struct Product products[MAX_PRODUCTS];
struct Order orders[MAX_ORDERS];
int product_count = 0;
int order_count = 0;

void create_product(char *name, float price, int number) {
    struct Product product;
    strcpy(product.name, name);
    product.price = price;
    product.number = number;
    products[product_count++] = product;

    for (int i = 0; i < order_count; i++) {
        if (orders[i].product_number == number) {
            printf("Client %s ordered %s\n", orders[i].address, name);
            orders[i] = orders[--order_count];
            i--;
        }
    }
}

void create_order(char *address, int product_number) {
    int found = 0;
    for (int i = 0; i < product_count; i++) {
        if (products[i].number == product_number) {
            printf("Client %s ordered %s\n", address, products[i].name);
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("No product with number %d available yet\n", product_number);
        struct Order order;
        strcpy(order.address, address);
        order.product_number = product_number;
        orders[order_count++] = order;
    }
}

int main() {
    char command[10];
    while (1) {
        printf("Enter command (Product/Order/END): ");
        scanf("%s", command);
        if (strcmp(command, "Product") == 0) {
            char name[50];
            float price;
            int number;
            printf("Enter product name, price, and number: ");
            scanf("%s%f%d", name, &price, &number);
            create_product(name, price, number);
        } else if (strcmp(command, "Order") == 0) {
            char address[100];
            int product_number;
            printf("Enter address and product number: ");
            scanf("%s%d", address, &product_number);
            create_order(address, product_number);
        } else if (strcmp(command, "END") == 0) {
            break;
        }
    }
    return 0;
}
