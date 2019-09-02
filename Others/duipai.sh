#/usr/bin/bash

while true; do
  python gen_data.py
  ./E < input.txt > output.txt
 ./E_r <input.txt > r.txt
  if diff output.txt r.txt; then
    printf AC
  else
    echo WA
    exit 0
  fi
done
