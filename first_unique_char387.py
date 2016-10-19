class Solution(object):
    def firstUniqChar(self, s):
        """
        :type s: str
        :rtype: int
        """
        char_count = collections.Counter(s)
        for i in s:
            if char_count[i] == 1:
                return s.index(i)
        else:
            return -1
