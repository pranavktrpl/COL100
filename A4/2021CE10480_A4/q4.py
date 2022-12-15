n = int(input())

for i in range(1,n+1,1):
    for j in range(1,n+1,1):
        if j<i:
            print(" ",end='')
        else:
            char = 64 + i
            print(chr(char),end='')
    print("\n")