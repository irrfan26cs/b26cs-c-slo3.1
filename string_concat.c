#include <stdio.h>
#include <string.h>

#define MAX_LEN 512

size_t get_string_length(const char *str) {
    size_t len = 0;
    if (str == NULL) {
        return 0;
    }
    while (str[len] != '\0') {
        len++;
    }
    return len;
}

void strip_newline(char *str) {
    size_t len = get_string_length(str);
    if (len > 0 && str[len - 1] == '\n') {
        str[len - 1] = '\0';
    }
}

int read_string(const char *prompt, char *buffer, size_t capacity) {
    printf("%s", prompt);
    if (fgets(buffer, (int)capacity, stdin) == NULL) {
        return 0;
    }
    strip_newline(buffer);
    return 1;
}

int concatenate_strings(char *dest, size_t dest_capacity, const char *source) {
    if (dest == NULL || source == NULL || dest_capacity == 0) {
        return -1;
    }

    size_t dest_len = get_string_length(dest);
    size_t src_len = get_string_length(source);

    if (dest_len >= dest_capacity) {
        return -1;
    }

    size_t available = dest_capacity - dest_len - 1;
    size_t to_copy = (src_len < available) ? src_len : available;

    for (size_t i = 0; i < to_copy; i++) {
        dest[dest_len + i] = source[i];
    }
    dest[dest_len + to_copy] = '\0';

    return (src_len <= available) ? 0 : 1;
}

int main(void) {
    char first[MAX_LEN];
    char second[MAX_LEN];

    if (!read_string("Enter the first string: ", first, sizeof(first))) {
        return 1;
    }
    if (!read_string("Enter the second string: ", second, sizeof(second))) {
        return 1;
    }

    int status = concatenate_strings(first, sizeof(first), second);
    if (status < 0) {
        fprintf(stderr, "Error: Invalid buffer.\n");
        return 1;
    }

    printf("Concatenated string: %s\n", first);
    if (status == 1) {
        printf("(Note: Second string was truncated to fit buffer size.)\n");
    }

    return 0;
}
