sample <- 50000
data <- rexp(sample, 0.2)
x <- data.frame(X = seq(1, sample , 1), Y = sort(data))
plot(x)

vectorpart <- matrix(data, nrow=500, ncol=100, byrow=TRUE)
#vectorpart
print("Mean and Standard Deviation of first five Vector")
for(i in 1:5){
	plot(ecdf(vectorpart[i,]), main="CDF of vectors")
	plot(density(vectorpart[i,]), main="PDF of vectors")
	result.mean <- mean(vectorpart[i,])
	print(result.mean)
	result.sd <- sd(vectorpart[i,])
	print(result.sd)
}
z <- 0
for(i in 1:500){
	z[i]=(mean(vectorpart[i,]))
}

fre <- table(round(z))
#str(fre)
plot(fre, "h", xlab="Z", ylab="Frequency", main="Frequency plot of Z")
plot(ecdf(z), main="CDF of Z")
plot(density(z), main="PDF of Z")

print("Mean and Standard Deviation of Z")
meanz <- mean(z)
sdz <- sd(z)
print(meanz)
print(sdz)

print("Mean and Standard Deviation of original distribution")
meandata <- mean(data)
sddata <- sd(data)
print(meandata)
print(sddata)

