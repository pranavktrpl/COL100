def pattern(a):
    if a<0:
        exit()
    elif a==0:
        return
    elif a>0:
        print(a,end='')
        pattern(a-1)
        print(a,end='')
        pattern(a-1)
        print(a,end='')
        return

n = int(input())
pattern(n)