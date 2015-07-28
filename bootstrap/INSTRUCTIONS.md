# Bootstrap Instructions

So you wanna burn a new image cuz you messed something up, eh? Glad you
Ansible-ized now, aren't you? 

Anyhoo, first thing is first: 

	dd if=catpoo-base.img of=/dev/sdX bs=1M
	
> *Note:* The image is based off of `2015-05-05-raspbian-wheezy.img`

Doing it this way will skip:

* Enabling the camera
* Overclocking
* Keyboard settings
* Creating a `tim` user
* Localization settings
* SSH settings
* Vim installation

What you'll have to do 

* Expand the volumes (`sudo raspi-config`)
* Configuration network settings (only ethernet will work at first)









