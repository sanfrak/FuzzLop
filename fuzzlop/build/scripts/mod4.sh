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

# create testcases and results
echo "Create directory:"
mkdir $output

# initializing fuzzers
echo "Initializing Fuzzers:"

# run LibFuzzer to generate seeds
libFdir="$(dirname "$DIR")"
cd $libFdir
libFsh=$libFdir"/get_seed.sh"
eval $libFsh
sleep 20

# copy seeds to AFL sync input dir
echo "copy LibFuzzer Seeds to AFL"
libSdir=$libFdir"/seed/"
echo "src DIR: $libSdir"
echo "des DIR: $input"
cp -r "$libSdir"* "$input"

# run AFL using the LibFuzzer seeds
echo "Make Files:"
make -C $DIR

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