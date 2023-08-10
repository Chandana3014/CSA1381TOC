#include <stdio.h>
#include <string.h>
int belongsToLanguageA(const char *str, int start, int end) {
    if (start > end) {
        return 1; 
    }
    if (str[start] == '0' || str[start] == '1') {
        int i;
        for (i = start + 1; i <= end; ++i) {
            if (belongsToLanguageA(str, start + 1, i - 1) && belongsToLanguageA(str, i, end)) {
                return 1;
            }
        }
    }
    return 0;
}
int belongsToLanguageS(const char *str, int start, int end) {
    if (start > end) {
        return 0; 
    }
    if (str[start] == '1' && str[end] == '1' && str[end - 1] == '0') {
        return belongsToLanguageA(str, start + 1, end - 2);
    }
    return 0; 
}
int main() {
    char input[100];
    printf("Enter a string: ");
    scanf("%s", input);
    int length = strlen(input);
    if (belongsToLanguageS(input, 0, length - 1)) {
        printf("String belongs to the CFG language.\n");
}else{
print("string does not belong to the CFG language.\n");
}
return 0;

