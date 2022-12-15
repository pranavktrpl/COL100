n = int(input())

for i in range(1,n+1,1):
    for j in range(1,2*i,1):
        print("*",end='')
    print("\n")

for i in reversed(range(1,n,1)):
    for j in range(1,2*i,1):
        print("*",end='')
    print("\n")