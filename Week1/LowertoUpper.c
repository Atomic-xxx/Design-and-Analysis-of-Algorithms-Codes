#include <stdio.h>
int main() {
    char str[50];
    printf("Enter a string: \n");
    fgets(str, sizeof(str), stdin); 
    printf("Entered String; %s\n", str);
    for (int i = 0; i < strlen(str); i++) 
    {
        if (str[i] >= 'a' && str[i] <= 'z')
         {
         str[i] = str[i] - 32;
        }
        
    }
 
 printf("Updated String : %s\n", str);
    return 0;
}