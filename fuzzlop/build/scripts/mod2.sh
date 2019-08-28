#!/bin/bash
pwd=$(dirname "$(readlink -f "$0")")
pwd=$pwd/
#printf 'curDIR: %s\n' "$DIR"

pwdtxt="pwd.txt"
file=$pwd$pwdtxt

DIR=$(sed -n '1p' < $file)
input=$DIR$(sed -n '2p' < $file)
output=$DIR$(sed -n '3p' < $file)
target=$DIR$(sed -n '4p' < $file)
numF=$(sed -n '5p' < $file)

echo "Output the directory info:" 
printf 'Project DIR:\n\t %s\n' "$DIR"
printf 'seed DIR:\n\t %s\n' "$input"
printf 'results DIR:\n\t %s\n' "$output"
printf 'target:\n\t %s\n' "$target"

echo "Make Files:"
make -C $DIR

# create testcases and results
echo "Create directory:"
mkdir $output

# start running
echo "Initializing Fuzzers:"
printf 'Checking CPU Capacity'
afl-gotcpu

printf 'total fuzzer needed: %d\n' "$numF"

if (( $numF > 0 ))
then
	fuzzer="fuzzer1"
	printf '\t%s created\n' "$fuzzer"
	cmd="aflfast-fuzz -i $input -o $output -M $fuzzer -- $target @@"
	screencmd="screen -dmS $fuzzer /bin/bash -c \"$cmd\""
	#echo "$screencmd"
	eval $screencmd
fi

numS=2;
while (( $numF >= $numS ))
do
	fuzzer="fuzzer"$numS
	printf '\t%s created\n' "$fuzzer"
	cmd="aflfast-fuzz -i $input -o $output -S $fuzzer -- $target @@"
	screencmd="screen -dmS $fuzzer /bin/bash -c \"$cmd\""
	#printf '\tslave: %s\n' "$screencmd"
	eval $screencmd
	numS=$((numS+1))
done

screendb="screen -rd"
eval $screendb