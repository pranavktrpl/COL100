#radius
r = float(input())

#sideofsquare
a = float(input())

#sides of rectangle
l = float(input())
b = float(input())

#base and height of parallelogram
base = float(input())
height = float(input())

#trapezium
side1 = float(input())
side2 = float(input())
dist = float(input())

#areaofcircle
print ( ( int( ( 3.14*(r**2) )*100 ) )/100 )

#area of square
print ( ( int( ( a**2 )*100 ) )/100 )

#area of rectangle
print ( ( int( (l*b)*100 ) )/100 )

#area of parallelogram
print ( ( int( (base*height)*100 ) )/100 )

#trapezium area
print ( ( int( ( (side1+side2)*0.5*dist )*100 ) )/100 )