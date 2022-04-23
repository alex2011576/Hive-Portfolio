<?php

Class Vector{

    public static $verbose = False;
    private $_x;
    private $_y;
    private $_z;
    private $_w = 0;

    public function __construct( $array ) {
        if (!isset($array['dest']) || !($array['dest'] instanceof Vertex)) {
            echo "error: invalid contruction parameter." . PHP_EOL;
            die();
        }
        if ((isset($array['orig']) && !($array['dest'] instanceof Vertex))) {
            echo "error: invalid contruction parameter." . PHP_EOL;
            die();
        } 
        if (!isset($array['orig'])){
            $orig = new Vertex (
                array ('x' => 0, 'y' => 0, 'z' => 0)
            );  
        } else {
            $orig = new Vertex(array(
                    'x' => $array['orig']->getX(),
                    'y' => $array['orig']->getY(),
                    'z' => $array['orig']->getZ()));
        }
        $this->_x = $array['dest']->getX() - $orig->getX();
        $this->_y = $array['dest']->getY() - $orig->getY();
        $this->_z = $array['dest']->getZ() - $orig->getZ();
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
        return sprintf("Vector( x:%.2f, y:%.2f, z:%.2f, w:%.2f )",
                $this->_x, $this->_y, $this->_z, $this->_w);
    }
    
    public static function doc() {
        return file_get_contents("Vector.doc.txt");
    }


    public function getX() { return $this->_x; }
	
	public function getY() { return $this->_y; }
	
	public function getZ() { return $this->_z; }
	
	public function getW() { return $this->_w; }
	

    private function createVertex()
    {
        return new Vertex ( array(
                'x' => $this->_x,
                'y' => $this->_y, 
                'z' => $this->_z ));
    }
    private function divideVertex( $Vertex_array, $mag ) {

        $Vertex_array->setX($Vertex_array->getX() / $mag);
        $Vertex_array->setY($Vertex_array->getY() / $mag);
        $Vertex_array->setZ($Vertex_array->getZ() / $mag);
        return $Vertex_array;
    }

    private function addVector( Vertex $n1, Vector $n2 ) {
        $n1->setX($n1->getX() + $n2->getX());
        $n1->setY($n1->getY() + $n2->getY());
        $n1->setZ($n1->getZ() + $n2->getZ());
        return $n1;
    }

    private function subVector( Vertex $n1, Vector $n2 ) {
         $n1->setX($n1->getX() - $n2->getX());
         $n1->setY($n1->getY() - $n2->getY());
         $n1->setZ($n1->getZ() - $n2->getZ());
        return $n1;
    }

    private function oppositeVector( Vertex $n1 ) {
        $n1->setX($n1->getX() * -1);
        $n1->setY($n1->getY() * -1);
        $n1->setZ($n1->getZ() * -1);
        return $n1;
    }

    private function productVertex( $Vertex_array, $k ) {

        $Vertex_array->setX($Vertex_array->getX() * $k);
        $Vertex_array->setY($Vertex_array->getY() * $k);
        $Vertex_array->setZ($Vertex_array->getZ() * $k);
        return $Vertex_array;
    }

    public function magnitude() {
        return sqrt( pow($this->_x, 2) + pow($this->_y, 2) + pow($this->_z, 2));
    }

    public function normalize() {
        $mag = $this->magnitude();
        if ( $mag == 1 )
            return clone $this;
        $Vertex_array = $this->createVertex();          
        return new Vector ( array( 'dest' =>  $this->divideVertex($Vertex_array, $mag)));
    }

    public function add( Vector $rhs ) {
        $Vertex_array = $this->createVertex();
        return new Vector ( array( 'dest' => $this->addVector($Vertex_array, $rhs)));
    }

    public function sub( Vector $rhs ) {
        $Vertex_array = $this->createVertex();
        return new Vector ( array( 'dest' => $this->subVector($Vertex_array, $rhs)));
    }

    public function opposite() {
        $Vertex_array = $this->createVertex();
        return new Vector ( array( 'dest' => $this->oppositeVector($Vertex_array)));
    }

    public function scalarProduct( $k ) {
        $Vertex_array = $this->createVertex();
        return new Vector ( array( 'dest' => $this->productVertex($Vertex_array, $k)));
    }

    public function dotProduct( Vector $rhs ) {
        return $this->_x * $rhs->getX() + $this->_y * $rhs->getY() + $this->_z * $rhs->getZ();
    }

    public function cos( Vector $rhs ) {
        return $this->dotProduct($rhs) / ($this->magnitude() * $rhs->magnitude());
    }

    public function crossProduct ( Vector $rhs ) {
        return new Vector (
            array( 'dest' => new Vertex (
                array(
                    'x' => $this->_y * $rhs->getZ() - $rhs->getY() * $this->_z,
                    'y' => $this->_z * $rhs->getX() - $rhs->getZ() * $this->_x,
                    'z' => $this->_x * $rhs->getY() - $rhs->getX() * $this->_y
                )
            ))
        );
    }

}

?>
