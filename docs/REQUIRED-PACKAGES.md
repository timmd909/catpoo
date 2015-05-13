# Required Packages 

* acl
* apache2
* erlang
* g++
* libasio-dev
* libasio-doc
* make
* php-apc
* php5-dev
* screen 

# PHP DIO

DIO is required to control Maestro via PHP. PHP is not to be used for real
stuff, but it's handy.

    sudo pecl install dio 
	echo 'extension=dio.so' | sudo tee /etc/php5/conf.d/dio.ini
	
