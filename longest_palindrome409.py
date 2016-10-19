# the code not has clearly solution thought at first

class Solution(object):
    def longestPalindrome(self, s):
        """
        :type s: str
        :rtype: int
        """
        char_count = collections.Counter(s)
        odd_count = filter(lambda x : x % 2, char_count.values())
        odd_not_one_count = filter(lambda x : x - 1, odd_count)
        even_sum = sum([0] + filter(lambda x: not x % 2, char_count.values()))
        odd_not_one_sum = sum([0] + map(lambda x : x - 1, odd_not_one_count))
            
        return even_sum + odd_not_one_sum + len(odd_count) > 0
# simplify the code..

class Solution(object):
    def longestPalindrome(self, s):
        """
        :type s: str
        :rtype: int
        """
        char_count = collections.Counter(s)
        odd_count = filter(lambda x : x % 2, char_count.values())
        all_sum = sum([0] + char_count.values())
            
        return all_sum - len(odd_count) + (len(odd_count) > 0)

