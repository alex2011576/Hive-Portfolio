<?php
    
    function    valid_post()
    {
        if (($_POST['submit'] == "OK") && ($_POST['login'] !== "") 
            && ($_POST['newpw'] !== "") && ($_POST['oldpw'] !== ""))
            return true;
        return false;
    }

    if (valid_post())
    {
        $users = unserialize(file_get_contents("../private/passwd"));
        $match = 0;
        foreach ($users as $key => $user)
        {
            if ($user['login'] == $_POST['login'])
            {
                $old_psw_hash = hash('whirlpool', $_POST['oldpw']);
                if ($user['passwd'] == $old_psw_hash)
                {
                    $match = 1;
                    $users[$key]['passwd'] = hash('whirlpool', $_POST['newpw']);
                }
            }
        }
        if ($match == 1)
        {
            file_put_contents("../private/passwd", serialize($users));
            echo ("OK\n");
            header('Location: index.html');
            return ;
        }
        echo "ERROR\n";
        return ;
    }
    else
        echo ("ERROR\n");
        
?>
