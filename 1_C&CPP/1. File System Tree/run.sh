if [ -f "File System Tree.exe" ]
then
	rm "File System Tree.exe"
fi;

g++ -o "File System Tree.exe" *.cpp -std=C++11 -Wall -g
if [ -f "File System Tree.exe" ]
then
	./"File System Tree.exe"
fi;
