#!/usr/bin/php
<?php
    
    if ($argc != 2)
        exit ();
    $day_of_week = array(
        1 => "lundi",
        2 => "mardi",
        3 => "mercredi",
        4 => "jeudi",
        5 => "vendredi",
        6 => "samedi",
        7 => "dimanche");
    $month = array(
        1 => "janvier",
        2 => "février",
        3 => "mars",
        4 => "avril",
        5 => "mai",
        6 => "juin",
        7 => "juillet",
        8 => "août",
        9 => "septembre",
        10 => "octobre",
        11 => "novembre",
        12 => "décembre");
    $data = array("week" => "0", "day" => "0", "month" => "0", "year" => "0", "hour" => "0", "minute" => "0", "second" => "0");
    $arr = explode(" ", $argv[1]);

    if ((count($arr) != 5) ||
		(preg_match("/^[1-9]$|^0[1-9]$|^[1-2][0-9]$|^3[0-1]$/", $arr[1], $data["day"]) === 0) ||
		(preg_match("/^[0-9]{4}$/", $arr[3], $data["year"]) === 0) ||
		(preg_match("/^([0-1][0-9]|2[0-3]):([0-5][0-9]):([0-5][0-9])$/", $arr[4], $arr[4]) === 0))
	    {
			echo "Wrong Format\n";
			exit();
	    }
    sscanf($arr[4][0], "%d:%d:%d", $data["hour"], $data["minute"], $data["second"]);
    $data["week"] = array_search(lcfirst($arr[0]), $day_of_week);
	$data["month"] = array_search(lcfirst($arr[2]), $month);

    if ($data["month"] === false || $data["week"] == false)
    {
        echo "Wrong Format\n";
        exit();
    }
    unset($arr);
    
    date_default_timezone_set('Europe/Paris');
    $time = mktime($data["hour"], $data["minute"], $data["second"], $data["month"], $data["day"][0], $data["year"][0]);

    if (date( "N", $time) == $data["week"])
		echo $time."\n";
	else
		echo "Wrong Format\n";

    /* 
    ** ----before I used preg_match XD

    function countDigits($MyNum)
    {
        $MyNum = (int)$MyNum;
        $count = 0;
         
        while($MyNum != 0)
        {
            $MyNum = (int)($MyNum / 10);
            $count++;
        }
        return $count;
    }    
    function check_time($value)
    {
        if (!is_numeric($value) || strlen($value) != 2 || countDigits($value) != 2)
            return (0);
        return (1);
    }     
    if (count($arr) != 5)
    {
        echo "Wrong Format\n";
        exit();
    }
    if (!is_numeric($arr[1]) || $arr[1] < 1 || $arr[1] > 31)
    {
        echo "Wrong Format\n";
        exit();
    }
    $data["day"] == $arr[1];
    if (!is_numeric($arr[3]) || strlen($arr[3]) != 4 || countDigits($arr[3]) != 4)
    {
        echo "Wrong Format\n";
        exit();
    }
    $data["year"] == $arr[3];
    sscanf($arr[4], "%d:%d:%d%s", $data["hour"], $data["minute"], $data["second"], $str);
    if (!check_time($data["hour"]) || !check_time($data["minute"]) || !check_time($data["second"]) || $str)
    {
        echo "Wrong Format!!!!\n";
        exit();
    }
    */

?>