class Solution:
    def reverseWords(self, s: str) -> str:
        words = s.split()
        words.reverse()
        ans = ""
        for word in words:
            ans += word
            ans += " "
        return ans.strip()