waitline_ID = []
waitline_bill = []

def Highest():
    if len(waitline_bill)>0:
        index = waitline_bill.index(max(waitline_bill))
        print(waitline_ID[index])
    else:
        print("Invalid")
    return

def Order(orderID: int, BillValue:int):
    waitline_ID.append(orderID)
    waitline_bill.append(BillValue)
    return

def Serve():
    if len(waitline_ID)>0:
        index = waitline_bill.index(max(waitline_bill))
        del waitline_ID[index]
        del waitline_bill[index]
    else:
        print("Invalid")
    return

n = int(input())

for i in range(n):
    command = str(input())
    parsed = command.split()

    if parsed[0] == "Highest":
        Highest()
    elif parsed[0] == "Order":
        orderID = int(parsed[1])
        Bill = int(parsed[2])
        Order(orderID,Bill)
    elif parsed[0] == "Serve":
        Serve()
     

# # A sample testcase is the following it is the Example 1 as in the pdf, you can uncomment to run it
# def testcase():
#     # The example in the pdf has the following operations
#     Order(5,20) # Order 5 20
#     # Note that you have to parse the input and then send values in the function like done here
#     Highest() # Highest
#     Order(4,100) # Order 4 100
#     Highest() # Highest
#     Order(3,100) # Order 3 100
#     Highest() # Highest
#     Serve() # Serve
#     Highest() # Highest
#     # Here we have not called print statements and that is upto you to do
#     # You could return values and then print or print in the function itself
#     # You can do whatever you like as long as the functions are used in the code

# testcase()
# # You can uncomment the above line to check whether your functions work
# # Please comment it out before you submit otherwise the output will not match the autograder