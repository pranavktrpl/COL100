def factorial(a):
    if a<0:
        exit()
    elif a==1 or a==0:
        fact = 1
    else:
        fact = a * factorial(a-1)
    return fact

n = int(input())

print('%.2f' %factorial(n))