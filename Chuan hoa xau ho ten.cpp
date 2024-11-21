#include <stdio.h>
#include <ctype.h>
#include <string.h>


void chuan_hoa_ho_ten(char ho_ten[]) {
    int i = 0;
    int len = strlen(ho_ten);
    int start = 0;
    while (ho_ten[start] == ' ' && start < len) {
        start++;
    }
    
    
    for (i = start; i < len; i++) {
        if (i == start || ho_ten[i - 1] == ' ') {
            ho_ten[i] = toupper(ho_ten[i]);
        }
        else {
            ho_ten[i] = tolower(ho_ten[i]);
        }
    }
    
    for (i = len - 1; i >= 0 && ho_ten[i] == ' '; i--) {
        ho_ten[i] = '\0';
}

    for (i = start; i < len; i++) {
        if (ho_ten[i] == ' ' && ho_ten[i + 1] == ' ') {
            int j = i;
            while (ho_ten[j + 1] == ' ') {
                for (int k = j + 1; k < len; k++) {
                    ho_ten[k] = ho_ten[k + 1];
                }
            }
        }
    }
}

int main() {
    char ho_ten[100];
        printf("Nhap ho ten: ");
    fgets(ho_ten, sizeof(ho_ten), stdin);
        ho_ten[strcspn(ho_ten, "\n")] = '\0';
    chuan_hoa_ho_ten(ho_ten);
    printf("ho ten chuan hoa: %s\n", ho_ten);
    
    return 0;
}

