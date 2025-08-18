#include <stdio.h>
int main() {
    char str[50];
    printf("Enter a string: \n");
    fgets(str, sizeof(str), stdin); 
    printf("Entered String; %s\n", str);
    int count=0;
    for (int i = 0; i < strlen(str); i++) 
    {
        if (str[i] == ' ')
         {
         count ++;
        }
        
    }
 
 printf("Number of Words = %d\n", count);
    return 0;
}