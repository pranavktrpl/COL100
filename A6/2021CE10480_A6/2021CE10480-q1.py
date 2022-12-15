plates = []

def PickPlate():
    if len(plates)>0:
        plates.pop()
    else:
        print("Invalid")
    return

def AddPlate(PlateID: int):
    plates.append(PlateID)
    return


def Check():
    if len(plates)>0:
        lastPlate = plates[-1]
        print(lastPlate)
    else:
        print("Invalid")
    return

n = int(input())

for i in range(0,n):
    command = str(input())
    parsed = command.split()

    if parsed[0] == "PickPlate":
        PickPlate()
    elif parsed[0] == "AddPlate":
        argument = parsed[1]
        AddPlate(argument)
    elif parsed[0] == "Check":
        Check()


# def testcase():
#     # The example in the pdf has the following operations
#     AddPlate(5) # AddPlate 5
#     # Note that you have to parse the input and then send values in the function like done here
#     Check() # Check
#     AddPlate(4) # AddPlate 4
#     Check() # Check
#     AddPlate(3) # AddPlate 3
#     PickPlate() # PickPlate
#     Check() # Check
#     # Here we have not called print statements and that is upto you to do
#     # You could return values and then print or print in the function itself
#     # You can do whatever you like as long as the functions are used in the code

# testcase()