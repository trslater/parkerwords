// https://raw.githubusercontent.com/dwyl/english-words/master/words_alpha.txt

// TODO: write words directly into words

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "parkerwords.h"

int main(int argc, char const *argv[])
{
    FILE *words_file = fopen(argv[1], "r");
    if (words_file == NULL)
        return 1;

    long long max_words = INIT_MAX_WORDS;
    long long num_words = 0;
    char (*words)[WORD_LEN + 1];
    words = malloc(max_words*sizeof(*words));
    char word[WORD_LEN + 1];
    char c;
    int i = 0;      // Line counter
    int j = 0;      // Char counter
    int valid = 1;

    while ((c = fgetc(words_file)) != EOF)
    {
        for (int k = 0; k < j; ++k) {
            if (word[k] == c && j < WORD_LEN) {
                valid = 0;
                break;
            }
        }

        // If at end of line
        if (c == '\n')
        {
            // If end of line is at end of desired word length
            if (j == WORD_LEN && valid) {
                // printf("Max words: %lld\n", max_words);
                if (num_words == max_words) {
                    max_words *= 2;
                    // printf("Updated max words: %lld\n", max_words);
                    words = realloc(words, (WORD_LEN + 1)*max_words);
                }
                
                // printf("Word %lld: %s\n", num_words, word);
                strncpy(words[num_words], word, WORD_LEN);
                ++num_words;
            }
         
            ++i;        // Advance line
            j = 0;      // Reset read head
            valid = 1;
        }
        else {
            // Part of valid word
            if (j < WORD_LEN) word[j] = c;
            ++j;
        }
    }

    fclose(words_file);


    for (int l = 0; l < num_words; ++l) {
        printf("%s ", words[l]);

        if (l % 10 == 0) {
            printf("\n");
        }
    }

    printf("\n");
    printf("Word count: %lld\n", num_words);

    free(words);
    return 0;
}
