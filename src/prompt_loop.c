#include "prompt_loop.h"

int identify_command(const char* command){
    int command_id = -1;
    if(strncmp(command, "exit",4)==0){
        command_id = 0;
        printf("[command]:exit >> this process will be ended. GoodBye!");
    }else if(strcmp(command, "")==0){
        command_id = -1;
        printf("error:command name is empty");
    }else{
        command_id = -1;
        printf("error:this command is not defined");
    }
    printf("\n");

    return command_id;
}

int prompt_loop(){

    struct pollfd pfd;
    char user_prompt[MAX_USER_PROMPT];
    int ret = 0;

    pfd.fd     = STDIN_FILENO;
    pfd.events = POLLIN;

    while(1){
        printf(">");
        fflush(stdout);
        if(poll(&pfd, 1, -1) < 0){
            printf("poll error\n");
            ret = -1;
            break;
        }

        if(pfd.revents & POLLIN){
            if(fgets(user_prompt,sizeof(user_prompt),stdin)==NULL){
                ret = -1;
                break;
            }
            user_prompt[strcspn(user_prompt, "\n")] = '\0';
            if(user_prompt[0]=='/'){
                int command_id = -1;
                const char* command = user_prompt + 1;
                command_id = identify_command(command);
                if(command_id == 0){
                    ret=0;
                    break;
                }
            }
        }
        printf("\n");

    }
    return ret;
}