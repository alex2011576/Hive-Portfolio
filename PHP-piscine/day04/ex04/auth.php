<?php

    function auth($login, $passwd)
    {
        if ($login !== "" && $passwd !== "")
        {
            if (file_exists("../private/passwd"))
            {
                $users = unserialize(file_get_contents("../private/passwd"));
                foreach ($users as $user)
                {
                    if ($user["login"] === $login)
                    {
                        $passwd_hash = hash('whirlpool', $passwd);
                        if ($user['passwd'] === $passwd_hash)
                            return TRUE;
                    }
                }
            }
        }
        return FALSE;
    }

?>
