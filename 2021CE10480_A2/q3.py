#subject1
c1 = int(input())
g1 = int(input())

#subject2
c2 = int(input())
g2 = int(input())

#subject3
c3 = int(input())
g3 = int(input())

#subject4
c4 = int(input())
g4 = int(input())

#subject5
c5 = int(input())
g5 = int(input())

weighted_sum = c1*g1 + c2*g2 + c3*g3 + c4*g4 + c5*g5
totalcredits = c1+c2+c3+c4+c5

sgpa = ( int( ( float(weighted_sum/totalcredits) )*100 ) )/100

print(sgpa)