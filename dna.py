import csv
from sys import argv, exit

# Check argv nub of Input files
if len(argv) != 3:
    print("Erorr")
    exit(0)

# Open CSV file and read it
with open(argv[1], "r") as DNA_file:
    reader = list(csv.reader(DNA_file))
    reader[0].remove('name')
    i = reader[0]
    datalist = reader

# Open sequence of DNA text to compare it with pepole data
with open(argv[2], "r") as sec_text:
    text = sec_text.read()

c = 0
maX = 0
valid = []
for q in range(len(i)):    
    c = 0
    maX=1
    for j in range(len(text)):
        
        if text.find(i[q],j,j+len(i[q])) != -1:
            c += 1
            if c > maX:
                maX = c
            if i[q] != text[j+len(i[q]):j+len(i[q])*2]:
                c=0    
    valid.append(str(maX))
    
true = []
com = []
for k in range(len(valid)):
    true.append(1)

for x in range(len(datalist)):
    name = datalist[x][0]
    datalist[x].pop(0)
    
    if valid == datalist[x]:
        print(name)
        exit(1)

print("No match")
exit(2)