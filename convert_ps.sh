#!/bin/bash

if type "enscript" > /dev/null 2>&1; then
    :
else
    echo "Not found command: enscript"
    exit 1
fi

if type "pstopdf" > /dev/null 2>&1; then
    :
else
    echo "Not found command: pstopdf"
    exit 1
fi

touch tmp.cpp
echo "// My library" >> tmp.cpp
echo "// contest template" >> tmp.cpp
cat contest_template.cpp >> tmp.cpp

for dir in *; do
    if [ -d ${dir} ]; then
        touch tmp_${dir}.cpp

        cd ${dir}
        for i in *.cpp; do
            echo "// ${dir}" >> ../tmp_${dir}.cpp
            echo "// ${i}" >> ../tmp_${dir}.cpp
            cat ${i} >> ../tmp_${dir}.cpp
            echo "----------------------------------------------------" >> ../tmp_${dir}.cpp
            echo "" >> ../tmp_${dir}.cpp
        done
        cd ..
    fi
done

enscript --highlight=cpp --fancy-header --line-number --color --font=Courier5 --landscape --columns=2 --indent=2 --tabsize=2 -o output.ps ./tmp*.cpp
rm ./tmp*.cpp
rm library.pdf
pstopdf -o library.pdf output.ps
rm output.ps
