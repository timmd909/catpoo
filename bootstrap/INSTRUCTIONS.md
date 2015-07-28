# Bootstrap Instructions

So you wanna burn a new image cuz you messed something up, eh? Glad you
Ansible-ized now, aren't you? 

Anyhoo, first thing is first: 

	dd if=catpoo-base.img of=/dev/sdX bs=1M
	
> *Note:* The image is based off of `2015-05-05-raspbian-wheezy.img`

Doing it this way will skip the `preansible.sh` and most `raspi-config` steps:

* Enabling the camera
* Overclocking
* Keyboard settings
* Hostname changing (to `catpoo.local`)
* Creating a `tim` user
* Localization settings
* Memory split (32M is more than enough)
* SSH settings
* Vim installation
* Sudoers change to lazy mode

What you'll have to do 

* Expand the volumes (`sudo raspi-config`)
* Configuration network settings (wireless is easiest to do after the
  Ansible has done its thing)

