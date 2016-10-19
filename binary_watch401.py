class Solution(object):
    def readBinaryWatch(self, num):
        """
        :type num: int
        :rtype: List[str]
        """
        if not num:
            return ['0:00']
        # 'xx:00'
        rlist = [str(i) + ':00' for i in range(12) if bin(i)[2:].count('1') == num] if num > 5 else []
        # '0:xx'
        min_list = ['0:0' + str(i) if i < 10 else '0:' + str(i) for i in range(60) if bin(i)[2:].count('1') == num]
        rlist.extend(min_list)
        for j in range(1, num + 1):
            if j > 4:
                break
            hour_list = [str(i) for i in range(12) if bin(i)[2:].count('1') == j]
            min_list = [':0' + str(i) if i < 10 else ':' + str(i) for i in range(60) if bin(i)[2:].count('1') == num - j]
            permu_list = [i + k for i in hour_list for k in min_list]
            rlist.extend(permu_list)
        return rlist
