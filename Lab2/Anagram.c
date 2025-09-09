#include <stdio.h>
#include <string.h>
void bubbleSort(char arr[], int n)
 {
    int i, j;
    char temp;
    for (i = 0; i < n - 1; i++)
     {
        for (j = 0; j < n - i - 1; j++) 
        {
            if (arr[j] > arr[j + 1]) 
            {
                
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main() {
    char str1[100], str2[100];
    char arr1[100], arr2[100];
    int len1, len2;
    printf("Enter first string: ");
    scanf("%s", str1);
    printf("Enter second string: ");
    scanf("%s", str2);
    len1 = strlen(str1);
    for (int i = 0; i < len1; i++) {
        arr1[i] = str1[i];
    }
     arr1[len1] = '\0';
    bubbleSort(arr1,len1);
    len2 = strlen(str2);
    for (int i = 0; i < len2; i++) {
        arr2[i] = str2[i];
    }
     arr2[len2] = '\0';
    bubbleSort(arr2,len2);
    if (strcmp(arr1, arr2) == 0) {
        if (strcmp(str1, str2) == 0) {
            printf("The two strings are SAME\n");
        } else {
            printf("The two strings are ANAGRAMS\n");
        }
    } else {
        printf("The two strings are NOT anagrams\n");
    }
    return 0;
}