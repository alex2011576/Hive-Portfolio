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
        $exist = 0;
        foreach ($users as $key => $user)
        {
            if ($user['login'] == $_POST['login'])
            {
                $exist == 1;
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
            echo "sucess!\n";
            header('Location: user_index.html');
            return ;
        }
        if ($exist == 0)
        {
            echo "SUCH USER IS NOT REGISTERED\n";
            echo "TRY AGAIN\n";
            header('Location: modif.html');
            return ;
        }
        echo "WRONG OLD PASSWORD\n";
        echo "TRY AGAIN\n";
        header('Location: modif.html');
    }
    else
        echo ("NOT A VALID FORMAT\n");
        
?>
