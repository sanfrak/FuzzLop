#! /bin/bash
count=0
while (( $count < 3))
do
	
	pwd=$(dirname "$(readlink -f "$0")")
	prjDIR=$pwd"/fuzzgoat"
	echo "current folder:$prjDIR"
	#make &> /dev/null
	cd $prjDIR
	make
	./fuzzgoat_llvm &> llvm.log
	cd ..
	ln -sf fuzzgoat/llvm.log llvm.log
	mkdir -p seed
	./gen_seed_new.py
	echo "waiting for seed_gen $count"
	sleep 5
	count=$((count+1))
done