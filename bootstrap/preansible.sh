#!/bin/bash 
#
# Install all necessary packages before Ansible tasks over
#
# To run this, execute:
#
#   curl https://github.com/timmd909/catpoo/tree/master/bootstrap/preansible.sh
# 

PACKAGES=$(cat << EOT
openssh-server
vim
git
EOT
)

for PACKAGE in $PACKAGES ; do 
	echo $PACKAGE
done
