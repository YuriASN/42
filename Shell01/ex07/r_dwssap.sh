cat /etc/passwd | sed '/\#/ d' | cut -d : -f 1 | rev | sort -r | sed -n "$FT_LINE1,$FT_LINE2 p" | tr $!'\n' ' ' | sed 's/ /, /g' | sed 's/, $/./'
