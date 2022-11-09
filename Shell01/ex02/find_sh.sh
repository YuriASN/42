find . -name "*.sh" | rev | cut -d "/" -f 1 | sed 's/hs\.//g' | rev 
