#include "../HeaderFiles/kernel32.h"

/* Memory */
void *kmemset(void *s, int c, size_t n){
    unsigned char* p = (unsigned char*)s;
    while(n--){
        *p++ = c;
    }
    return s;
}

/* Strings */
int kstrlen(char *s){
    char *p = s;
    while(!(*p == 0))
        p++;

    return p - s;
}

void reverse(char s[]){
    int c, i, j;
    for(i = 0, j = kstrlen(s) - 1; i < j; i++, j--){
        c = s[i];
        s[i] = s[j];
        s[j] = c;
    }
}
/* Conversions */
void itoa(int n, char s[]){
    int i, sign;

    if((sign = n) < 0)
        n = -n;
    
    i = 0;
    do {
        s[i++] = n % 10 + '0';
    } while((n /= 10) > 0);

    if(sign < 0)
        s[i++] = '-';
    
    s[i] = '\0';
    reverse(s);
}
void itox(unsigned int n, char s[]){
    int r, i = 0;

    while(n != 0){
        r = n % 16;

        if(r < 10)
            s[i] = r + '0';
        else
            s[i] = r + 'A' - 10;

        i++;
        n = n / 16;
    }

    reverse(s);
}
