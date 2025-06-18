reply = input(" Hey there, welcome to ID generator! ")

if reply == "Hey" or reply == "hey":
    print ("Ok")

elif reply == "Hi" or reply == "hi":
    print ("Ok")

elif reply == "Hello" or reply == "hello":
    print ("Ok")

else:
    print ("Can't understand you....Sorry")
    quit()

reply_2 = input(" So you need help for creating a Id?   Yes or No    ")

if reply_2 == "Yes" or reply_2 == "yes":
    print("I'll help you ")

elif reply_2 == "No" or reply_2 == "no":
    print("Ok then, have a good day")
    quit()

else:
    print("invalid")
    quit()


reply_3 = input(" What should your id namae start with? eg. abc.., xyz..,etc *Note: Write alphabets only* ")

# Input the range (x,y)

for i in range (0,10):
    a = str(i)
    f = open ("Id's.txt" , "a")
    # Password can generated through password_generator and for now password for all id's will be same
    f.write(reply_3 + a + '@gmail.com' + ' ==> '+'Password = {Ypsg<W"6q_);t'+ '\n')
    f.close
    print (reply_3 + a + '@gmail.com','=','{Ypsg<W"6q_);t')





