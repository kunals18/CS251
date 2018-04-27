BEGIN{
     maxt=0
     mint=1000000 
}
function max(a, b){
	if(a>b) return a
	else return b
}
function min(a, b){
	if(a<b) return a
	else return b
}

{
a=$3
b=$5

arr[a " > " b]++  #arr for packets
if(arr[a " > " b]==1){
  arr2[a " > " b]=0
  arr4[a":" " > " b]=0
  arr5[a":" " > " b]=900000
  re[a " > " b ]=0
}        



if($0 !~ "length 0"){
  arr2[a " > " b]++  #arr2 of datapackets
}

arr3[a " > " b ] = arr3[a " > " b ] + $NF    #arr3 for bytes
 
split($0, c, ":")
c[1]=c[1]*3600
c[2]=c[2]*60
arr4[a":" " > " b ]=max(arr4[a":" " > " b ], c[1]+c[2]+c[3])  #arr4 for max
arr5[a":" " > " b ]=min(arr5[a":" " > " b ], c[1]+c[2]+c[3])  #arr5 for min
arrdif[a " > " b ]=max(arr4[a":" " > " b ], arr4[b " > " a":" ]) - min(arr5[a":" " > " b ], arr5[b " > " a":" ])
#arrdif[a " > " b ]=arr4[a " > " b ]-arr5[a " > " b ]
arr6[a " > " b ]= arr3[a " > " b ]/arrdif[a " > " b ]  #arr6 for xputes

if($NF ~ 0){
y=$(NF-2)
  split($(NF-2), d, ",") 
  split(d[1], e, "]") 
  split(e[1], f, "}") 
  split(f[1], h, "{") 
  split(h[2], x, ":") 
}
else if($NF != 0){
  split($9, seq1, ",")
  split(seq1[1], seq2, ":")
  x[1]=seq2[1]
  x[2]=seq2[2]
}

for(l=x[1]; l<x[2]; l++){
  if( check[a " > " b ">" l ] == "5"){
  re[a " > " b ]++
  }
  else {check[a " > " b ">" l ] = "5"}
}
#print x[2] - x[1]

}

END{
      
       for(i in arr){
               print i " #packets=" arr[i] " #datapackets=" arr2[i] " #bytes=" arr3[i] " #retrans=" re[i] " #xputes=" arr6[i] " bytes/sec"
       }
#	for(j in dif){
#               print j "   " dif[j]
#       }
#	for(k in arr3){
#               print k "   " arr3[k]
#       }
#	for(k in arr4){
#               print k " max  " arr4[k]
#       }
#	for(l in arr5){
#               print l " min  " arr5[l]
#       }
#	for(g in arrdif){
#               print g "   " arrdif[g]
#       }
#	for(g in arr6){
#               printf("%d",arr6[g]);
#       }
}
