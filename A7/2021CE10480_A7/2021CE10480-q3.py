from typing import List
def sortings(lst : List[str]) -> List[str]: # it takes list of strings as input and return list of strings
    # write your code in this function only
    # your's code start here 

    #to sort the given string copied from q2 
    def sortstring(inpt : str) -> str: # it takes string as input and return string
        # write your code in this function only
        # your's code start here 

        lstofwords = list(inpt)
        front = []

        # print(lstofwords)

        for i in range(0,10):
            counter = 0
            for j in range(0,len(lstofwords)):
                if lstofwords[j] == str(i):
                    counter = counter+1
            if counter % 2 == 1:
                for k in range(0,counter):
                    lstofwords.remove(str(i))
                    front.append(str(i))
                        
        # print (front)
        # print(lstofwords)

        final_lst = front + lstofwords
        otpt = ""
        for b in range(0,len(final_lst)):
            otpt = otpt + str(final_lst[b])
        
        return otpt

        # return your's string result
        # your's code end here 

    # to sort individual strings in the input list according to q2 rules
    for i in range(len(lst)):
        lst[i] = sortstring(lst[i])

    # to check if the given no is an base10 integer, similar to is numeric in python but from scratch
    def isint(a:str)->bool:
        for j in range(0,10):
            if a == str(j):
                return True
        return False

    # code to give the no in starting of sorted string
    def extractnos(inpt: str)->str:
        numeric = ""
        i = 0
        while( i<len(inpt) and isint(inpt[i]) == True):
            numeric = (numeric) + inpt[i]
            i = i + 1
        return numeric

    # return your's result (list of string) 
    # your's code end here 
    for i in range(len(lst)):
        for j in range(i,len(lst)):
            if (extractnos(lst[i]) != "" and extractnos(lst[j]) != ""):
                if int(extractnos(lst[i]))>int(extractnos(lst[j])):
                    lst[i],lst[j] = lst[j],lst[i]
            elif (extractnos(lst[i]) == "" and extractnos(lst[j]) != ""):
                lst[i],lst[i+1] = lst[i+1],lst[i]
            elif (extractnos(lst[i]) != "" and extractnos(lst[j]) == ""):
                continue
    return lst

if __name__=="__main__": # calling main (run automtically)
    lst = []             # list that stores the input strings
    num = int(input())   # taking input from user of number of strings of list
    for i in range(num): # take input of all strings of list
        inpt = input()
        lst.append(inpt) # append each string into the list
    lst = sortings(lst)  # calling function in which you have to write the code
    print (lst)          # printing the output (list of strings) of your's function