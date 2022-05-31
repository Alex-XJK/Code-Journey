# Read from the file file.txt and output all valid phone numbers to stdout.

# grep -P: Interpret  the pattern as a Perl-compatible regular expression (PCRE).
# ^((([0-9]{3}-)|(\([0-9]{3}\) ))[0-9]{3}-[0-9]{4})$

grep -P '^(\d{3}-\d{3}-\d{4}|\(\d{3}\) \d{3}-\d{4})$' file.txt