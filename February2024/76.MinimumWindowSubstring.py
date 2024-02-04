""""
Description:
Given two strings s and t of lengths m and n respectively,
return the minimum window substring of s such that every 
character in t (including duplicates) is included in the window.
If there is no such substring, return the empty string "".
"""

class Solution:
    def minWindow(self, s: str, t: str) -> str:
        #incialize variables and dictinaries
        j = 0
        i = 0        
        SubCount = {}
        tCount = {}
        finalSub = ""
        minLen = len(s)
        # dictionary for string t
        for char in t:
                tCount[char] = tCount.get(char, 0) + 1
        # main loop finifng smalles subString
        while j != (len(s) + 1):
            SubS = s[i:j]
             # dictionary for Substring from s
            for char in SubS:
                SubCount[char] = SubCount.get(char, 0) + 1
            #check if all chars from string t are in SubS
            for key in tCount.keys():
                same = True
                if key in SubCount and tCount[key] <= SubCount[key]:
                    continue
                else:
                    same = False
                    break
            # new min Substring, move left part of window
            if same:
                if len(SubS) <= minLen:
                    finalSub = SubS
                    minLen = len(finalSub)
                i += 1
            # move right part of window
            else:
                j += 1
            SubCount = {}

        return finalSub


def main():

    solution = Solution()
    input_s = "abdaa"
    input_t = "aa"
    result = solution.minWindow(input_s, input_t)
    print("Minimum window:", result)


if __name__ == "__main__":
    main()
