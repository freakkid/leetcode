class Solution(object):
    def fizzBuzz(self, n):
        """
        :type n: int
        :rtype: List[str]
        """
        relist = ['1',]
        for i in range(1, n):
            if n % 3 and n % 5 or n < 3:
                relist.append(str(i))
            elif n % 3:
                relist.append('Fizz')
            elif n % 5:
                relist.append('Buzz')
            else:
                relist.append('FizzBuzz')
                
        return relist
        
