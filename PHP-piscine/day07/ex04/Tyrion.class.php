<?php

class Tyrion extends Lannister {
    public function sleepWith($name)
    {
        if ($name instanceof Jaime)
            print("Not even if I'm drunk !" . PHP_EOL);
        else if ($name instanceof Sansa)
            print("Let's do this." . PHP_EOL);
        else if ($name instanceof Cersei)
            print("Not even if I'm drunk !" . PHP_EOL);
    }
}

?>