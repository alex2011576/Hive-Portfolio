#!/usr/bin/php
<?php

array_shift($argv);
$str = implode(" ", $argv);
$str =  preg_replace('/\s\s+/', ' ', trim($str));
$arr = explode(" ", $str);
sort($arr);
foreach ($arr as $elem)
    echo "$elem\n";

?>