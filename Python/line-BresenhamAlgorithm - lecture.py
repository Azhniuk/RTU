import matplotlib.pyplot as plt
import math
plt.title("Bresenham Algorithm")
plt.xlabel("x axis")
plt.ylabel("y axis")






def arrayCreation (xBeg, yBeg, xEnd, yEnd):
    xCoordinates = [xBeg]
    yCoordinates = [yBeg]
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
        p = 2*dy - dx
        pn = p
        for x in range (dx):
            x = x + xs
            xCoordinates.append(x)
        
        for y in range (dy):
            if pn > 0:
                y = y + ys
            yCoordinates.append(y)
            pn = pn + (2*dy)  
    return



print(xCoordinates)
print(yCoordinates)
        
        

            
                







arrayCreation (0, 0, 5, 4)
#plt.plot(xCoordinates, yCoordinates)
#plt.show()
