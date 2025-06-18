num = int(input("Enter a number: "))

if num ==1 or num ==0:
    print(f"Factorial of {num} is 1")
else:
    num1 = 1
    for i in range(1,num+1):
        num1 = num1*i
    print(f"Factorial of {num} is {num1}")