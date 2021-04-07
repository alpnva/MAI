# !/bin/bash

if [[ $# -ne 2 ]]
then
	echo "Need 2 arguments"
else
	for file in $(find -iname "*$1" -type f -size -"$2"c)
	do
		file2=$(echo $file | rev | cut -d '/' -f1 | rev)
		echo $file2;
		cat $file2 >> new."$1";
	done
	echo "Done!"
fi

