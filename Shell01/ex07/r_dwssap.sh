cat /etc/passwd | sed '/\#/ d; /^$/ d' | cut -d : -f 1 | sed '1!n;d' | rev | sort -r | sed -n "$FT_LINE1,$FT_LINE2 p" | tr $!'\n' ' ' | sed 's/ /, /g' | sed 's/, $/./'
