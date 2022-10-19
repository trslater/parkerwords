#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "parkerwords.h"

int main(int argc, char const *argv[])
{
    FILE *words_file = fopen(argv[1], "r");
    if (words_file == NULL)
        return 1;

    long long max_words = 10;
    long long num_words = 0;
    char (*words)[WORD_LEN + 1];
    words = malloc(max_words*sizeof(*words));
    char word[WORD_LEN + 1];
    char c;
    int i = 0;      // Line counter
    int j = 0;      // Char counter

    while ((c = fgetc(words_file)) != EOF)
    {
        // If at end of line
        if (c == '\n')
        {
            // If end of line is at end of desired word length
            if (j == WORD_LEN) {
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
        }
        else if (j < WORD_LEN) word[j++] = c;
    }

    for (int l = 0; l < num_words; ++l) {
        printf("%s\n", words[l]);
    }

    fclose(words_file);
    free(words);
    return 0;
}
