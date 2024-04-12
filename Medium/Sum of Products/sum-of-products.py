#User function Template for python3

class Solution:
        #code hereclass Solution:
    def pairAndSum(self, n, arr):
        #code here
        sum = 0
        for i in range(32):
            bits = 0
            for j in range(n):
                if arr[j] & (1<<i): 
                    bits += 1 
            sum += (1<<i) * ((bits * (bits-1))/2) 
        return int(sum)


#{ 
 # Driver Code Starts
#Initial Template for Python 3

if __name__=='__main__':
    t=int(input())
    for _ in range(t):
        N=int(input())
        Arr=list(map(int,input().strip().split(' ')))
        ob=Solution()
        print(ob.pairAndSum(N,Arr))
# } Driver Code Ends