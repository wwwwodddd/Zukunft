# Read from the file file.txt and output all valid phone numbers to stdout.
grep -e '^\(\([0-9][0-9][0-9]-[0-9][0-9][0-9]-[0-9][0-9][0-9][0-9]\)\|\(([0-9][0-9][0-9]) [0-9][0-9][0-9]-[0-9][0-9][0-9][0-9]\)\)$' file.txt