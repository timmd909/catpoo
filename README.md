# Cat Antagonizing Tactical Platform of Oppression (CATPOO)

This project utilizes a Rasperberry Pi for everything except sensor inputs.
For all inputs and blinken lights, an Arduino Nano is used.

## Preparing the Raspberry Pi

First things first, let's install some packages:

	sudo apt-get install xserver-xorg apache2 libapache2-mod-php5 php5-cli \
	build-essential libtool autoconf automake libtool m4 gcc \
	libcgicc5 libcgicc5-dev libcgicc-doc php-apc acl

## Compiling Motion CGI application

	cd motion
	mkdir build
	cd build
	../bootstrap
	make

## Database Setup

Since everyone should hate Oracle, and fart in their general direction, we'll
be using MariaDB.

	echo "deb http://repository.pi3g.com/debian/ wheezy main" | \
	sudo tee /etc/apt/sources.list.d/repository.pi3g.com.list
	wget -O - http://repository.pi3g.com/pubkey | sudo apt-key add -
	sudo apt-get update
	sudo apt-get install mariadb-server mariadb-client

I recommend not worrying about security on the database. The robot shouldn't be
directly on the internet directly, so who cares?

## Setup PHP website

### Composer configuration

GitHub will freak out once Composer starts without a valid auth token. Go to
https://help.github.com/articles/creating-an-access-token-for-command-line-use/
to learn how to create a token, then execute:

	composer config --global github-oauth.github.com <TOKEN>

Then we can install the vendors while grabbing a cup of coffee:

	cd www
	../composer.phar install

### Cache configuration

Now to fix up that damned cache directory. First we need to make sure that
ACL is enabled on the root partion. Edit `/etc/fstab` to look like this:

	proc            /proc           proc    defaults              0       0
	/dev/mmcblk0p1  /boot           vfat    defaults              0       2
	/dev/mmcblk0p2  /               ext4    defaults,noatime,acl  0       1

Next, run the follow `setfacl` commands:

	cd www/
	mkdir app/cache
	mkdir app/logs
	sudo setfacl -R -m u:"`whoami`":rwX -m u:`whoami`:rwX app/cache app/logs
	sudo setfacl -R -m u:"www-data":rwX -m u:`whoami`:rwX app/cache app/logs
	sudo setfacl -dR -m u:"`whoami`":rwX -m u:`whoami`:rwX app/cache app/logs
	sudo setfacl -dR -m u:"www-data":rwX -m u:`whoami`:rwX app/cache app/logs

### Apache configuration

Next we'll need to make sure that the appropriate Apache modules are enabled:

	sudo a2enmod rewrite php5

Disable the default Apache sites:

	sudo a2dissite default
	sudo a2dissite default-ssl

Setup the Catpoo site by making a copy of `catpoo-site.default` to
`catpoo-site`. Then make a symlink of that new file into
`/etc/apache2/sites-available`. Then we need to enable that site and
restart Apache:

	sudo a2ensite catpoo-site
	sudo service apache2 restart

