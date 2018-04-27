import os

f1=open('t1', 'r')
numpar=0
for line in f1:
	numpar+=1
numpar=numpar/100
#print numpar
f1.close()

f1=open('t1', 'r')
f2=open('t2', 'r')
f3=open('t3', 'r')
f4=open('t4', 'r')
f5=open('t5', 'r')
f=open('partC', 'w')
for i in range(0, numpar):
	a1=0
	a2=0
	a3=0
	a4=0
	a5=0
	va1=0
	va2=0
	va3=0
	va4=0
	va5=0
	#k1=f1.readline()
	#kk1=k1.split(" ")
	#ka=kk1[0]
	for j in range(0, 100):
		p1=f1.readline()
		pp1=p1.split(" ")
		ka=pp1[0]		
		a1+=int(pp1[1])
		va1+=(a1*a1)		
		p2=f2.readline()
		pp2=p2.split(" ")
		a2+=int(pp2[1])
		va2+=(a2*a2)
		p3=f3.readline()
		pp3=p3.split(" ")
		a3+=int(pp3[1])
		va3+=(a3*a3)
		p4=f4.readline()
		pp4=p4.split(" ")
		a4+=int(pp4[1])
		va4+=(a4*a4)
		p5=f5.readline()
		pp5=p5.split(" ")
		a5+=int(pp5[1])
		va5+=(a5*a5)
	a1=a1/100
	a2=a2/100
	a3=a3/100
	a4=a4/100
	a5=a5/100
	va1=va1/100
	va1=va1-(a1*a1)
	va2=va2/100
	va2=va2-(a2*a2)
	va3=va3/100
	va3=va3-(a3*a3)
	va4=va4/100
	va4=va4-(a4*a4)
	va5=va5/100
	va5=va5-(a5*a5)
	f.write(ka+" "+str(a1)+" "+str(va1)+" "+str(a2)+" "+str(va2)+" "+str(a3)+" "+str(va3)+" "+str(a4)+" "+str(va4)+" "+str(a5)+" "+str(va5)+" \n")
