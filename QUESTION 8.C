#include <stdio.h>
#include <stdbool.h>
bool nfa_transition(int current_state, char input) {
    if (current_state == 0 && input == 'b') {
        return true;
    } else if (current_state == 1 && input == 'a') {
        return true;
    }
    return false;
}
bool simulate_nfa(const char *input_string) {
    int current_state = 0;
    int i;
    for (i = 0; input_string[i] != '\0'; ++i) {
        if (nfa_transition(current_state, input_string[i])) {
            current_state++;
        }
    }
    return current_state == 2;
}
int main() {
    char input[100];
    printf("Enter a string: ");
    scanf("%s", input);
    if (simulate_nfa(input)) {
        printf("String is accepted by the NFA.\n");
    } else {
        printf("String is not accepted by the NFA.\n");
    }
    return 0;
