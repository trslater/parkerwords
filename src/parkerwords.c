// https://raw.githubusercontent.com/dwyl/english-words/master/words_alpha.txt

// TODO: write words directly into words

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "parkerwords.h"

#define NUM_COMBOS 65780
#define WORD_LEN 5

long combo_num(char *);
long ncr(long, long);
long falling_fact(long, long);

int main(int argc, char const *argv[])
{
    FILE *words_file = fopen(argv[1], "r");
    if (words_file == NULL)
        return 1;

    // int used[NUM_COMBOS] = {0};

    char c;
    char word[WORD_LEN + 1];
    int i = 0;

    int t = 0;
    while ((c = fgetc(words_file)) != EOF)
    {
        if (c == '\n')
        {
            if (i == WORD_LEN)
            {
                printf("%s\n", word);
                // long i = combo_num(word);
                // printf("%ld\n", i);
                ++t;
            }
            i = 0;
            continue;
        }
        else if (i < WORD_LEN)
        {
            word[i] = c;
        }
        ++i;
    }

    fclose(words_file);
    return 0;
}

long combo_num(char *s)
{
    long i = 0;

    for (int k = 1; k <= WORD_LEN; ++k)
    {
        long ck = (long)(*s) - 97;
        i += ncr(ck, k);
        ++s;
    }

    return i;
}

long ncr(long n, long r)
{
    if (n < r) return 0;
    // Minimize number of multiplications
    long d = n - r;
    long k = (d < r) ? d : r;

    return falling_fact(n, k)/falling_fact(k, k);
}

long falling_fact(long n, long r)
{
    long f = 1;

    for (long t = n; t > (n - r); --t)
        f *= t;

    return f;
}
