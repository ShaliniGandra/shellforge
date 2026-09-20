#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/mman.h>

int data = 100;
int bss;
const char *msg = "Hello";

void fun()
{
    int local = 20;
    printf("Stack  : %p\n", (void *)&local);
}

int main(int argc, char *argv[])
{
    int main_local = 10;

    int *heap = malloc(sizeof(int));
    *heap = 500;

    int *map = mmap(
        NULL,
        sizeof(int),
        PROT_READ | PROT_WRITE,
        MAP_PRIVATE | MAP_ANONYMOUS,
        -1,
        0
    );

    *map = 1000;

    printf("PID    : %d\n", getpid());
    printf("Code   : %p\n", (void *)main);
    printf("ROData : %p\n", (void *)msg);
    printf("Data   : %p\n", (void *)&data);
    printf("BSS    : %p\n", (void *)&bss);
    printf("Stack  : %p\n", (void *)&main_local);

    fun();

    printf("Heap   : %p\n", (void *)heap);
    printf("mmap   : %p\n", (void *)map);
    printf("argv   : %s\n", argv[1]);
    printf("HOME   : %s\n", getenv("HOME"));

    while (1)
        sleep(10);

    return 0;
}
