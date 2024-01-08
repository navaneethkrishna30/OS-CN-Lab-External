#include <stdio.h>
#include <string.h>

int main() {
    char data[20], str[100];
    int i, len;
    printf("Enter the data: ");
    scanf("%s", data);
    len = strlen(data);
    strcpy(str, "stxdle");
    i = 0;
    while (i < len - 2)
    {
            if (data[i]=='d' && data[i+1] =='l' && data[i+2]=='e')
            {
                strcat(str, "dledle");
                i += 2;
            }
            else
            {
                strncat(str, &data[i], 1);
            }
            i++;
    }

    strcat(str, &data[i]);
    strcat(str, "etxdle");
    printf("%s\n", str);

    return 0;
}
