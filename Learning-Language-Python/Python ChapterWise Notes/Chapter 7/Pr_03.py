a = int(input("Enter a number for what you want table: "))
b = int(input("Enter a number till what you want the table: "))
count = 1
while count <=b:
    print(a, "*", count, "=", a*count)
    count+=1
