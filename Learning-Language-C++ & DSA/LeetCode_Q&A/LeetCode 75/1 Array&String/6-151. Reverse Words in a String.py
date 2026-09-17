class Solution:
    def reverseWords(self, s: str) -> str:
        # s.split() automatically handles multiple spaces and trims whitespace
        words = s.split()
        
        # Reverse the list of words and join them with a single space
        return " ".join(words[::-1])


# class Solution:
#     def reverseWords(self, s: str) -> str:
#         return " ".join(s.split()[::-1])