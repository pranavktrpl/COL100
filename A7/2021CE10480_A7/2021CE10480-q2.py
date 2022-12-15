def sortings(inpt : str) -> str: # it takes string as input and return string
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
    

if __name__=="__main__": # calling main (run automtically)
    inpt = input()       # taking input from user (string type)
    out = sortings(inpt) # calling function sortings in which you have to write code
    print (out)          # printing the output of your's function