# Cat Antagonizing Tactical Platform of Oppression (CATPOO)

This project utilizes a Rasperberry Pi for everything except sensor inputs.
For all inputs and blinken lights, an Arduino Nano is used.

## Preparing the Raspberry Pi

First things first, let's install some packages:

	sudo apt-get install xserver-xorg apache2 libapache2-mod-php5 php5-cli \
	build-essential libtool autoconf automake libtool m4 gcc \
	libcgicc5 libcgicc5-dev libcgicc-doc

## Compiling Motion CGI application

	cd motion
	./bootstrap
	make

## Setup PHP website

GitHub will freak out once Composer starts without a valid auth token. Go to
https://help.github.com/articles/creating-an-access-token-for-command-line-use/
to learn how to create a token, then execute:

	composer config --global github-oauth.github.com <TOKEN>

Then we can install the vendors while grabbing a cup of coffee:

	cd www
	../composer.phar install

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

