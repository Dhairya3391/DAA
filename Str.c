// input = abc#de$
// output = edc#ba$
#include <stdio.h>

#define IS_SPECIAL(c) (!((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z') || (c >= '0' && c <= '9')))

int main() {
    char str[100], result[100];
    int i, len = 0;

    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);

    for (i = 0; str[i] && str[i] != '\n'; i++) {
        len++;
    }

    int j = 0;
    for (i = len - 1; i >= 0; i--) {
        if (!IS_SPECIAL(str[i])) {
            result[j++] = str[i];
        }
    }

    j = 0;
    for (i = 0; i < len; i++) {
        if (IS_SPECIAL(str[i])) {
            result[i] = str[i];
        } else {
            result[i] = result[j++];
        }
    }

    result[len] = '\0';
    printf("Modified string: %s\n", result);
    return 0;
}
