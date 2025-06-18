num = int(input("Enter a number: "))

count = 1
num1 = 0
while count<=num:
    num2 = num1+ count
    num1 = num2
    count+=1

print("The sum of the first",num,"natural number is",num1)