#!/bin/bash
echo "Running test suite..."

echo "rectA: pos(0,0), size(5,5)"
echo "rectB: pos(1,0), size(5,5)"
if ./build/app.exe 0 0 5 5 1 0 5 5 | grep -q 'SUCCESS'; then
	echo "passed"
else
	echo "failed"
fi

echo " "

echo "rectA: pos(0,0), size(5,5)"
echo "rectB: pos(7,0), size(2,5)"
if ./build/app.exe 0 0 5 5 7 0 2 5 | grep -q 'FAILED'; then
	echo "passed"
else
	echo "failed"		
fi

echo " "

echo "rectA: pos(0,0), size(5,5)"
echo "rectB: pos(-10,0), size(50,5)"
if ./build/app.exe 0 0 5 5 -10 0 50 5 | grep -q 'SUCCESS'; then
	echo "passed"
else
	echo "failed"		
fi


echo " "

echo "rectA: pos(0,0), size(5,5)"
echo "rectB: pos(5,30), size(50,9)"
if ./build/app.exe 0 0 5 5 5 30 50 5 | grep -q 'FAILED'; then
	echo "passed"
else
	echo "failed"		
fi


echo " "

echo "rectA: pos(-5,0), size(5,5)"
echo "rectB: pos(0,0), size(50,5)"
if ./build/app.exe -5 0 5 5 0 0 50 5 | grep -q 'SUCCESS'; then
	echo "passed"
else
	echo "failed"		
fi


