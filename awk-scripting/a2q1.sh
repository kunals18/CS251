a=0
b=0
function work(){
	while read i
	do
		echo "Just echoing for the sake $i"
		if [[ -d $i ]];then
			work $new_content $tab $new_command
		else
			if [[ $i == *.c ]];then
			a_a = `awk -f trial1.awk "$i" | cut -f1 -d' '`
			b_a = `awk -f trial1.awk "$i" | cut -f2 -d' '`
			a = $(($a + $a_a))
			b = $(($b + $b_a))
			echo $a " " $b
			fi
		fi
	done < <(ls $1)
}
work $1
