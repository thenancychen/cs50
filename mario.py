import cs50

# takes user input
height = 0
while height < 1 or height > 8:
    height = cs50.get_int("Height: ")

# for loop to create pyramid   
for i in range(height):
    print(" " * (height - i - 1), end="")
    print("#" * (i + 1), end="")
    print("\n", end="")
    
