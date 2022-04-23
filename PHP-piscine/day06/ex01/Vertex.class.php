<?php

require_once '../ex00/Color.class.php';
Class Vertex{

    public static $verbose = False;
    private $_x;
    private $_y;
    private $_z;
    private $_w = 1.0;

    public function __construct($xyzwc) {
        $this->_x = $xyzwc['x'];
        $this->_y = $xyzwc['y'];
        $this->_z = $xyzwc['z'];
        if (isset($xyzwc['w']) && !empty($xyzwc['w']))
            $this->_w = $xyzwc['w'];
        if (isset($xyzwc['color']) && !empty($xyzwc['color']) && $xyzwc['color'] instanceof Color)
            $this->_color = $xyzwc['color'];
        else
            $this->_color = new Color(array('red' => 255, 'green' => 255, 'blue' => 255));
        if (Self::$verbose === True)
            echo $this . " constructed" . PHP_EOL;
        return;
    }

    public function __destruct() {
        if (Self::$verbose === True)
        echo $this . " destructed" . PHP_EOL;
        return;
    }

    public function __toString() {
		$coords = sprintf("Vertex( x: %.2f, y: %.2f, z:%.2f, w:%.2f", $this->_x, $this->_y, $this->_z, $this->_w);
		if (Self::$verbose === true)
			return $coords.", ".$this->_color." )";
		else
			return $coords." )";
	}

    public function doc() {
		return file_get_contents("Vertex.doc.txt");
	}

    public function getX() { return $this->_x; }
	
	public function getY() { return $this->_y; }
	
	public function getZ() { return $this->_z; }
	
	public function getW() { return $this->_w; }
	
	public function getColor() { return $this->_color; }

    public function setX($new_value) { return $this->_x = $new_value; }
	
	public function setY($new_value) { return $this->_y = $new_value; }
	
	public function setZ($new_value) { return $this->_z = $new_value; }
	
	public function setW($new_value) { return $this->_w = $new_value; }
	
	public function setColor($new_value) { return $this->_color = $new_value; }



}

?>
