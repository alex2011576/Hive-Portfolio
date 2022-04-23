#!/usr/bin/php
<?php
   if ($argc != 2)
   {
        echo "Incorrect Parameters\n";
        exit ();
   }
   $check = sscanf($argv[1], "%d %c %d %s");
   if (count($check) != 4 || !is_numeric($check[0]) || !is_numeric($check[2]) || $check[3])
        {
            echo "Syntax Error\n";
            exit ();
        }
    $nb1 = $check[0];
    $op = $check[1];
    $nb2 = $check[2]; 
    switch($op)
    {
        case "*":
            print(($nb1 * $nb2)."\n");
            break;
        case "/":
            if ($nb2 == 0)
            {
                echo "Division by 0 is forbidden\n";
                break;
            }
            print(($nb1 / $nb2)."\n");
            break;
        case "+":
            print(($nb1 + $nb2)."\n");
            break;
        case "-":
            print(($nb1 - $nb2)."\n");
            break;
        case "%":
            if ($nb2 == 0)
            {
                echo "Division by 0 is forbidden\n";
                break;
            }
            print(($nb1 % $nb2)."\n");
            break;
        default:
            echo "Syntax Error\n";
            break;
    }
?>