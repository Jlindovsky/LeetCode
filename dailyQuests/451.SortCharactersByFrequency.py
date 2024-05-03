""""
Difficulty: Medium
Topics: Hash Table, String, Sorting,, Heap (Priority Queue), Bucket Sort, Counting
Description:
Given a string s, sort it in decreasing order basedon the frequency of the characters.
The frequency of a character is the number of times it appears in the string.
Return the sorted string. If there are multiple answers, return any of them.
"""

class Solution:
    def frequencySort(self, s: str) -> str:
        charCount = {}
        result = []
        # dictionary for number of chars in string
        for char in s:
            charCount[char] = charCount.get(char, 0) + 1
        # sorted dictionary from biggerst to lowest value
        sortedCount = dict(sorted(charCount.items(), key=lambda x: x[1],  reverse=True))

        for char, count in sortedCount.items():
            for i in range(count):
                result.append(char)
        return result
    
def main():

    solution = Solution()
    input_s = "abdaa"
    result = solution.frequencySort(input_s)
    print("Sorted by frequency:", result)

if __name__ == "__main__":
    main()