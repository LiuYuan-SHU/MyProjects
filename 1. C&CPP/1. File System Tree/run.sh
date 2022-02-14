# delete existing program
if [ -f 'File Tree System' ]
then
	echo 'Deleting existing program...'
	rm 'File Tree System'
	echo '----- delete FINISHED -----'
	echo
fi;

# compile program
echo 'compiling new program...'
gcc -o 'File Tree System' *.c

# if compiling success, run the progra,
# else print error info
if [ -f 'File Tree System' ]
then
	echo '----- compiling FINISHED -----'
	echo 'run new program...'
	echo '------------------------------'
	./'File Tree System'
else
	echo '----- compiling FAILED -----'
fi;