BEGIN{
start=0
start2=0
start3=0
count_1=0
count_2=0
count_3=0
flag=0
flag2=0
flag3=0
final_comment=0
}
{
#if($0 ~ /\/\// && start==0 && start2==0){
#  start=1
#  count_1 = count_1 + 1;
#  print "count_1 " count_1
#  }
split($0, b, /\/\//)
for(j in b){
  if(start==0 && start2==0){
  start=1
  count_1 = count_1 + 1
  print "count_1 "count_1
  }
}
count_1--
start=0

if($0 ~ /\/\*/ && start==0 && start2==0){
  flag=1
  start2=0
  start3=1
}
if( flag ~ 1 && start2==0){
  count_2 = count_2 + 1;
  print "count_2 " count_2
}
if($0 ~ /\*\//){
  flag=0
  start2=0
  start3=0
}
start=0
#if($0 ~ /\".*\"/){
#  count_3 = count_3 + 1;
#  print "count_3 " count_3
#}
#if($0 ~ /\"/ && start3==0){
#  if($0 ~ /\/\//){ }
#  else if($0 ~ /\"/){
#    count_3 = count_3 + 1
#    print "count_3 " count_3
#  }
#}

split($0, a, /\"/)
if(start3==0){
  for(i in a){
    if($0 ~ /\/\//){ }
    else{count_3 = count_3 + 1
    print count_3}
  }
if($0 ~ /\/\//){ }
else{count_3--}
}



}
END{
  final_comment= count_1 + count_2
  print "comment " final_comment
  print "string " count_3/2
}
