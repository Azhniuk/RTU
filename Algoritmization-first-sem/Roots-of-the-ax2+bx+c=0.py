import math

print ("Write a b and c for the equation ax2+bx+c=0:")
a = int(input("a = "))
b = int(input("b = "))
c = int(input("c = "))

D=float(b**2 - 4*a*c)

if D<0 :
    print("No roots")

elif D==0:
    print("Ok")
    
else:
    x1 =( -b + math.sqrt(D) )/(2*a)
    x2 =( -b - math.sqrt(D) )/(2*a)
    print("x1 is: ", x1, "\nx2 is: ", x2)
