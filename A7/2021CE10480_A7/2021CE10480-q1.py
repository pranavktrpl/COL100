'''
Since the function runs on a loop for iterations 4 to 'num' it is running for n-3 times so the time complexity comes out for a loop to be O(n)
'''

def heaven(num : int) -> int:  # write your code in this function only
    # your's code start here 
    # remov pass and write your code
    if num>3:
        current = 4
        prev = 2
        pprev = 1
        for i in range(4,num+1):
            c = current
            current = current + prev + pprev
            pprev = prev
            prev = c 
        return current
    elif num == 3:
        return 4
    elif num == 2:
        return 2
    elif num == 1:
        return 1
    # return your's integer result
    # your's code end here 
    
    
if __name__=="__main__": # calling main (run automtically)
    num = int(input())   # taking input from user
    out = heaven(num)    # calling function in which you have written code
    print (out)          # printing the output of your's function
