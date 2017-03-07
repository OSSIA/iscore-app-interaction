#include <stdlib.h>
#include <string.h>
#include "extract.hpp"

struct datai* extract_data(const char* str)
{
    datai* d = new datai;
    char recup1[strlen(str)];
    char recup2[strlen(str)];
    int i = 0;
    int j = 0;
    while (str[i] != ':'){
        recup1[i]=str[i];
        i++;
    }
    recup1[i]='\0';
    i++;
    d->id = atoi(recup1);
    while (str[i] != ':'){
        recup2[j]=str[i];
        i++;
        j++;
    }
    recup2[j]='\0';
    d->duration = atoi(recup2);
    return d;
}
