#include "stdio.h"
#include "dlfcn.h"

int main() {
    int current = 1;
    void* LBhandle = dlopen("./libimpl1.so", RTLD_LAZY);
    if (!LBhandle) {
        fprintf(stderr, "Error: %s\n", dlerror());
        return -1;
    }
    float (*Pi)(int) = dlsym(LBhandle, "Pi");
    if (!Pi) {
        fprintf(stderr, "Error: %s\n", dlerror());
        dlclose(LBhandle);
        return 1;
    }
    float (*Square)(float, float) = dlsym(LBhandle, "Square");
    if (!Square) {
        fprintf(stderr, "Error: %s\n", dlerror());
        dlclose(LBhandle);
        return 2;
    }
    int option = 0;
    while (option != 3) {
        printf("You're using implementation %d.\nOptions: 0 - change implementation, 1 - pi(1 arg), 2 - square(2 args), 3 - exit\n", current);
        scanf("%d", &option);
        switch(option) {
            case 0:
                dlclose(LBhandle);
                if (current == 1) {
                    LBhandle = dlopen("./libimpl2.so", RTLD_LAZY);
                    printf("Moved from implementation %d to %d\n", current, current++);
                } else {
                    LBhandle = dlopen("./libimpl1.so", RTLD_LAZY);
                    printf("Moved from implementation %d to %d\n", current, current--);
                }
                Pi = dlsym(LBhandle, "Pi");
                if (!Pi) {
                    fprintf(stderr, "Error: %s\n", dlerror());
                    dlclose(LBhandle);
                    return 1;
                }
                Square = dlsym(LBhandle, "Square");
                if (!Square) {
                    fprintf(stderr, "Error: %s\n", dlerror());
                    dlclose(LBhandle);
                    return 2;
                }
                break;
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
                dlclose(LBhandle);
                break;
            default:
                printf("Wrong option!\n");
                break;
        }
    }
}