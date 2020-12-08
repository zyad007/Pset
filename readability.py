from cs50 import get_string

t = get_string("Text: ")

letters = 0
words = 1
sentence = 0

for i in range(len(t)):

    if t[i].isalpha() == True:
        letters = letters + 1
    
    if t[i].isspace() == True:
        words = words + 1
    
    if t[i] == '.' or t[i] == '!' or t[i] == '?':
        sentence = sentence + 1


L = (letters / words )*100
S = (sentence / words )*100
index =round( 0.0588 * L - 0.296 * S - 15.8)

if index >= 16 :
    print("Grade 16+")
elif index < 1 :
    print("Before Grade 1")
else :
    print(f"Grade {index}")