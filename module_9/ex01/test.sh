#!/bin/bash

# Test cases
test_cases=(
	"1 1 + -"
	"8 9 * 9 - 9 - 9 - 4 - 1 +" #42
	"7 7 * 7 -" #42
	"1 2 * 2 / 2 * 2 4 - +" #0
	"(1 + 1)" #Error
	"3 4 +"          # 7
	"3 4 -"          # -1
	"2 3 *"          # 6
	"6 3 /"          # 2
	"2 3 + 4 *"      # 20
	"5 1 2 + 4 * + 3 -"  # 14
	"3 4 + 5 6 + *"  # 77
	"3 4 5 +"        # Error: The user input has too many values
	"4 0 /"          # Error: Division by zero
	"4 a +"          # Error: Invalid token
	"4 +"            # Error: Insufficient values in the expression
	""
)

# Run each test case
for test in "${test_cases[@]}"; do
	echo "Testing: $test"
	./RPN "$test"
done
