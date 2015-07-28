#!/bin/bash
#
# Install all necessary packages before Ansible tasks over
#
# To run this, execute:
#
#   curl --silent https://raw.githubusercontent.com/timmd909/catpoo/master/bootstrap/preansible.sh | bash -
#

PACKAGES=$(cat << EOT
openssh-server
vim
git
EOT
)

echo '===================='
echo 'Bootstrapping CATPOO'
echo '===================='
echo

for PACKAGE in $PACKAGES ; do
	sudo apt-get install -y $PACKAGE
done

# Don't make fun of my server name... but feel free to add to this public
# key to all your servers in all your root accounts... (if you have access
# to my private dev network)
#
# ALL YOUR ROOT ARE BELONG TO US
#
mkdir ~/.ssh
chmod 700 ~/.ssh
ssh-keygen
curl --silent ibig/~tim/id_rsa.pub | cat >> ~/.ssh/authorized_keys

echo '===================='
echo 'Done prepping CATPOO'
echo '===================='
echo
