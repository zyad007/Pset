from cs50 import get_float

n = get_float("Change owed: ")

while True:
    if n < 0:
        n = get_float("Change owed: ")
    else:
        break

s = n*100
c = 0

while s >= 25:
    s = s - 25
    c = c + 1
    
while s >= 10:
    s = s - 10
    c = c +1
    
while s >= 5:
    s = s - 5
    c = c +1

while s >= 1:
    s = s - 1
    c = c +1    

print(c)    