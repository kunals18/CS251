import math
Nb = raw_input("Enter Nb: ")
b = input("Enter b: ")
length = len(Nb)
flag=0
ns=Nb.split(".")
#print ns[0] + " split wala " +ns[1]
l=len(ns[0])
for i in range(0,length):
	if Nb[i]=='.':
		flag=flag+1

if flag==1:
	l2=len(ns[1])
	for i in range(0, l2):
		if ord(ns[1][i])>64:
			if (ord(ns[1][i]) - ord('A') + 10)>b:
				print "Invalid Input"
				exit()
		else:
			if (ord(ns[1][i]) - ord('0'))>b:
				print("Invalid Input")
				exit()
nb2=[]
nb22=[]
count=l-1
for i in range(0, l):
	if ord(ns[0][i])>64:
		if (ord(ns[0][i]) - ord('A') + 10)>b:
			print "Invalid Input"
			exit()
	else:
		if (ord(ns[0][i]) - ord('0'))>b:
			print("Invalid Input")
			exit()

j=0
ans = 0
k=0
ans2=0

for i in range(0, l):
	if ord(ns[0][i])==ord('-'):
		nb2.append('-')
	elif ord(ns[0][i])>64:
		nb2.append(ord(ns[0][i]) - ord('A') + 10)
	else:
		nb2.append(ord(ns[0][i]) - ord('0'))

while (count>=0):
	if nb2[count]!='-':
		ans=ans + nb2[count]*(math.pow(b,j))
		j=j+1
	count=count-1

if flag==1:
	for i in range(0, l2):
		if ord(ns[1][i])>64:
			nb22.append(ord(ns[1][i]) - ord('A') + 10)
		else:
			nb22.append(ord(ns[1][i]) - ord('0'))
#print nb22[1]
#print ns[1][1]
	while (k<l2):
		ans2=ans2 + nb22[k]/(math.pow(b,k+1))
		k=k+1
if nb2[0]=='-':
	if flag==0:
		print '-' + str(ans)
	else:
		print '-' + str(ans) + str(ans2)
else:
	if flag==0:
		print ans
	else:
		print ans + ans2