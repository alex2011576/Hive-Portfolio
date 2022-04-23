#!/usr/bin/php
<?php

function    my_char_cmp($a, $b)
{
	if (ctype_alpha($a))
	{
		if (ctype_alpha($b))
			return $a <=> $b;
		else
			return (-1);
	}
	else if (is_numeric($a))
	{
		if (ctype_alpha($b))
			return (1);
		else if (is_numeric($b))
		{
			return $a <=> $b;
		}
		else
			return -1;
	}
	if (ctype_alnum($b))
		return (1);
	else
		return $a <=> $b;

}

function    my_str_cmp($str1, $str2)
{
    $str1 = strtolower($str1);
    $str2 = strtolower($str2);
	$len1 = strlen($str1);
	$len2 = strlen($str2);
	$len = min($len1, $len2);
	for ($i = 0; $i < $len; $i++)
	{
		$tmp = my_char_cmp($str1[$i], $str2[$i]);
		if ($tmp > 0)
			return (1);
		else if ($tmp < 0)
			return (-1);
	}
	return $len1 <=> $len2;

}
	
array_shift($argv);
$str = implode(" ", $argv);
$str =  preg_replace('/\s\s+/', ' ', trim($str));
$arr = explode(" ", $str);
usort($arr, 'my_str_cmp');
foreach ($arr as $elem)
    echo "$elem\n";

?>
