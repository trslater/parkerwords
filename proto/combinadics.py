"""Combinadic Index Finder

Searches a list of words for combinations, groups them, and indexes them by
their combinatorial number.
"""

from math import comb
import sys


def main():
    anagram_sets = combinadics(map(str.strip, sys.stdin))
    
    for i, anagrams in enumerate(anagram_sets):
        if anagrams:
            print(i, end=" ")

            for anagram in anagrams:
                print(anagram, end=" ")
            
            print()
    

def combinadics(word_gen):
    anagram_sets = tuple(set() for _ in range(comb(26, 5)))

    for word in word_gen:
        if len(word) == 5 and has_no_repeats(word):
            anagram_sets[index(offset(word))].add(word)

    return anagram_sets


def has_no_repeats(word):
    return len(word) == len(set(word))


def offset(word):
    return tuple(ord(c) - ord('a') for c in word)


def index(combo):
    return sum(comb(ck, k) for k, ck in enumerate(sorted(combo), start=1))


if __name__ == "__main__":
    main()
