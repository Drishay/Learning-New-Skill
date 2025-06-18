n = int(input("Enter number of rows: "))

a = 1
b = n-1
for i in range(1,n+1):
    print(" " * b , "*" * a , " " * b)
    a +=2
    b -=1