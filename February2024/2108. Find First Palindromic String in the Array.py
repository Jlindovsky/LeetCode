""""
Difficulty: Easy
Topics: Array, Two Pointers, String
Description:
Given an array of strings words, return the first palindromic string
in the array. If there is no such string, return an empty string "".
A string is palindromic if it reads the same forward and backward.
"""

from ast import List


class Solution:
    def firstPalindrome(self, words: List[str]) -> str:
        result = ""
        for string in words:
            left = 0
            right = len(string)-1
            while left <=right:
                if string[left] != string[right]:
                    break
                left = left +1
                right = right -1
            if left > right:
                result = string
                return result
        return result
    
def main():
    solution = Solution()
    strs = ["eat", "tea", "nan", "ate", "nat", "bat"]
    result = solution.firstPalindrome(strs)
    print(result)

if __name__ == "__main__":
    main()