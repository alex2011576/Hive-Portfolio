<?php
Class Color{

    public static $verbose = False;
    public $red;
    public $green;
    public $blue;

    public function __construct(array $color) {
        if (isset($color['red']) && isset($color['green']) && isset($color['blue'])) {
            $this->red = intval($color['red']);
            $this->green = intval($color['green']);
            $this->blue = intval($color['blue']);
        } else if (isset($color['rgb'])) {
            $rgb = intval($color['rgb']);
            $this->red = intval($color['rgb']) >> 16 & 0xff;
			$this->green = intval($color['rgb']) >> 8 & 0xff;
			$this->blue = intval($color['rgb']) & 0xff;
        }
        if (Self::$verbose === True)
            echo $this . " constructed." . PHP_EOL;
        return;
    }

    public function __destruct() {
        if (Self::$verbose === True)
        echo $this . " destructed." . PHP_EOL;
        return;
    }

    public function __toString() {
		return sprintf("Color( red: %3d, green: %3d, blue: %3d )", $this->red, $this->green, $this->blue);
	}

    public static function doc() {
        return file_get_contents("Color.doc.txt");
    }

    public function add(Color $rhs) {
        return (new Color(array(
            'red' => $this->red + $rhs->red, 
            'green' => $this->green + $rhs->green, 
            'blue' => $this->blue + $rhs->blue
        )));
    }

    public function sub(Color $rhs) {
        return (new Color(array(
            'red' => $this->red - $rhs->red, 
            'green' => $this->green - $rhs->green, 
            'blue' => $this->blue - $rhs->blue
        )));
    }

    public function mult($f) {
        return (new Color(array(
            'red' => intval($this->red * $f), 
            'green' => intval($this->green * $f),
            'blue' => intval($this->blue * $f)
        )));
    }
}

?>
