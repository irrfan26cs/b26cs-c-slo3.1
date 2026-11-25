#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

#define MAX_SENTENCE_LEN 1024
#define MAX_WORD_LEN 128

static bool is_delimiter(char ch) {
    return ch == '\0' || isspace((unsigned char)ch) || ispunct((unsigned char)ch);
}

static bool words_match(const char *a, const char *b) {
    while (*a != '\0' && *b != '\0') {
        if (tolower((unsigned char)*a) != tolower((unsigned char)*b)) {
            return false;
        }
        a++;
        b++;
    }
    return *a == '\0' && *b == '\0';
}

int count_word_frequency(const char *sentence, const char *target) {
    if (sentence == NULL || target == NULL || target[0] == '\0') {
        return 0;
    }

    int count = 0;
    size_t i = 0;

    while (sentence[i] != '\0') {
        while (sentence[i] != '\0' && is_delimiter(sentence[i])) {
            i++;
        }
        if (sentence[i] == '\0') {
            break;
        }

        char current_word[MAX_WORD_LEN];
        size_t len = 0;
        while (sentence[i] != '\0' && !is_delimiter(sentence[i])) {
            if (len + 1 < MAX_WORD_LEN) {
                current_word[len++] = sentence[i];
            }
            i++;
        }
        current_word[len] = '\0';

        if (words_match(current_word, target)) {
            count++;
        }
    }

    return count;
}

int main(void) {
    char sentence[MAX_SENTENCE_LEN];
    char target[MAX_WORD_LEN];

    printf("Enter a sentence: ");
    if (fgets(sentence, sizeof(sentence), stdin) == NULL) {
        return 1;
    }
    sentence[strcspn(sentence, "\n")] = '\0';

    printf("Enter the word to count: ");
    if (fgets(target, sizeof(target), stdin) == NULL) {
        return 1;
    }
    target[strcspn(target, "\n")] = '\0';

    int frequency = count_word_frequency(sentence, target);
    printf("Frequency of \"%s\": %d\n", target, frequency);

    return 0;
}
