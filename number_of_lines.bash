#!/usr/bin/env bash

count=0
# lines=$(< /dev/stdin )

# IFS='\n' read -ra line <<< "${lines}"
# for _ in "${line[@]}"; do
	while read line; do
(( count++ ))
	done < "$1"

	echo "we found $count lines."
