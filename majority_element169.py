class Solution(object):
    def majorityElement(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        count = collections.Counter(nums)
        for k, v in count.iteritems():
            if v > len(nums)/2:
                return k

# simplify
class Solution(object):
    def majorityElement(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        count = collections.Counter(nums)
        return [k for k, v in count.iteritems() if v > len(nums) / 2][0]
        ###????

