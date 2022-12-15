import math

a = float(input())
b = float(input())
c = float(input())

d = (b**2) - (4*(a*c))                  #Discriminant

if d>=0:
    x1 = (-b + math.sqrt(d)) / (2*a)
    x2 = (-b - math.sqrt(d)) / (2*a)

    print('%.2f' %x1,"0.00")
    print('%.2f' %x2,"0.00")
else:
    x = (0 - (b / (2*a)) )
    y = (math.sqrt(-d)) / (2*a)
    
    print('%.2f' %x,'%.2f' %y)
    print('%.2f' %x,'%.2f' %-y)