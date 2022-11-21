class Solution:
   def solve(self, k):
      sign = '-' if k<0 else ''
      k = abs(k)
      if k < 3:
         return str(k)
      s = ''
      while k != 0:
         s = str(k%3) + s
         k = k//3
      return sign+s
i=int(input("Enter a Number :- "))
ob = Solution()
print(ob.solve(i))
