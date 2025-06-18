#import the necessary modules !
import random
import string


reply = input(" Hey there, welcome to password generator! ")

if reply == "Hey" or reply == "hey":
    print (" Ok ")

elif reply == "Hi" or reply == "hi":
    print (" Ok ")

elif reply == "Hello" or reply == "hello":
    print (" Ok ")

else:
    print (" Can't understand you....Sorry ")
    quit()

reply_2 = input(" So you need help for creating a password?   Yes or No    ")

if reply_2 == "Yes" or reply_2 == "yes":
    print(" I'll help you ")

elif reply_2 == "No" or reply_2 == "no":
    print(" Ok then, have a good day ")
    quit()

else:
    print(" invalid ")
    quit()


reply_3 = input(" For which thing you need a password? ")


#define data
lower = string.ascii_lowercase
upper = string.ascii_uppercase
num = string.digits
symbols = string.punctuation

#input the type of password
password = input(" Which password type you want?  A = Numeric    B = Alphabetic    C = Alphanumeric    ")

if password == "a" or password == "A" :
    print(" Numeric ")

    #input the length of password
    length = int(input(" Enter the length of password:  "))

    #combine the data
    all = num

    #use random
    temp = random.sample(all,length)

    #create the password
    password = "".join(temp)

    #save the password in a file i.e Numeric_Passes

    f = open ("Numeric_Passes.txt" , "a")
    f.write(str(password + '\n'))
    f.close()

    #save the password in a file i.e Alphanumeric_Passes

    f = open ("Alphanumeric_Passes.txt" , "a")
    f.write(str(password + '\n'))
    f.close()


elif password == "b" or password == "B" :
    print(" Alphabetic ")

    #input the length of password
    length = int(input(" Enter the length of password:  "))

    #combine the data
    all = lower + upper

    #use random
    temp = random.sample(all,length)

    #create the password
    password = "".join(temp)

    #save the password in a file i.e Alphabetic_Passes

    f = open ("Alphabetic_Passes.txt" , "a")
    f.write(str(password + '\n'))
    f.close()

    #save the password in a file i.e Alphanumeric_Passes

    f = open ("Alphanumeric_Passes.txt" , "a")
    f.write(str(password + '\n'))
    f.close()


elif password == "c" or password == "C" :
    print(" Alphanumeric ")

    #input the length of password
    length = int(input(" Enter the length of password:  "))

    #combine the data
    all = lower + upper + num + symbols

    #use random
    temp = random.sample(all,length)

    #create the password
    password = "".join(temp)

    #save the password in a file i.e Alphanumeric_Passes

    f = open ("Alphanumeric_Passes.txt" , "a")
    f.write(str(password + '\n'))
    f.close()


else:
    print(" error ")
    quit()

f = open ("Password.txt" , "a")
f.write(str("Your password for " + reply_3 + " is : " + password + '\n'))
f.close

print(" Your password for", reply_3 , "is : ", password)

