import matplotlib.pyplot as plt
import math
plt.title("Bresenham Algorithm")
plt.xlabel("x axis")
plt.ylabel("y axis")



xBeg, x = 0
yBeg, y = 0
xEnd = 6
yEnd = 3
xCoordinates = [xBeg]
yCoordinates = [yBeg]


def arrayCreation (xBeg, yBeg, xEnd, yEnd):
    dx = abs(xEnd - xBeg)
    dy = abs(yEnd - yBeg)
    

    if xBeg < xEnd :
        xs = 1
    else:
        xs = -1

    if yBeg < yEnd :
        ys = 1
    else:
        ys = -1

    if dx > dy:
        p0 = 2*dy - dx
        pn = p0
        for x in range (dx):
            xCoordinate = x + xs
            xCoordinates.append(xCoordinate)
        
        for y in range (dy):
            if pn > 0:
                y = y + ys
            else:
                yCoordinates.append(y)
                pn = pn + (2*dy)    



        print(xCoordinates)
        print(yCoordinates)
        
        

            
                







arrayCreation (xBeg, yBeg, xEnd, yEnd)
#plt.plot(xCoordinates, yCoordinates)
plt.show()