<?php
    
    function    valid_post()
    {
        if (($_POST['submit'] == "OK") && ($_POST['login'] !== "") && ($_POST['passwd'] !== ""))
            return true;
        return false;
    }

    if (valid_post())
    {
        if (!file_exists("../private/passwd"))
            mkdir("../private");
        else
        {
            $users = unserialize(file_get_contents("../private/passwd"));
            foreach ($users as $user)
            {
                if ($user["login"] == $_POST["login"])
                {
                    echo "ERROR\n";
                    return ;
                }
            }
        }
        $new_usr["login"] = $_POST["login"];
	    $new_usr["passwd"] = hash('whirlpool', $_POST["passwd"]);
        $users[] = $new_usr;
        file_put_contents("../private/passwd", serialize($users));
        echo ("OK\n");
        header('Location: index.html');
    }
    else
        echo ("ERROR\n");
        
?>
