#!/usr/bin/php
<?php

if ($argc == 2)
{
    $param = preg_replace('/\s\s+/', ' ', trim($argv[1]));
    echo "$param\n";

}

?>