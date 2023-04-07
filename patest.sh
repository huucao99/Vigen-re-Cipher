case $1 in
vigenere.c)
	gcc vigenere.c 
	EXE="./a.out"
	;;
vigenere.cpp)
	g++ vigenere.cpp
	EXE="./a.out"
	;;
vigenere.java)
	javac vigenere.java
	EXE="java vigenere"
	;;
*)
	echo "Invalid source file name"
	exit 1
esac

echo "Case #0"
eval $EXE k0.txt p0.txt >case0stu.txt
read -n 1 -p "Enter to continue:" mainmenuinput
diff case0stu.txt case0base.txt
echo "Case #0 - complete"

echo "Case #1"
eval $EXE k1.txt p1.txt >case1stu.txt
read -n 1 -p "Enter to continue:" mainmenuinput
diff case1stu.txt case1base.txt
echo "Case #1 - complete"

echo "Case #2"
eval $EXE k2.txt p2.txt >case2stu.txt
read -n 1 -p "Enter to continue:" mainmenuinput
diff case2stu.txt case2base.txt
echo "Case #2 - complete"

echo "Case #3"
eval $EXE k3.txt p3.txt >case3stu.txt
read -n 1 -p "Enter to continue:" mainmenuinput
diff case3stu.txt case3base.txt
echo "Case #3 - complete"

echo "Case #4"
eval $EXE k4.txt p4.txt >case4stu.txt
read -n 1 -p "Enter to continue:" mainmenuinput
diff case4stu.txt case4base.txt
echo "Case #4 - complete"
