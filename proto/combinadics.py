"""Combinadic Index Finder

Searches a list of words for combinations, groups them, and indexes them by
their combinatorial number.
"""

from math import comb
import sys


def main():
    words = combinatics(map(str.strip, sys.stdin))
    
    for i, anagrams in enumerate(words):
        if anagrams:
            print(i, anagrams)


def combinatics(word_gen):
    words = tuple([] for _ in range(comb(26, 5)))

    for word in word_gen:
        if len(word) == 5 and has_no_repeats(word):
            words[index(offset(word))].append(word)

    return words


def has_no_repeats(word):
    return len(word) == len(set(word))


def offset(word):
    return tuple(ord(c) - ord('a') for c in word)


def index(combo):
    return sum(comb(ck, k) for k, ck in enumerate(sorted(combo), start=1))


if __name__ == "__main__":
    main()
