a = int(input())
x = float(input())

n = 1

for i in range(1,a+1,1):
    if (i%x==0):
        n = n*i

print('%.2f' %n)