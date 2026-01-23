#!/bin/bash

BIN=./convert

tests=(
	"a"
	"Z"
	"0"
	"9"
	"42"
	"-42"
	"+42"
	"2147483647"
	"-2147483648"
	"2147483648"

	"4.2"
	"-4.2"
	"+4.2"
	"4.2f"
	"-4.2f"
	"+4.2f"
	".42"
	".42f"

	"nan"
	"nanf"
	"inf"
	"+inf"
	"-inf"
	"inff"
	"+inff"
	"-inff"

	"abc"
	"42abc"
	"--42"
	"++42"
	""
)

for value in "${tests[@]}"; do
	echo "=============================="
	echo "Input: [$value]"
	echo "=============================="
	$BIN "$value"
	echo
done
