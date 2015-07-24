<?php

namespace timmd909\CatPooBundle\Controller;

use Symfony\Bundle\FrameworkBundle\Controller\Controller;

class ControllerBase extends Controller
{
	function __get($variable)
	{
		if (strrpos($variable, 'Service') !== FALSE) {
			$service = 'timmd909.catpoo.' . ucfirst(
				substr($variable, 0, 
					strrpos($variable, 'Service')
				)
			);
			return $this->get($service);
		}
	}
	
}
