#include "main.h"

int main(void)
{

    if(prompt_loop() < 0){
        printf("error\n");
        return -1;
    }

    return 0;
}
