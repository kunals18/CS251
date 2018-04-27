import os
import numpy as np
import random
import csv
import matplotlib.pyplot as plt
import math

filename = "train.csv"
feature=[]
label=[]

i=0
with open(filename, 'r') as csvfile:
	csvreader = csv.reader(csvfile)
	field=csvreader.next()
	for row in csvreader:
		#feature[i]=row[0]
		#label[i]=row[1]
		feature.append(float(row[0]))
		label.append(float(row[1]))
		i=i+1
n_train = i
#print i

#Step-1
x_train=np.matrix(feature).transpose()
y_train=np.matrix(label).transpose()
#print x_train.shape
x_train= np.insert(x_train,0,1, axis=1)
#print x_train[5,1]

#step-2
#print random.random()
w = np.matrix([[random.random()],[random.random()]])
#print w.shape
print w

#step-3
plt.plot(feature, label)
plt.show()

x = x_train.transpose()
wt=w.transpose()
t=wt*x
t=t.transpose()
plt.plot(t, feature)
plt.show()

#step-4
inverse = np.linalg.inv(x*x_train)
w_direct = inverse*x*y_train
w_direct_t = w_direct.transpose()
k=w_direct_t*x
k=k.transpose()
plt.plot(k,feature)
plt.show()

#step-5
eta=0.00000001
for i in range(1,2):
	for j in range(1,n_train):
		xj=np.matrix(x_train[j])
		yj=np.matrix(y_train[j])
		xjt=xj.transpose()
		w = w - eta*xjt*(wt*xjt - yj)
		if j%100==0:
			plt.plot(wt*xjt,xj)
			#plt.show()

#step-6
plt.plot(wt*xjt,xj)
plt.show()

#step-7
file = "test.csv"
feature2=[]
label2=[]

l=0
with open(file, 'r') as csvfile:
	csvreader = csv.reader(csvfile)
	field=csvreader.next()
	for row in csvreader:
		feature2.append(float(row[0]))
		label2.append(float(row[1]))
		l=l+1
n_test = l

x_test=np.matrix(feature2).transpose()
y_test=np.matrix(label2).transpose()
#print x_test.shape
x_test= np.insert(x_test,0,1, axis=1)
#print x_test[5,1]
y_pred1=x_test*w
y_pred2=x_test*w_direct
RMSE1=0
RMSE2=0
for i in range(1,min(n_test,n_train)):
	RMSE1= math.pow(y_pred1[j]-y_test[j],2)
RMSE1=math.sqrt(RMSE1/min(n_test,n_train))
print RMSE1
for i in range(1,min(n_test,n_train)):
	RMSE2= math.pow(y_pred2[j]-y_test[j],2)
RMSE2=math.sqrt(RMSE2/min(n_test,n_train))
print RMSE2