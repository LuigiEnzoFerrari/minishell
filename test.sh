#!/bin/bash

RESET="\033[0m"
BLACK="\033[30m"
RED="\033[31m"
GREEN="\033[32m"
YELLOW="\033[33m"
BLUE="\033[34m"
MAGENTA="\033[35m"
CYAN="\033[36m"
WHITE="\033[37m"

BOLDBLACK="\033[1m\033[30m"
BOLDRED="\033[1m\033[31m"
BOLDGREEN="\033[1m\033[32m"
BOLDYELLOW="\033[1m\033[33m"
BOLDBLUE="\033[1m\033[34m"
BOLDMAGENTA="\033[1m\033[35m"
BOLDCYAN="\033[1m\033[36m"
BOLDWHITE="\033[1m\033[37m"

TEST_PARSED="test"
EXIT=0
function exec_test()
{
	printf $YELLOW
	TEST=$(echo $1 | ./minishell 2>&-)
	TEST_PARSED=$(sed '1d; $d' <<< $TEST)
	sleep 0.1
}

echo
printf $WHITE"------Testing RT------\n"
exec_test 'echo test1 > file'
COMPARE_FILE="test1"
if grep -q "$COMPARE_FILE" file ; then
	printf " $BOLDGREEN%s$RESET" "✓ "
else
	EXIT=1
	printf " $BOLDRED%s$RESET" "✗ "
fi
rm file
sleep 0.1
echo


# MIXS

# Testing RF and PIPE
echo
printf $WHITE"------Testing RT and PIPE------\n"
exec_test 'echo test1 > file | echo test2'
COMPARE_RETURN="test2"
COMPARE_FILE="test1"
if grep -q "$COMPARE_FILE" file && echo $TEST_PARSED | grep -q "$COMPARE_RETURN"; then
	printf " $BOLDGREEN%s$RESET" "✓ "
else
	EXIT=1
	printf " $BOLDRED%s$RESET" "✗ "
fi
rm file
sleep 0.1
echo

echo
printf $WHITE"------Testing PIPE RT and PIPE------\n"
exec_test 'ls | grep o > file | grep o file'
COMPARE_RETURN="objects sources"
COMPARE_FILE="objects
sources"
if grep -q "$COMPARE_FILE" file && echo $TEST_PARSED | grep -q "$COMPARE_RETURN"; then
	printf " $BOLDGREEN%s$RESET" "✓ "
else
	EXIT=1
	printf " $BOLDRED%s$RESET" "✗ "
fi
rm file
sleep 0.1
echo


echo
printf $WHITE"------Testing PIPE RT------\n"
exec_test 'ls | grep ob > file'
COMPARE_FILE="objects"
if grep -q "$COMPARE_FILE" file && ! grep -q tester.sh file; then
	printf " $BOLDGREEN%s$RESET" "✓ "
else
	EXIT=1
	printf " $BOLDRED%s$RESET" "✗ "
fi
rm file
sleep 0.1
echo

echo
printf $WHITE"------Testing RFS PIPE------\n"
echo testando > file
exec_test 'grep t < file | grep e'
COMPARE_FILE="testando"
COMPARE_RETURN="testando"
if grep -q "$COMPARE_FILE" file && echo "$COMPARE_RETURN" | grep -q e; then
	printf " $BOLDGREEN%s$RESET" "✓ "
else
	EXIT=1
	printf " $BOLDRED%s$RESET" "✗ "
fi
rm file
sleep 0.1
echo

echo
printf $WHITE"------Testing PIPE RFS------\n"
echo testando > file
exec_test 'touch teste | grep t < file'
if cat teste && echo "$TEST_PARSED" | grep -q "testando"; then
	printf " $BOLDGREEN%s$RESET" "✓ "
else
	EXIT=1
	printf " $BOLDRED%s$RESET" "✗ "
fi
rm file teste
sleep 0.1
echo

echo
printf $WHITE"------Testing RFS RT------\n"
echo "oi
quero
testar
isso
aqui" > file
exec_test 'wc -l < file > file2'
if grep -q oi file && cat file2 | grep -q 5; then
	printf " $BOLDGREEN%s$RESET" "✓ "
else
	EXIT=1
	printf " $BOLDRED%s$RESET" "✗ "
fi
rm file file2
sleep 0.1
echo

echo
printf $WHITE"------Testing RFS RT------\n"
echo teste > file
exec_test 'grep t < file > file2'
if grep -q teste file2 ; then
	printf " $BOLDGREEN%s$RESET" "✓ "
else
	EXIT=1
	printf " $BOLDRED%s$RESET" "✗ "
fi
rm file
sleep 0.1
echo

echo
printf $WHITE"------Testing RT RFS------\n"
exec_test 'echo teste > file < file2'
if grep -q teste file && echo "$TEST_PARSED" | grep -q such  ; then
	printf " $BOLDGREEN%s$RESET" "✓ "
else
	EXIT=1
	printf " $BOLDRED%s$RESET" "✗ "
fi
rm file
sleep 0.1
echo

echo
printf $WHITE"------Testing RT RFS------\n"
echo oi > file2
exec_test 'echo teste > file < file2'
if grep -q teste file && grep -q oi file2  ; then
	printf " $BOLDGREEN%s$RESET" "✓ "
else
	EXIT=1
	printf " $BOLDRED%s$RESET" "✗ "
fi
rm file file2
sleep 0.1
echo

echo
printf $WHITE"------Testing RT RFD------\n"
exec_test 'echo zooi > file << file2'
if grep -q zooi file ; then
	printf " $BOLDGREEN%s$RESET" "✓ "
else
	EXIT=1
	printf " $BOLDRED%s$RESET" "✗ "
fi
rm file
sleep 0.1
echo


echo
printf $WHITE"------Testing RF RT------\n"
echo teste > file
exec_test 'grep t < file > file2'
if grep -q teste file2; then
	printf " $BOLDGREEN%s$RESET" "✓ "
else
	EXIT=1
	printf " $BOLDRED%s$RESET" "✗ "
fi
rm file file2
sleep 0.1
echo

exit $EXIT