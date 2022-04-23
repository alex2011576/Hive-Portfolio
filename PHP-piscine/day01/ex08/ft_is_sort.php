<?php

function    ft_is_sort($tab)
{
    if ($tab)
    {
        $arr = $tab;
        sort($arr);
        if ($arr == $tab)
            return (true);
    }
    else 
        return (true);
    return (false);

}

?>