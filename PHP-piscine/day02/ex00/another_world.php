#!/usr/bin/php
<?php

if ($argc > 1)
{
    $param = preg_replace('/\s+/', ' ', trim($argv[1]));
    if ($param)
        echo "$param\n";

}

?>