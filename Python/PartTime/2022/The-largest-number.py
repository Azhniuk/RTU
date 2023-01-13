def sort(array_name):
    for i in range(len(array_name)):
        swapped = False
        for j in range(0, len(array_name) - i - 1):
            if array[j] > array[j + 1]:
                a = array[j]
                array[j] = array[j+1]
                array[j+1] = a
                swapped = True
                if not swapped:
                    break

array = []
number_of_items = int(input("How many numbers? "))
print("Write number+enter:")

for i in range(0, number_of_items):
    array.append(int(input()))

sort(array)

print (array[len(array)-1], "is the largest of that", number_of_items, "numbers") 
