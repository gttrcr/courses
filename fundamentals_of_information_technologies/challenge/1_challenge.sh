#level 2
echo "75.45.11.50 misterioso.lan" | sudo tee -a /etc/hosts
sudo mkdir /flag

num_files=1524
directory="/flag"

generate_random_number() {
  echo $((RANDOM % 90 + 10))
}

for ((i = 0; i < num_files; i++)); do
	xx=$(generate_random_number)
	yy=$(generate_random_number)
	zz=$(generate_random_number)
	aa=$(generate_random_number)
	filename="${xx}.${yy}.${zz}.${aa}"
	sudo touch "$directory/$filename"
done

echo "Who first attested the name \"china\"?" | sudo tee /flag/75.45.11.50

#level3
sudo mkdir /srv/webgame
echo "You're almost there. The answer, once found, must be written and hidden in the root." | sudo tee /srv/webgame/flag
echo "Write the answer like this: " | sudo tee -a /srv/webgame/flag
echo -e "\t1. The answer on the first line.\n\t2. One person per line (you and your teammates)." | sudo tee -a /srv/webgame/flag
python3 -m http.server 8080 --directory /srv/webgame &

