#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_LEN 1000  


void findLongestWords(char str[]) {
    char words[MAX_LEN][MAX_LEN];  
    int wordCount = 0;  
    int maxLen = 0; 
    int i, j = 0;

    
    for(i = 0; i <= strlen(str); i++) {
        
        if(isalpha(str[i]) || str[i] == '\0') {
            if(isalpha(str[i])) {
                words[wordCount][j++] = str[i];
            } else {
                words[wordCount][j] = '\0';  
                if(j > maxLen) {
                    maxLen = j;  
                }
                j = 0;  
                wordCount++;  
            }
        }
    }


    printf("Cac tu dai nhat co do dai %d la:\n", maxLen);
    for(i = 0; i < wordCount; i++) {
        if(strlen(words[i]) == maxLen) {
            printf("%s\n", words[i]);
        }
    }
}

int main() {
    char str[MAX_LEN];

    printf("Nhap van ban:\n");
    fgets(str, sizeof(str), stdin);  
    findLongestWords(str);  

    return 0;
}

