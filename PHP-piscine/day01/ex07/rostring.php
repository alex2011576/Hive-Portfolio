#!/usr/bin/php
<?php

if ($argc > 1)
{
    $str = preg_replace('/\s\s+/', ' ', trim($argv[1]));
    $arr = explode(" ", $str);
    if (count($arr) > 1)
    {
        $arr[] = $arr[0];
        array_shift($arr);
        $first = true;
        foreach ($arr as $elem)
        {
            if ($first)
                $first = false;
            else
                echo " ";
            echo "$elem";

        }
        echo "\n";
    }
    else
        echo "$str\n";
}
?>