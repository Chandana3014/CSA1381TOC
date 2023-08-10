#include <stdio.h>
int dfa_transition(int current_state, char input) {
    switch (current_state) {
        case 0:
            if (input == '0') return 1;
            break;
        case 1:
            if (input == '1') return 2;
            if (input == '0') return 1;
            break;
        case 2:
            if (input == '1') return 2;
            if (input == '0') return 1;
            break;
    }
    return -1;
}
int simulate_dfa(const char *input_string) {
    int current_state = 0;
    for (int i = 0; input_string[i] != '\0'; ++i) {
        current_state = dfa_transition(current_state, input_string[i]);
        if (current_state == -1) {
            return 0; 
        }
    }
    return (current_state == 2); 
}
int main() {
    char input[100];
    printf("Enter a string: ");
    scanf("%s", input);
    if (simulate_dfa(input)) {
        printf("String is accepted by the DFA.\n");
    } else {
        printf("string is not accepted by the DFA.\n");
}
return 0;
