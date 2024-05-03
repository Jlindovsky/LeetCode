""""
Difficulty: Medium
Topics: Array, Hash Table, String, Sorting
Description:
Given an array of strings strs, group the anagrams together.
You can return the answer in any order. An Anagram is a word
or phrase formed by rearranging the letters of a different
word or phrase, typically using all the original letters exactly once.
"""

from collections import defaultdict
from typing import List

class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        #dictionary that keys are signatures and values are string from list
        anagrams = defaultdict(list)

        for word in strs:
            signature = ''.join(sorted(word))
            anagrams[signature].append(word)
        return list(anagrams.values())


def main():

    solution = Solution()
    strs = ["eat", "tea", "tan", "ate", "nat", "bat"]
    result = solution.groupAnagrams(strs)
    print(result)

if __name__ == "__main__":
    main()

