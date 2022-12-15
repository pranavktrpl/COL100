# series is (-1)^n/x^2n

x = float(input())
n = int(input())

for i in range(1,n+1,1):
    value = ((-1)**i)/((x)**(2*i))
    print('%.2f' %value)