#level4
sudo mkdir -p /srv/webgame2
echo "Destroy everything so no one can discover you. There's a server behind you that shouldn't be discovered..." | sudo tee /srv/webgame2/flag.txt
sudo tar -czf /srv/webgame2/flag_pack.tar.gz -C /srv/webgame2 flag.txt
python3 -m http.server 8081 --directory /srv/webgame2 &

#level5
echo "You should remember the first clue (1), you should remember the Chinese question (2), now the question awaits its answer in a solitary file (3). 
You should have destroyed everything (4). Remember that every end is the beginning of the future!" | nc -l -p 9090 &
