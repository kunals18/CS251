import os
import commands

f1=open('params.txt', 'r')
for line in f1:
	par=line.split(" ")
#par=f1.readlines()
f1.close()
f2=open('threads.txt', 'r')
for line in f2:
	th=line.split(" ")
#th=f2.readlines()
f2.close()

p=len(par)
t=len(th)
par[p-1]=par[p-1].strip('\n')
#print par[p-1]
#print t
#for i in range(0,t):
#	for j in range(0,p):
#		for k in range(0,100):
#			temp=commands.getoutput("+./try+" "+par[j]+" "+th[i]+")
#			
#			time.append(temp)

#param = [int(x) for x in par]
#print param
#print par
f=open("t1","w")
for j in range(0,p):
	for k in range(0,100):
		#print par[j]
		temp=commands.getoutput("./try" + " " + par[j] + " 1")
		tempo=temp.split(" ")		
		f.write(par[j]+" "+tempo[3]+"\n")
f.close()

f=open("t2","w")
for j in range(0,p):
	for k in range(0,100):
		#print par[j]
		temp=commands.getoutput("./try" + " " + par[j] + " 2")
		tempo=temp.split(" ")		
		f.write(par[j]+" "+tempo[3]+"\n")
f.close()

f=open("t3","w")
for j in range(0,p):
	for k in range(0,100):
		#print par[j]
		temp=commands.getoutput("./try" + " " + par[j] + " 4")
		tempo=temp.split(" ")		
		f.write(par[j]+" "+tempo[3]+"\n")
f.close()

f=open("t4","w")
for j in range(0,p):
	for k in range(0,100):
		#print par[j]
		temp=commands.getoutput("./try" + " " + par[j] + " 8")
		tempo=temp.split(" ")		
		f.write(par[j]+" "+tempo[3]+"\n")
f.close()

f=open("t5","w")
for j in range(0,p):
	for k in range(0,100):
		#print par[j]
		temp=commands.getoutput("./try" + " " + par[j] + " 16")
		tempo=temp.split(" ")		
		f.write(par[j]+" "+tempo[3]+"\n")
f.close()

