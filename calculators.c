#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

void calculate(int i, char *input, int n, char op);
void space_remover(char *input, int *n);

int main() {
    while(1) {
        char input[100];
        printf("Enter the expression: ");
        fgets(input, sizeof(input), stdin);
        int n = strlen(input);
        
        if (input[n - 1] == '\n') {
            input[n - 1] = '\0';
            n--;
        }
        space_remover(input, &n);
        for (int i = 0; i < n; i++) {
            if (input[i] == '/' || input[i] == '*') {
                calculate(i, input, n, input[i]);
                i = -1;
                n = strlen(input);
            }
        }
        for (int i = 0; i < n; i++) {
            if (input[i] == '+' || input[i] == '-') {
                calculate(i, input, n, input[i]);
                i = -1;
                n = strlen(input);
            }
        }
        printf("Result: %s\n", input);
    }
    return 0;
}

void calculate(int i, char *input, int n, char op) {
    int left = 0, right = 0, j = i - 1, k = i + 1;
    while (j >= 0 && isdigit(input[j])) {
        j--;
    }
    left = atoi(&input[j + 1]);
    while (k < n && isdigit(input[k])) {
        k++;
    }
    right = atoi(&input[i + 1]);
    if (op == '/' && right == 0) {
        printf("Error: Division by zero.\n");
        exit(0);
    }
    int result = 0;
    if (op == '/') {
        result = left / right;
    } else if (op == '*') {
        result = left * right;
    } else if (op == '+') {
        result = left + right;
    } else if (op == '-') {
        result = left - right;
    }
    char updated[100];
    snprintf(updated, sizeof(updated), "%.*s%d%s", j + 1, input, result, &input[k]);
    strcpy(input, updated);
}

void space_remover(char *input, int *n) {
    int p = 0, q = 0;
    while (input[p]) {
        if (isdigit(input[p]) || strchr("/*+-", input[p])) {
            input[q++] = input[p];
        } else if (input[p] != ' ') {
            printf("Error: Invalid expression.\n");
            exit(0);
        }
        p++;
    }
    input[q] = '\0';
    *n = strlen(input);
}
