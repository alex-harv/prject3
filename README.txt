This is the provided code for the side-channel cache attack. There are 2 given folders and a results.txt file.

This project must be run on a CSE labs machine for best results. You probably won't get usable results on
other machines. This includes vole. Please ssh into a lab machine to work on this project remotely.

The part 1 folder contains a side-channel attack on yourself. This is strictly for testing purposes. Part 1 is used for probing the threshold used in part 2.

The part 2 folder contains a partial implementation of a side-channel cache attack. In the provided C file, you will be completing the attacker code. Also, in 
the part 2 folder is a shared library with the secret array. The secret array is calibrated by you putting your x500 in the data.txt file.

For both folders your should be able to run ‘make’ and run the generated executable. If the shared library is not working in part 2 you can run the following command

export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:.

That should tell the compiler that there is shared library in your local directory.
