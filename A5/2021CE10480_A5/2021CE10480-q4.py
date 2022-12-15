def numwords(str):
    new_str = str.replace(',', ' ')                    # gives string separated by spaces only and no commas,periods etc
    new_str = new_str.replace('.', ' ')                # splits each and every word (separated by a space)
    seperate_words = new_str.split()                   # and gives in form of an array/list
    length = len(seperate_words) ;                      '''Gives length of the string/scentence.'''
    return length

n = int(input())
length_str = []                                        # an array of length of all the scentences

for i in range(0,n):
    scentence = str(input())
    length = int(numwords(scentence))
    length_str.append(length)


print('%.2f' %min(length_str))