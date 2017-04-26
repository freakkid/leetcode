class Solution(object):
    def romanToInt(self, s):
        """
        :type s: str
        :rtype: int
        """
        numerals = {'I':1,'V':5,'X':10,'L':50,'C':100,'D':500,'M':1000}
        dec = numerals[s[0]]
        for i in range(1, len(s)):
            if numerals[s[i]] > numerals[s[i-1]]:
                dec = numerals[s[i]] - 2*numerals[s[i-1]]
            else:
                dec += numerals[s[i]]

        return dec

