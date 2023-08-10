#include <stdio.h>
#include <string.h>
int belongsToLanguage(const char *str, int start, int end) {
    if (start > end) {
        return 1;
    }
    if (start == end) {
        return (str[start] == '0' || str[start] == '1');
    }
    int i, j;
    for (i = start; i <= end; ++i) {
        if (str[i] != '0' && str[i] != '1') {
            return 0;
        }
    }
    for (i = start + 1; i <= end - 1; ++i) {
        if ((str[start] == '0' && str[end] == '0') ||
            (str[start] == '1' && str[end] == '1')) {
            if (belongsToLanguage(str, start + 1, i - 1) && belongsToLanguage(str, i + 1, end - 1)) {
                return 1;
            }
        }
    }
    return 0;
}
int main() {
    char input[100];
    printf("Enter a string: ");
    scanf("%s", input);
    int length = strlen(input);
    if (belongsToLanguage(input, 0, length - 1)) {
        printf("String belongs to the CFG language.\n");
    } else {
        printf("String does not belong to the CFG language.\n");
    }
    return 0;
}
