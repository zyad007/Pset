from cs50 import get_int

n = get_int("Height: ")

while True:
    if n > 8 or n < 1:
        n = get_int("Height: ")
    else:
        break

for i in range(n):
    for k in range(n-i-1):
        print(" ", end = "")
    
    for j in range(i+1):
        print("#", end = "")
    print()