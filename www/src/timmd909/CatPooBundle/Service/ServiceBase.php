<?php

namespace timmd909\CatPooBundle\Service;

class ServiceBase   
{
	protected $logger;
	
	public function setLogger($logger)
	{
		$this->logger = $logger;
	}
	
	function __construct()
	{
	}	
} // class
