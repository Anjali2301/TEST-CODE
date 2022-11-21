def countinString(ch, s):
    if (len(s) == 0):
        return 0
    count = 0
    if (s[0] == ch):
        count += 1
    count += countinString(ch, s[1:])
    return count
str1 = input("Enter 1st String:- ")
str2=input("Enter 2nd String:- ")
c=str2[-1]
print(countinString(c, str1))
