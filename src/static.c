#include "lib.h"

int main() {
    int option = 0;
    while (option != 3) {
        printf("Your options: 1 - pi(1 arg), 2 - square(2 args), 3 - exit\n");
        scanf("%d", &option);
        switch(option) {
            case 1:
                int k;
                scanf("%d", &k);
                printf("Pi: %f\n", Pi(k));
                break;
            case 2:
                float side1, side2;
                scanf("%f%f", &side1, &side2);
                printf("%f\n", Square(side1, side2));
                break;
            case 3:
                printf("Exiting!\n");
                break;
            default:
                printf("Wrong option!\n");
                break;
        }
    }
}