queu = []

def Issue():
    if len(queu)>0:
        del queu[0]
    else:
        print("Invalid")
    return

def Join(AadharID: int):
    queu.append(AadharID)
    return


def Check():
    if len(queu)>0:
        Aadhar1 = queu[0]
        print(Aadhar1)
    else:
        print("Invalid")
    return

def GetLine():
    if len(queu)>0:
        for i in range(0,len(queu)):
            print(queu[i], end = ' ')
        print()
    else:
        print("Invalid")
    return

n = int(input())

for i in range(n):
    command = str(input())
    parsed = command.split()
    
    if parsed[0] == "Issue":
        Issue()
    elif parsed[0] == "Join":
        AadharID = parsed[1]
        Join(AadharID)
    elif parsed[0] == "Check":
        Check()
    elif parsed[0] == "GetLine":
        GetLine()

# # A sample testcase is the following it is the Example 1 as in the pdf, you can uncomment to run it
# def testcase():
#     # The example in the pdf has the following operations
#     Join(5) # Join 5
#     # Note that you have to parse the input and then send values in the function like done here
#     Check() # Check
#     Join(4) # Join 4
#     Check() # Check
#     GetLine() # GetLine
#     Join(3) # Join 3
#     GetLine() # GetLine
#     Issue() # Issue
#     Check() # Check
#     GetLine() # GetLine
#     # Here we have not called print statements and that is upto you to do
#     # You could return values and then print or print in the function itself
#     # You can do whatever you like as long as the functions are used in the code

# testcase()
# # You can uncomment the above line to check whether your functions work
# # Please comment it out before you submit otherwise the output will not match the autograder