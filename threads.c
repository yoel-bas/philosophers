#include "philosophers.h"
void*       hey()

{
    printf("hey\n");
}
int main()
{
    pthread_t t1;
    pthread_create(&t1, NULL, &hey, NULL);
    pthread_join(t1, NULL);
    return(0);
}
