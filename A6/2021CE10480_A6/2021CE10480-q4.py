# matrixA = [[1.00,2.00,3.00],[2.00,3.00,4.00],[4.00,5.00,6.00]]
# matrixB = [[1.00,0.00,2.00],[9.00,8.00,5.00],[5.00,8.00,0.00]]
# matrixC = [["Hello"]]
# matrixD = [[1.00,2.00],[5.00,7.00],[3.00,8.00]]

def PrintMatrix(A:list ):
	if A == None:
		print(A)
		return
	# It will print None if the input is None
	rows = len(A)
	cols = len(A[0])
	for i in range(rows):
		for j in range(cols):
			print(A[i][j], end = " ")
		print()

# The argument type is a list and the return type is a boolean
def CheckMatrix(A: list)->bool:
	# Check whether the list of list is a matrix
    rows = len(A)
    cols = len(A[0])
    for i in range(rows):
        if len(A[i]) == cols:
            # ==> Checks lentgth of each row
            for j in range(cols):
                if type(A[i][j]) == float:
                    # ==> checks the type of a(ij) matrix element if it's float or not
                    return True
                else:
                    return False
        else:
            return False

# IMPORTANT NOTE: Please make sure to use CheckMatrix in the further questions

# The argument type is a list and the return type is a list as well
def Transpose(A:list) -> list:
	# Find the transpose of the matrix given please make sure the dimensions of the list of list
	# the transpose of the matrix
    if CheckMatrix(A) == True:
        At = []
        rows = len(A)
        cols = len(A[0])
        for j in range(cols):
            newRow = []
            for i in range(rows):
                newRow.append(A[i][j])
            At.append(newRow)
        return At
    else:
	    return None

# There are two arguments whose type is list, it returns a list as output
def Multiplication(A:list,B:list) -> list:
	# Return the multiplication of matrices A and B if it exists
    if len(A[0]) == len(B) and CheckMatrix(A) == True and CheckMatrix(B) == True:
        C = []
        rowsC = len(A)
        colsC = len(B[0])
        sum = len(A[0]) 
        for i in range(rowsC):
            newRow = []
            for j in range(colsC):
                cij = 0
                for k in range(sum):
                    cij = cij + ( (A[i][k]) * (B[k][j]) )
                newRow.append(cij)
            C.append(newRow)
        return C
    else:
	    return None

# There are two arguments whose type is list, it returns a list as output
def Addition(A:list,B:list) -> list:
	# Return the addition of matrices A and B if it exists
    if len(A) == len(B) and len(A[0]) == len(B[0]) and CheckMatrix(A) == True and CheckMatrix(B) == True :
        rows = len(A)
        cols = len(A[0])
        C = []
        for i in range(rows):
            newRow = []
            for j in range(cols):
                cij = A[i][j] + B[i][j]
                newRow.append(cij)
            C.append(newRow)
        return C
    else:
        return None

# The argument type is a list and the return type is a boolean
def Symmetric(A: list)->bool:
	# Write code to check whether matrix is symmetric or not return True if it is
	# Return False in all the other cases 
    if CheckMatrix(A) == True :
        rows = len(A)
        cols = len(A[0])
        if rows == cols :
            for i in range(rows):
                for j in range(cols):
                    if A[i][j] == A[j][i]:
                        continue
                    else:
                        
                        return False
            return True
        else:
            return False
    else:
	    return False

# # THESE ARE SOME SAMPLE TESTCASES THAT YOU CAN USE TO EVALUATE YOUR CODE
# # WE WILL NOT BE CHECKING THE OUTPUT OF THE FOLLOWING AND WILL CHECK THE RETURNED VALUE USING OUR TESTCASES

# # Printing Matrix A
# PrintMatrix(matrixA)

# # Checking whether matrixC is a valid Matrix
# print(CheckMatrix(matrixC))

# # Printing the multiplication of matrixA and matrixB
# PrintMatrix(Multiplication(matrixA,matrixB))

# # Printing the addition of matrixA and matrixB
# PrintMatrix(Addition(matrixA,matrixB))

# # Is matrixA a symmetric matrix
# print(Symmetric(matrixA))

# # Printing the transpose of matrixA
# PrintMatrix(Transpose(matrixA))

# # THE ABOVE ARE ONLY FOR YOUR REFERENCE AND WILL NOT BE INCLUDED IN EVALUATION