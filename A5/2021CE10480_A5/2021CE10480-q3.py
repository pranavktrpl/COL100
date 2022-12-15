def padovan(a):
    if a==0 or a==1 or a==2 :
        p = 1
    else:
        p = padovan(a-2) + padovan(a-3)

    return p

n = int(input())

print('%.2f' %padovan(n))