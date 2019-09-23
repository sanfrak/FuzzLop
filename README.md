// README.MD
// This is the project idea & instruction for running the FuzzLop.

// PROJECT IDEA and DESCRIPTION
	To make hybrid fuzzing easier and more user-friendly, we designed a GUI application - FuzzLop Hybrid Fuzzer.
	
	This application is able to perform mono/hybrid fuzzingand provide the user with straightforward information about fuzzing tasks in an easy-to-use fashion, which enables an ordinary user who is puzzled by the complicated commandline instructions but wants to perform hybrid fuzzing.
	
	FuzzLop is able to incorporate three mainstream fuzzers(AFL, LibFuzzer, AFL-Fast) and perform fuzzing jobs using user's configurations.
	
	FuzzLop also offers more accessible ways to check run-time stats and crashstats in just a few clicks of buttons, which is far more user-friendly than typing commandlines and do information gathering jobs by users themselves.
	
	The architecture of this software is shown in figure below.
	
	In summary, this software offers hybrid fuzzing with three mainstream fuzzers in an easy-to-use fashion. It also provides run-time and crash statistics checking function, which makes it more practical than traditional fuzzers with command line instructions. 


// INSTALLATION AND EXECUTION

1. Prerequisites:
	to run the FuzzerLop software, the following packages are needed:

	1. AFL (2.52b)
		http://lcamtuf.coredump.cx/afl/
	2. AFLFast
		https://github.com/mboehme/aflfast
	3. LibFuzzer
		this is a part of clang 6.x.
	4. Qt Creator
		https://www.qt.io/download

	The program can run only after all four prerequisites are installed and properlly configured.
	This program is developed and run on Linux 16.04 x64.

	*caution:
		1) AFL need to be configured properly as it may have core_pattern error message first time
		2) LibFuzzer only comes with clang 6.x, which is only available on 64-bit OS.
		3) Qt 5.x may or may not have issue with Ubuntu 18.04. It may require mesa-dev packages.

2. Run the GUI
	This software has two major functions: 1) hybrid fuzzing and 2) statistics checking.
	
	2.1 Hybrid Fuzzing
		FuzzLop is able to incorporate three mainstream fuzzers(AFL, LibFuzzer, AFL-Fast) and perform fuzzing jobs using user's configurations.
	
	2.2 Statistics Checking
		FuzzLop offers more accessible ways to check run-time stats and crashstats in just a few clicks of buttons, which is far more user-friendly than typing commandlines and do information gathering jobs by users themselves.
	
	// EXECUTE PROCESS:
	
	To run the software, firstly, the user has to set configurations for the fuzzing jobs, which includes setting directories, specifying the executable for fuzzing jobs, specifyingthe number of fuzzers run in parallel, and selecting the fuzzer engines (figure 2).
	
	These configurations are saved in a text file, and the software will decide which bash script torun according to the given configurations. The bash script then will initialize the fuzzerengines, which includes making input and output directories, compiling the project withfuzzer engines, and fuzz the executable. If the user chooses running the hybrid mode (which runs more than one type of fuzzer at the same time), the FuzzerLop will also do seed synchronization.
	
	Lastly, after the software started the fuzzer engines, run-time statistics will be generatedand updated periodically. The FuzzLop offers run-time statistics and crashes statisticschecking functions.
	
	To check the run-time statistics (figure 3.1), the fuzzer will gather thestatistics generated by each fuzzer engine and display them in the text area. To make iteasier for the user to check the fuzzing procedure, we also offer Plotting function, whichgenerates the historical statistics for current fuzzer’s path coverage, hangs and crashesinformation, as well as the execution speed, as shown in figure 3.3.To check the crash statistics (figure 3.2), every time the user clicks the "get crash list"button, we will run a bash script to gather all unique crashes found by each fuzzers into afolder, and display them in software’s text area, the user can use our "check crash" buttonto open each file and inspect the input which caused the crash.
	

// SOURCE FILE STRUCTURE

In this project, there are two folders, ./fuzzlop and ./target

1. ./fuzzlop:
	1) ./fuzzlop/4-1QDialogDemo
		This directory contains the source code for the design of FuzzLop GUI, this project can be opened by Qt Creator 5.x.

	2) ./fuzzlop/build:
		This directory is the default building path for FuzzLop project. The files are generated by Qt Creator using Qmake.

		a. ./fuzzlop/build/scripts:
		This directory contains the scripts calling the fuzzer engines and the generated text files which stores the user configurations.

			i. pwd.txt
				This file stores the user configuration defined in "set configuration" part of the GUI.
			ii. mod*.sh
				mod1.sh - mod4.sh are four bash scripts which make the target application and run the fuzzers. It is called when user click "run" button in GUI.
			iii. stop.sh
				This bash script terminatees all the fuzzers running. It is called when user click "stop" button in GUI.

2. ./target:
	1) ./target/fuzzgoat:
		This directory contains the example target for fuzzing. fuzzgoat is described in the final report of this project.

		a. ./target/fuzzgoat/in
			This is the example input folder for fuzzing. This folder contains seeds, and can not be empty!

		b. ./target/fuzzgoat/out
			This is the example output folder for fuzzing. This folder contains all fuzzers and their information. This folder is created on the run.

		c. ./target/fuzzgoat/crashes
			This is the example folder which stores the crash information. This folder contains all unique crrashes found by each fuzzer. This folder is created when user click "get crash list" in GUI.

	2) ./target/seed:
		This directory is generated on-the-run. When LibFuzzer is called, it will generate seed for hybrid fuzzing, all the interesting seeds will be extracted and stored here.

	3) ./target/get_seed.sh & gen_seed_new.py
		These two scripts are used to pass configurations to LibFuzzer, generate seeds and extract them.