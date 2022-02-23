# delete existing files
if [ -f BuyBook ]
then
	echo 'deleting existing files...'
	rm 'BuyBook'
	echo 'delete finished'
	echo
fi;

#compile new files
echo 'compiling new file...'
g++ -o BuyBook *.cpp
echo

#if success
if [ -f BuyBook ]
then
	echo '------ compiling finished ------'
	echo 'compiling succeeded, run file...'
	echo '--------------------------------'
	clear
	./BuyBook
else
	echo '------ compiling FAILED --------'
fi;
