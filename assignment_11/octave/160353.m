train=csvread("train.csv");
feature = train(:,1);
label = train(:,2);

X_train = train(:,1);
X_train = [ones(rows(X_train), 1) X_train];
Y_train = train(:,2);
#step 2
w=rand(2,1);

#step 3
hold on;
plot(feature, label);

xlabel ("Feature");
ylabel ("Label");
title ("Graph of feature v/s label");
print -dpdf "plot1.pdf";
close

x= X_train';
wt= w';
t=wt*x;
hold on;
plot(t,x);
title("w^T*x' v/s x");
print -dpdf "plot2.pdf";
close

#step 4
w_direct=inv(x*X_train)*x*Y_train;
k=w_direct'*x;
hold on;
plot(k,feature);
title ("w_direct^T*x' v/s x");
print -dpdf "plot3.pdf";
close

#step 5
eta=0.00000001;

for i=1 : 2,
	for j=1 : length(feature),
		xj=([1,feature(j)]);
		yj=label(j);
		xjt=xj';
		w=w - eta*xjt*(wt*xjt - yj);
		#if (mod(j, 100) == 0),
			
			#hold on;
			#k1=w'*X_train';
			#plot(k1, X_train);
			#title ("w^T*x' v/s x");
			#print -dpdf "plot4.pdf";
			#close
		#end,
	end,
end,

#step 6
hold on;
k2=w'*X_train';
plot(k2,X_train);
title ("w^T*x' v/s x");
print -dpdf "plot5.pdf";
close

#step 7
test=csvread("test.csv");
testfeature = test(:,1);
testlabel = test(:,2);

X_test = test(:,1);
X_test = [ones(rows(X_test), 1) X_test];
Y_test = test(:,2);
y_pred1=X_test*w;
y_pred2=X_test*w_direct;
m=min(length(testfeature), length(feature));
rms1=0;
for i=1:m,
	rms1=rms1+(y_pred1(j)-Y_test(j))^2;
end,
rms1=sqrt(rms1/m)

rms2=0;
for i=1:m,
	rms2=rms2+(y_pred2(j)-Y_test(j))^2;
end,
rms2=sqrt(rms2/m)




