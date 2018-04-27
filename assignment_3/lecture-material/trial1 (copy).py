import math
Nb = raw_input("Enter Nb ")
b = input("Enter b ")
length = len(Nb)
#print Nb, b
#print Nb[0]
print ord(Nb[0])-ord('0')
#print length
#ns=Nb.split(".")
#print ns[0][0]
nb2=[]
count=length-1
print count
j=0
ans = 0
#print ord('-')
for i in range(0, length):
	if ord(Nb[i])==ord('-'):
		nb2.append('-')
	elif ord(Nb[i])>64:
		print Nb[i]
		print "loop 1"
		nb2.append(ord(Nb[i]) - ord('A') + 10)
	else:
		print Nb[i]
		print "loop 2"
		nb2.append(ord(Nb[i]) - ord('0'))

while (count>=0):
	ans=ans + nb2[count]*(math.pow(b,j))
	count=count-1
	j=j+1

#print 6*(math.pow(2,2))
print nb2[0], nb2[1]
print ans