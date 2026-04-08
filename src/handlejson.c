#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <cjson/cJSON.h>


int build_json(char **data, char *str, int num){
    int ret = 1;
    cJSON *root = cJSON_CreateObject();
    cJSON_AddStringToObject(root, "strings", str);
    cJSON_AddNumberToObject(root, "integer", num);
    
    *data = cJSON_PrintUnformatted(root);
    return ret;
}

#ifdef MAIN_FUNC

int main(){
    char *data;
    build_json(&data, "str", 0);
    printf("%s\n", data);
}

#endif