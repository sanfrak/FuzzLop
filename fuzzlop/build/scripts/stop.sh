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

# Ternimate fuzzers
echo "Ternimating Fuzzers:"

numS=1;

while (( $numF >= $numS ))
do
	fuzzer="fuzzer"$numS
	screencmd="screen -S $fuzzer -X quit"
	printf '\t%s terminated\n' "$fuzzer"
	eval $screencmd
	numS=$((numS+1))
done

printf 'total fuzzers terminated: %d\n' "$numF"

screendb="screen -rd"
eval $screendb