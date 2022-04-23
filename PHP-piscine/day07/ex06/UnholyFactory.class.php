<?php
    class UnholyFactory{
        private $_fighters = array();
        public function absorb($fighter) {
            if ($fighter instanceof Fighter) {
                if (array_key_exists($fighter->type, $this->_fighters)) {
                    echo "(Factory already absorbed a fighter of type " . $fighter->type . ")" . PHP_EOL;
                } else {
                    echo "(Factory absorbed a fighter of type " . $fighter->type . ")" . PHP_EOL;
                    $this->_fighters[$fighter->type] = $fighter;
                }
            }
            else
                echo "(Factory can't absorb this, it's not a fighter)" . PHP_EOL;
            return ;
        }

        public function fabricate($requested_fighter) {
            if (array_key_exists($requested_fighter, $this->_fighters)) {
                echo "(Factory fabricates a fighter of type " . $requested_fighter . ")" . PHP_EOL;
                return clone $this->_fighters[$requested_fighter];
            } else {
                echo "(Factory hasn't absorbed any fighter of type " . $requested_fighter . ")" . PHP_EOL;
                return (NULL);
            }
        }
    }
?>