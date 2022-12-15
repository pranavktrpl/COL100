from operator import sub


def addition(x,y):
    sum = int(x + y)
    return sum

def subtraction(x,y):
    subt = int(x - y)
    return subt

def multiplication(x,y):
    prodct = int(x*y)
    return prodct

def division(x,y):
    if y==0:
        exit()
    else:
        div = (x//y)
        return div

def modulus(x,y):
    if y==0:
        exit()
    else:
        mod = int(x%y)
        return mod

a = int(input())
b = int(input())

print(addition(a,b))
print(subtraction(a,b))
print(multiplication(a,b))
print(division(a,b))
print(modulus(a,b))