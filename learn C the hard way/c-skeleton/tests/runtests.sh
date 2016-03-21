echo "Running unit tests:"

for i in tests/*_tests
do
	if test -f $i 
	then
	#添加执行命令
	#./$i build/./libex29.so print_a_message "hello"
		if $VALGRIND ./$i build/./libex29.so print_a_message "test" 2>> tests/tests.log
		then 
			echo $i PASS
		else
			echo "ERROR in test $i:here's tests/tests.log"
			echo "------"
			tail tests/tests.log
			exit 1
		fi
	fi
done

echo ""