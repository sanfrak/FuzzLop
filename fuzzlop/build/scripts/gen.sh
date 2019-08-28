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

parentDir="$(dirname "$DIR")"
crashDir=$DIR"crashes/"
mkdir $crashDir
# Generate results
echo "Generating Results:"

# Generate statistics
restxt="res.txt"
resfile=$pwd$restxt
cmd="afl-whatsup $output"
$eval $cmd
$cmd > $resfile 2>&1
echo "Stats stored at res.txt"

# Generate plots
numS=1;
plt="plot"
while (( $numF >= $numS ))
do
	fuzzer="fuzzer"$numS
	fuzzdir=$output"/"$fuzzer
	plotdir=$fuzzdir"/"$plt
	#printf '\t%s is fzers dir\n' "$fuzzdir"
	#printf '\t%s is plots dir\n' "$plotdir"
	cmd="afl-plot $fuzzdir $plotdir"
	eval $cmd

	echo "copy crashes to parentDir"
	fuzzCrashDir=$fuzzdir"/crashes/"
	echo "src DIR: $fuzzCrashDir"
	echo "des DIR: $crashDir"
	cp -r "$fuzzCrashDir"* "$crashDir"

	numS=$((numS+1))
done

echo "plot is generated for all fuzzers"
