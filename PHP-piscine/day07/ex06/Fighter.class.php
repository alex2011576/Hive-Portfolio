<?php
    abstract class Fighter {
        public $type;
        
        public function __construct($type) {
            $this->type = $type;
        }
    
        abstract function fight($target);
    }

?>