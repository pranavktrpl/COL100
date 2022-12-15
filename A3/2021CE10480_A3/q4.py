s = input()

n = len(s)

if s[0]==s[n-1]:
   if s[1]==s[n-2]:
      print("YES")
   else:
      print("NO")
else:
   print("NO")
