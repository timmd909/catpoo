<?php

namespace timmd909\CatPooBundle\Controller;

use Symfony\Bundle\FrameworkBundle\Controller\Controller;

class DefaultController extends Controller
{
    public function indexAction()
    {
        return $this->render('timmd909CatPooBundle:Default:index.html.twig', array());
    }
	
	public function video_frame($channel) 
	{
		$file = "/dev/video".intval($channel);
		return $file;
	}
}
