#/usr/bin/bash

while true; do
  python gen.py > in.txt
  time ./my < in.txt > out.txt
  time ./std < in.txt > ans.txt
  if diff out.txt ans.txt; then
    echo AC
  else
    echo WA
    exit 0
  fi
done
