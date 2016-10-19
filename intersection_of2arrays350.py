class Solution(object):
    def intersect(self, nums1, nums2):
        """
        :type nums1: List[int]
        :type nums2: List[int]
        :rtype: List[int]
        """
        relist = []
        for i in nums1:
            if i in nums2:
                relist.append(i)
                nums2.remove(i)
        return relist
