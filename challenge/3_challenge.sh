#level5
lsof -i tcp:9090 | awk 'NR!=1 {print $2}' | xargs --no-run-if-empty kill
echo -e "If you remember the first clue (1), download it!\nAlso,\n\tYou should remember the Chinese question (2).\n\tThe question awaits its answer in a solitary file (3).\n\tYou should have destroyed everything (4).\n\nRemember that every end is the beginning of the future!" | nc -l -p 9090 &
