""""
Difficulty: Easy
Description:
Given a string s, find the first non-repeating
character in it and return its index.
If it does not exist, return -1.
"""
class Solution:
    def firstUniqChar(self, s: str) -> int:
        # dictionary for chars in string
        charCount = {}
        #filling dictionary
        for char in s:
            charCount[char] = charCount.get(char, 0) +1
        #finding first value 1 and returning index of char with this value
        for key,value in charCount.items():
            if value == 1:
                return s.index(key)
        return -1

def main():

    solution = Solution()
    input_s = "abdaa"
    result = solution.firstUniqChar(input_s)
    print("First unique char:", result)

if __name__ == "__main__":
    main()
