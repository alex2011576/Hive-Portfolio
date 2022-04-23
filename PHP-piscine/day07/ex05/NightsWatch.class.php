<?php

class NightsWatch implements IFighter{

    private $_fighters = array();
    public function recruit($new_reqruit){
        if ($new_reqruit instanceof IFighter) {
            $this->_fighters[] = $new_reqruit;
        }
    }
    public function fight() {
        foreach ($this->_fighters as $fighter) {
            $fighter->fight();
        }
    }
}

?>
