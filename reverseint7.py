class Solution(object):
    def reverse(self, x):
        """
        :type x: int
        :rtype: int
        """
        INT_MAX = pow(2,31) - 1
        INT_MIN = -pow(2,31) + 1
        a = int(str(x)[::-1]) if x > 0 else -int(str(-x)[::-1])
        if a > INT_MAX or a < INT_MIN:
            a = 0
        return a
        
