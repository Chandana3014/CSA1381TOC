#include <stdio.h>
#include <stdbool.h>
int dfa_transition(int state, char input) {
    switch (state) {
        case 0:
            if (input == 'a') return 1;
            else return 0;
        case 1:
            if (input == 'a') return 1;
            else return 2;
        case 2:
            return 2;
    }
    return -1; 
}
int main() {
    int current_state = 0;
    char input_string[100];
    printf("Enter an input string: ");
    scanf("%s", input_string);
    for (int i = 0; input_string[i] != '\0'; i++) {
        current_state = dfa_transition(current_state, input_string[i]);
        if (current_state == -1) {
            printf("Invalid input string.\n");
            return 0;
        }
    }
    if (current_state == 1) {
        printf("Accepted: The input string starts with 'a' and ends with 'a'.\n");
    } else {
        printf("Rejected: The input string does not satisfy the language.\n");
    }
    return 0;
}
