<?php

namespace timmd909\CatPooBundle\Controller;

use Symfony\Bundle\FrameworkBundle\Controller\Controller;

class MotionController extends ControllerBase
{
	public function commandAction($command, $direction)
	{
		$this->get('logger')->info("commandAction($command, $direction)");
		
		switch ($command) {
			case 'move': {
				$this->motionService->move($direction);
			} break;
			case 'turn': {
				$this->motionService->turn($direction);
			} break;
			case 'stop': {
				$this->motionService->stop();
			} break;
		}
		
		$options = array(
			'command' => $command,
			'direction' => $direction
		);
		return $this->render('timmd909CatPooBundle:Motion:response.xml.twig', $options);	
	}
}
